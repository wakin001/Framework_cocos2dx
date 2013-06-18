//
//  FWAbstractView.cpp
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAbstractView.h"

using namespace cocos2d;

FWAbstractView::FWAbstractView() :
    m_pModel(NULL)
{
}

FWAbstractView::~FWAbstractView()
{
}

// Create funciton.

bool FWAbstractView::init(FWAbstractModel *model, FWAbstractViewDelegate *delegate)
{
    m_pModel = model;
    m_pDelegate = delegate;
    return true;
}


void FWAbstractView::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
}

void FWAbstractView::onExit()
{
    CCLayer::onExit();
}

/**
 * Called if got the notification message.
 */
void FWAbstractView::onNotificationCalled(CCNotificationObserver *pNotification)
{
    
}

/**
 * Get the touch point.
 */
cocos2d::CCPoint FWAbstractView::locationFromTouch(CCTouch *pTouch)
{
    cocos2d::CCPoint touchLocation = pTouch->getLocation();
    return CCDirector::sharedDirector()->convertToGL(touchLocation);
}

/**
 * Get the touch point.
 */
cocos2d::CCPoint FWAbstractView::locationFromTouches(CCSet *pTouches)
{
    CCTouch *pTouch = (CCTouch *)pTouches->anyObject();
    return locationFromTouch(pTouch);
}

/**
 * Call it in every interval time.
 * Should call [scene scheduleWithInterval:interval] firstly.
 */
void FWAbstractView::onUpdateWithInterval(float fInterval)
{
    
}


void FWAbstractView::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCPoint point = locationFromTouches(pTouches);
    m_pDelegate->touchesBeganWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouches(pTouches);
    m_pDelegate->touchesMoveWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouches(pTouches);
    m_pDelegate->touchesEndWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouches(pTouches);
    m_pDelegate->touchesCancelledWithPoint(point, pEvent);
}
