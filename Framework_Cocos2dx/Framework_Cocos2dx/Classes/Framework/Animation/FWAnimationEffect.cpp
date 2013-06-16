//
//  FWAnimationEffect.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAnimationEffect.h"
#include "FWEffectSprite.h"
#include "FWCommons.h"

using namespace cocos2d;

FWAnimationEffect::FWAnimationEffect()
{
}

FWAnimationEffect::~FWAnimationEffect()
{
}


FWAnimationEffect * FWAnimationEffect::create(const char *         fileName,
                                              int                  frameCount,
                                              cocos2d::CCPoint     scale,
                                              cocos2d::CCRect      rect,
                                              cocos2d::ccColor3B   color,
                                              float                lastingTime,
                                              float                interval,
                                              float                delay,
                                              FWE_MOVEDIRECT       moveDirection)
{
    FWAnimationEffect *paeEffect = new FWAnimationEffect;
    if (paeEffect && paeEffect->init(fileName, frameCount, scale, rect, color, lastingTime, interval, delay, moveDirection))
    {
        paeEffect->autorelease();
        return paeEffect;
    }
    CC_SAFE_DELETE(paeEffect);
    return NULL;
}

bool FWAnimationEffect::init(const char *         fileName,
                             int                  frameCount,
                             cocos2d::CCPoint     scale,
                             cocos2d::CCRect      rect,
                             cocos2d::ccColor3B   color,
                             float                lastingTime,
                             float                interval,
                             float                delay,
                             FWE_MOVEDIRECT       moveDirection)
{
    if (!FWAnimationBase::init())
    {
        return false;
    }
    
    m_pccFileName = fileName;
    m_iFrameCount = frameCount;
    m_poScale = scale;
    m_rRect = rect;
    m_cColor = color;
    m_fLastingTime = lastingTime;
    m_fInterval = interval;
    m_fDelay = delay;
    m_fTotalTime = 0.0f;
    m_eMoveDirection = moveDirection;
    
    schedule(schedule_selector(FWAnimationEffect::onCreateEffects), interval);
    
    
    return true;
}

void FWAnimationEffect::onCreateEffects(float interval)
{
    if (m_fTotalTime > m_fLastingTime)
    {
        unscheduleAllSelectors();
        return;
    }
    
    // Create an effect animation.
    FWEffectSprite *pesEffect = FWEffectSprite::create(m_pccFileName, m_iFrameCount, m_fDelay, true);
    
    float x = m_rRect.origin.x;
    float w = m_rRect.size.width;
    float y = m_rRect.origin.y;
    float h = m_rRect.size.height;
    float randomX = FWCommons::randomFloat(x, x + w);
    float randomY = FWCommons::randomInt(y, y + h);
    pesEffect->setPosition(ccp(randomX, randomY));
    
    // scale.
    pesEffect->setScale(FWCommons::randomFloat(m_poScale.x, m_poScale.y));
    int r = FWCommons::randomInt(0, 255);
    int g = FWCommons::randomInt(0, 255);
    int b = FWCommons::randomInt(0, 255);
    pesEffect->setColor((ccColor3B){r, g, b});
    
    addChild(pesEffect);
    
    switch (m_eMoveDirection)
    {
        case FWE_MOVEDIRECT_UP:
        {
            CCMoveBy * moveUp = CCMoveBy::create(2.0f, ccp(0, m_rRect.size.height));
            pesEffect->runAction(moveUp);
            break;
        }
        default:
            break;
    }
    
    m_fTotalTime += interval;
}
