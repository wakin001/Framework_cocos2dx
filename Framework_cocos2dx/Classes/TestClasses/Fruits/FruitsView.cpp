//
//  FruitsView.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FruitsView.h"
#include "PolygonSprite.h"

using namespace cocos2d;

FruitsView::FruitsView()
: m_cache(NULL)
{
}

FruitsView::~FruitsView()
{
    CC_SAFE_DELETE(m_cache);
}

bool FruitsView::init(FruitsModel *model, FWAbstractViewDelegate *delegate)
{
    if (!FWAbstractView::init(model, delegate))
    {
        return false;
    }
    
    initBackground();
    
    m_bladeSparkle = CCParticleSystemQuad::create("blade_sparkle.plist");
    m_bladeSparkle->stopSystem();
    addChild(m_bladeSparkle, 3);
    
    setTouchEnabled(true);
    
    return true;
}

void FruitsView::initBackground()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite *background = CCSprite::create("bg.png");
    background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(background, 0);
    
    CCParticleSystemQuad *sunPollen = CCParticleSystemQuad::create("sun_pollen.plist");
    addChild(sunPollen);
}

void FruitsView::initSprites(b2World *world)
{
    // Create fruits. (out of screen at first.)
    m_cache = CCArray::createWithCapacity(53);
    m_cache->retain();
    
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_WATERMELON, "watermelon");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        addChild(sprite->getSplurt(), 3);
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_STRAWBERRY, "strawberry");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        addChild(sprite->getSplurt(), 3);
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_PINEAPPLE, "pineapple");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        addChild(sprite->getSplurt(), 3);
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_GRAPES, "grapes");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_BANANA, "banana");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        addChild(sprite->getSplurt(), 3);
        m_cache->addObject(sprite);
    }
    
    for (int i = 0; i < 3; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_BOMN, "bomb");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        addChild(sprite->getSplurt(), 3);
        m_cache->addObject(sprite);
    }
}
