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
    addChild(bgSprite);
    bgSprite->setPosition(ccp(screenSize.width / 2, screenSize.height / 2));

    
    // back button.
    CCMenuItemImage *pmiiBack = CCMenuItemImage::create("btn.png", "btn.png", "btn.png", this, menu_selector(FirstView::onBackButtonClicked));
    pmiiBack->setPosition(ccp(screenSize.width / 2 - pmiiBack->getContentSize().width / 2,
                              -screenSize.height / 2 + pmiiBack->getContentSize().height / 2));
    CCMenu *pmMenu = CCMenu::create(pmiiBack, NULL);
    addChild(pmMenu);
    
    setTouchEnabled(true);
    
    return true;
}

void FirstView::onBackButtonClicked()
{
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

void FirstView::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    onBackButtonClicked();
}