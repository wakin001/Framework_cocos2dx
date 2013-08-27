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
    
    // Add back button.
    CCSize visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCMenuItemImage *pmiiBack = CCMenuItemImage::create("btn.png",
                                                        "btn.png",
                                                        "btn.png",
                                                        this,
                                                        menu_selector(FWAbstractView::onNodeTouched));
    pmiiBack->setTag(TAG_BUTTON_BACK);
    CCPoint point = ccp(winSize.width / 2 - pmiiBack->getContentSize().width / 2 - visibleOrigin.width,
                        -winSize.height / 2 + pmiiBack->getContentSize().height / 2 - visibleOrigin.height);
    pmiiBack->setPosition(point);
    CCMenu *pmMenu = CCMenu::create(pmiiBack, NULL);
    addChild(pmMenu);
    
    CCLabelTTF *label = CCLabelTTF::create("BACK", "Arial", 12);
    label->setPosition(ccp(pmiiBack->getContentSize().width * 0.5f,
                           pmiiBack->getContentSize().height * 0.5f));
    pmiiBack->addChild(label);
}

void FruitsView::initSprites(b2World *world)
{
    // Create fruits. (out of screen at first.)
    m_cache = CCArray::createWithCapacity(53);
    m_cache->retain();
    
    TYPE_FRUITS types[] = {
        TYPE_FRUITS_WATERMELON,
        TYPE_FRUITS_STRAWBERRY,
        TYPE_FRUITS_PINEAPPLE,
        TYPE_FRUITS_GRAPES,
        TYPE_FRUITS_BANANA
    };
    const char *names[] = {
        "watermelon",
        "strawberry",
        "pineapple",
        "grapes",
        "banana",
    };
    
    for (int j = 0; j < 5; ++j)
    {
        for (int i = 0; i < 10; i++)
        {
            PolygonSprite *sprite = PolygonSprite::spriteWithWorld(world, types[j], names[j]);
            sprite->setPosition(ccp(-64*(i+1),-64));
            addChild(sprite, 1);
            addChild(sprite->getSplurt(), 3);
            m_cache->addObject(sprite);
        }
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