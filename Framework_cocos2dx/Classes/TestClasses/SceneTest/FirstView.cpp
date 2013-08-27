//
//  FirstView.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FirstView.h"
#include "FWEffectSprite.h"
#include "FWAnimation.h"
#include "FWActionEffect.h"

using namespace cocos2d;

FirstView::FirstView()
{
}

FirstView::~FirstView()
{
}

bool FirstView::init(FWAbstractModel *model, FWAbstractViewDelegate *delegate)
{
    if (!FWAbstractView::init(model, delegate))
    {
        return false;
    }
    // init sprite.
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    //background.
    CCSprite *bgSprite = CCSprite::create("bg_town_0.png");
//    CCSprite *bgSprite = CCSprite::create("underwater-fish-in-hawaii_1024x768.png");
    bgSprite->setAnchorPoint(CCPointZero);
    addChild(bgSprite);
//    bgSprite->setPosition(ccp(screenSize.width / 2, screenSize.height / 2));

    
    // back button.
    CCSize visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCMenuItemImage *pmiiBack = CCMenuItemImage::create("btn.png",
                                                        "btn.png",
                                                        "btn.png",
                                                        this,
                                                        menu_selector(FWAbstractView::onNodeTouched));
    pmiiBack->setTag(TAG_FRUITSGAME);
    CCPoint point = ccp(screenSize.width / 2 - pmiiBack->getContentSize().width / 2 - visibleOrigin.width,
                        -screenSize.height / 2 + pmiiBack->getContentSize().height / 2 - visibleOrigin.height);
    pmiiBack->setPosition(point);
    CCMenu *pmMenu = CCMenu::create(pmiiBack, NULL);
    addChild(pmMenu);
    
    CCLabelTTF *label = CCLabelTTF::create("Fruit", "Arial", 12);
    label->setPosition(ccp(pmiiBack->getContentSize().width * 0.5f,
                           pmiiBack->getContentSize().height * 0.5f));
    pmiiBack->addChild(label);
    
    setTouchEnabled(true);    
    return true;
}


void FirstView::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    FWAbstractView::ccTouchesBegan(pTouches, pEvent);

    // Add effect.
    FWEffectSprite *penBurst = FWEffectSprite::create("effect_burst", 7, 0.05f, true);
    penBurst->setPosition(ccp(100.0f, 100.0f));
    addChild(penBurst, 10);
    
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    FWActionEffect *paeEffect = FWActionEffect::create("effect_burst",
                                                       7,
                                                       ccp(0.2f, 0.5f),
                                                       CCRectMake(0, 0, winsize.width, winsize.height),
                                                       ccBLUE,
                                                       300.0f,
                                                       0.02f,
                                                       0.02f);
    addChild(paeEffect);
    
}