//
//  FWEffectNode.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/06.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWEffectSprite.h"
#include "FWAnimation.h"

using namespace cocos2d;

FWEffectSprite::FWEffectSprite()
{
}

FWEffectSprite::~FWEffectSprite()
{
}

bool FWEffectSprite::init()
{
	if ( !CCSprite::init() )
	{
		return false;
	}
    
	return true;
}

FWEffectSprite * FWEffectSprite::create(const char *effectName,
                                    int frameCount,
                                    float delay,
                                    bool deleteAfterFinishing)
{
    FWEffectSprite *pnEffect = new FWEffectSprite();
    if (pnEffect && pnEffect->init(effectName, frameCount, delay, deleteAfterFinishing))
    {
        pnEffect->autorelease();
        return pnEffect;
    }
    CC_SAFE_DELETE(pnEffect);
    return NULL;

}

bool FWEffectSprite::init(const char *effectName,
                       int frameCount,
                       float delay,
                       bool deleteAfterFinishing)
{
    CCString *psPlistFile = CCString::createWithFormat("%s.plist", effectName);

    CCSpriteFrameCache *psfcFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    psfcFrameCache->addSpriteFramesWithFile(psPlistFile->getCString());
    
    CCString *psFrameName = CCString::createWithFormat("%s_0.png", effectName);
    const char * pccFrameName = psFrameName->getCString();
//    m_psfSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pccFrameName);
    
    if (!CCSprite::initWithSpriteFrameName(pccFrameName))
    {
        return false;
    }
    
    CCAnimation *paAnimation = FWAnimation::create(effectName, frameCount, delay);
    CCAnimate *paAnimate = CCAnimate::create(paAnimation);
    
    if (deleteAfterFinishing)
    {
        CCCallFunc *pcfCallBack = CCCallFunc::create(this, callfunc_selector(FWEffectSprite::removeSelf));
        CCSequence *pseSeq = CCSequence::createWithTwoActions(paAnimate, pcfCallBack);
        runAction(pseSeq);
    }
    else
    {
        runAction(paAnimate);
    }
    return true;
}

void FWEffectSprite::removeSelf()
{
    removeFromParentAndCleanup(true);
}


