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
    
    setTouchEnabled(true);
    
    return true;
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
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_STRAWBERRY, "strawberry");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        m_cache->addObject(sprite);
    }
    for (int i = 0; i < 10; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_PINEAPPLE, "pineapple");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
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
        m_cache->addObject(sprite);
    }
    
    for (int i = 0; i < 3; i++)
    {
        PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, TYPE_FRUITS_BOMN, "bomb");
        sprite->setPosition(ccp(-64*(i+1),-64));
        addChild(sprite, 1);
        m_cache->addObject(sprite);
    }
}
