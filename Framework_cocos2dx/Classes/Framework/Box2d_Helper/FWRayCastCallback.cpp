//
//  FWRayCastCallback.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWRayCastCallback.h"
#include "Machtimer.h"
#include "FWPolygonSprite.h"

#define collinear(x1, y1, x2, y2, x3, y3)   fabsf((y1 - y2) * (x1 - x3) - (y1 - y3) * (x1 - x2))

using namespace cocos2d;

FWRayCastCallback::FWRayCastCallback()
{
}

FWRayCastCallback::~FWRayCastCallback()
{
}

float32 FWRayCastCallback::ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float32 fraction)
{
    FWPolygonSprite *polygonSprite = (FWPolygonSprite *)fixture->GetBody()->GetUserData();
    if (!polygonSprite->getSliceEntered())
    {
        polygonSprite->setSliceEntered(true);
        
        // you need to get the point coordinates within the shape.
        polygonSprite->setEntryPoint(polygonSprite->getBody()->GetLocalPoint(point));
        
        double currentTime = Machtimer::currentTimeInSecond();
        CCLOG("current time: %f", currentTime);
        // + 1 : The avaiable time is 1 scecond, which means user should finish the split in 1 second.
        polygonSprite->setSliceEntryTime(currentTime + 1);
        CCLOG("Slice Entered at world coordinates:(%f,%f), polygon coordinates:(%f,%f)",
              point.x*PTM_RATIO,
              point.y*PTM_RATIO,
              polygonSprite->getEntryPoint().x * PTM_RATIO,
              polygonSprite->getEntryPoint().y*PTM_RATIO);
    }
    else if (!polygonSprite->getSliceExited())
    {
        polygonSprite->setExitPoint(polygonSprite->getBody()->GetLocalPoint(point));

        b2Vec2 entrySide = polygonSprite->getEntryPoint() - polygonSprite->getCentroid();
        b2Vec2 exitSide = polygonSprite->getExitPoint() - polygonSprite->getCentroid();
        if (entrySide.x * exitSide.x < 0 || entrySide.y * exitSide.y < 0)
        {
            polygonSprite->setSliceExited(true);
        }
        else
        {   //if the cut didn't cross the centroid, you check if the entry and exit point lie on the same line
            b2Fixture *fixture = polygonSprite->getBody()->GetFixtureList();
            b2PolygonShape *polygon = (b2PolygonShape*)fixture->GetShape();
            int count = polygon->GetVertexCount();
            
            bool onSameLine = false;
            for (int i = 0 ; i < count; i++)
            {
                b2Vec2 pointA = polygon->GetVertex(i);
                b2Vec2 pointB;
                
                if (i == count - 1)
                {
                    pointB = polygon->GetVertex(0);
                }
                else
                {
                    pointB = polygon->GetVertex(i+1);
                }//endif
                
                float collinear = collinear(pointA.x,pointA.y, polygonSprite->getEntryPoint().x, polygonSprite->getEntryPoint().y, pointB.x,pointB.y);
                
                if (collinear <= 0.00001)
                {
                    float collinear2 = collinear(pointA.x,pointA.y,polygonSprite->getExitPoint().x,polygonSprite->getExitPoint().y,pointB.x,pointB.y);
                    if (collinear2 <= 0.00001)
                    {
                        onSameLine = true;
                    }
                    break;
                }
            }
            
            if (onSameLine)
            {
                polygonSprite->setEntryPoint(polygonSprite->getExitPoint());
                double currentTime = Machtimer::currentTimeInSecond();
                CCLOG("current time: %f", currentTime);
                polygonSprite->setSliceEntryTime(currentTime + 1);
                polygonSprite->setSliceExited(false);
            }
            else
            {
                polygonSprite->setSliceExited(true);
            }
        }
        
        CCLOG("Slice Exited at world coordinates:(%f,%f), polygon coordinates:(%f,%f)",
              point.x*PTM_RATIO,
              point.y*PTM_RATIO, 
              polygonSprite->getExitPoint().x*PTM_RATIO,
              polygonSprite->getExitPoint().y*PTM_RATIO);
    }
    // Lastly, you return 1 to tell Box2D that this ray cast should continue to check
    // for fixtures even after the first fixture. Returning other numbers will make the
    // ray cast behave differently, but this is beyond the scope of this tutorial.
    return 1;
}
