//
//  FWAnimation.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/06.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAnimation.h"

using namespace cocos2d;

FWAnimation::FWAnimation()
{
}

FWAnimation::~FWAnimation()
{
}


CCAnimation * FWAnimation::create(const char * frameName, int frameCount, float delay)
{
    CCArray *parFrames = CCArray::createWithCapacity(frameCount);
    CCSpriteFrameCache *psfcCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    
    for (int i = 0; i < frameCount; ++i)
    {
        CCString *psFile = CCString::createWithFormat("%s_%d.png", frameName, i);
        CCSpriteFrame *psfFrame = psfcCache->spriteFrameByName(psFile->getCString());
        parFrames->addObject(psfFrame);
    }
    return CCAnimation::createWithSpriteFrames(parFrames, delay);
}