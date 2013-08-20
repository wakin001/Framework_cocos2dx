//
//  FWBox2dHelper.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/08/06.
//
//

#include "FWBox2dHelper.h"

using namespace cocos2d;

b2Vec2 FWBox2dHelper::toMeters(cocos2d::CCPoint point)
{
    return b2Vec2(point.x / kPointsToMeterRatio, point.y / kPointsToMeterRatio);
}

b2Vec2 FWBox2dHelper::toMetersFromPixels(cocos2d::CCPoint point)
{
    return b2Vec2(point.x / pixelsToMeterRatio(), point.y / pixelsToMeterRatio());
}

cocos2d::CCPoint FWBox2dHelper::toPoints(b2Vec2 vec)
{
    return ccpMult(ccp(vec.x, vec.y), kPointsToMeterRatio);
}

cocos2d::CCPoint FWBox2dHelper::toPixels(b2Vec2 vec)
{
    return ccpMult(ccp(vec.x, vec.y), pixelsToMeterRatio());
}

float FWBox2dHelper::pointsToMeterRatio()
{
    return (kPointsToMeterRatio);
}

float FWBox2dHelper::pixelsToMeterRatio()
{
    float ratio = (CC_CONTENT_SCALE_FACTOR() * kPointsToMeterRatio);
//    CCLOG("ratio: %f", ratio);
    return ratio;
}
