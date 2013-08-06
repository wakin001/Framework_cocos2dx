//
//  FWBox2dHelper.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/08/06.
//
//

#ifndef __Framework_cocos2dx__FWBox2dHelper__
#define __Framework_cocos2dx__FWBox2dHelper__

#define kPointsToMeterRatio 32.0f

#include "cocos2d.h"
#include "Box2D.h"

class FWBox2dHelper
{
public:
    static b2Vec2                   toMeters(cocos2d::CCPoint point);
    static b2Vec2                   toMetersFromPixels(cocos2d::CCPoint point);
    static cocos2d::CCPoint         toPoints(b2Vec2 vec);
    static cocos2d::CCPoint         toPixels(b2Vec2 vec);
    
    static float                    pointsToMeterRatio();
    static float                    pixelsToMeterRatio();
};

#endif /* defined(__Framework_cocos2dx__FWBox2dHelper__) */
