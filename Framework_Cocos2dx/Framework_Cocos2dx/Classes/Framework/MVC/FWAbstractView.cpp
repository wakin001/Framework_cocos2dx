//
//  FWAbstractView.cpp
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAbstractView.h"

using namespace cocos2d;

FWAbstractView::FWAbstractView()
{
}

FWAbstractView::~FWAbstractView()
{
}

bool FWAbstractView::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
    
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

// Create funciton.
static FWAbstractView *create(FWAbstractModel *model, FWAbstractViewDelegate *delegate)
{
    FWAbstractView *view = FWAbstractView::create();
    view->init(model, delegate);
    return view;
}

void FWAbstractView::init(FWAbstractModel *model, FWAbstractViewDelegate *delegate)
{
    m_pModel = model;
    m_pDelegate = delegate;
}

/**
 * Called if got the notification message.
 */
void FWAbstractView::onNotificationCalled(CCNotificationObserver *notification)
{
    
}

/**
 * Get the touch point.
 */
cocos2d::CCPoint FWAbstractView::locationFromTouch(CCTouch *touch)
{
    cocos2d::CCPoint touchLocation = touch->getLocation();
    return CCDirector::sharedDirector()->convertToGL(touchLocation);
}

/**
 * Get the touch point.
 */
cocos2d::CCPoint FWAbstractView::locationFromTouches(CCSet *touches)
{
    CCTouch *touch = (CCTouch *)touches->anyObject();
    return locationFromTouch(touch);
}

/**
 * Call it in every interval time.
 * Should call [scene scheduleWithInterval:interval] firstly.
 */
void FWAbstractView::onUpdateWithInterval(float interval)
{
    
}


bool FWAbstractView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint point = locationFromTouch(pTouch);
    return m_pDelegate->touchesBeganWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouch(pTouch);
    m_pDelegate->touchesMoveWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouch(pTouch);
    m_pDelegate->touchesEndWithPoint(point, pEvent);
}

void FWAbstractView::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint point = locationFromTouch(pTouch);
    m_pDelegate->touchesCancelledWithPoint(point, pEvent);
}
