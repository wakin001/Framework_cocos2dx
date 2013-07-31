//
//  FruitsView.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FruitsView.h"
#include "Watermelon.h"

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
    m_cache = CCArray::createWithCapacity(53);
    
    // Just create one sprite for now. This whole method will be replaced later.
    PolygonSprite *sprite = Watermelon::spriteWithWorld(world);
    addChild(sprite, 1);
    sprite->activateCollisions();
    m_cache->addObject(sprite);
}
