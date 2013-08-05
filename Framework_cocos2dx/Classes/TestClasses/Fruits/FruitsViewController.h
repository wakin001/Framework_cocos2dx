//
//  FruitsViewController.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FruitsViewController__OBJECT_H__
#define __FruitsViewController__OBJECT_H__

#define calculate_determinant_2x2(x1, y1, x2, y2)       (x1 * y2 - y1 * x2)
#define calculate_determinant_2x3(x1, y1, x2, y2, x3, y3)       (x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)

#define frandom ((float)arc4random()/UINT64_C(0x100000000))
#define frandom_range(low,high) (((high-low)*frandom)+low)
#define random_range(low,high) ((arc4random()%(high-low+1))+low)

#define midpoint(a,b) ((float)(a+b)/2)

typedef enum
{
    TOSS_TYPE_CONSECUTIVE = 0,
    TOSS_TYPE_SIMULTANEOUS,
} TOSS_TYPE;

#include "cocos2d.h"
#include "FruitsModel.h"
#include "FruitsView.h"
#include "FWPhysicsViewController.h"
#include "FWRayCastCallback.h"
#include "PolygonSprite.h"

class FruitsViewController : public FWPhysicsViewController
{
public:
    FruitsViewController();
    
    ~FruitsViewController();
    
    CREATE_FUNC(FruitsViewController);
    CREATE_FUNC_ONE_PARAMETER(FruitsViewController, FruitsModel*, model);
    
    virtual bool                init(FruitsModel * model = NULL);
    
    virtual void                draw();
    virtual void                update(float delta);
    
    virtual bool                touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    
    b2Vec2 *                    arrangeVertices(b2Vec2 *vertices, int count);
    void                        splitPolygonSprite(PolygonSprite *sprite);
    bool                        areVerticesAcceptable(b2Vec2 *vertices, int count);
    b2Body *                    createBodyWithPosition(b2Vec2 position, float rotation, b2Vec2 *vertices, int32 count, float density, float friction, float restitution);
    void                        clearSlices();
    
    void                        checkAndSliceObjects();
    
    void                        tossSprite(PolygonSprite *sprite);
    
    void                        spriteLoop();
    
    void                        clearSprites();
    
protected:
    FruitsView                  *m_fruitsView;
    cocos2d::CCPoint            m_startPoint;
    cocos2d::CCPoint            m_endPoint;
    FWRayCastCallback           *m_raycastCallback;

    // This is the time when a fruit, or a group of fruits will be tossed next.
    double                      m_nextTossTime;
    // This is the random number of seconds in between tosses. 
    double                      m_tossInterval;
    // This is the random number of fruits that still need to be tossed for the current toss type.
    int                         m_queuedForToss;
    // The toss type of the current toss interval. It is a random choice between simultaneous and consecutive.
    TOSS_TYPE                   m_currentTossType;
};

#endif // __FruitsViewController__OBJECT_H__