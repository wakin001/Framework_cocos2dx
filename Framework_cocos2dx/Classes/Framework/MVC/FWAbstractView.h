//
//  FWAbstractView.h
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAbstractView__LAYER_H__
#define __FWAbstractView__LAYER_H__

#include "cocos2d.h"
#include "FWAbstractModel.h"
#include "FWMacro.h"

/**
 * FWAbstractView Delegate
 */
class FWAbstractViewDelegate
{
public:
    virtual bool                    touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent) = 0;
    virtual void                    touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent) = 0;
    virtual void                    touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent) = 0;
    virtual void                    touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent) = 0;
    virtual void                    onNodeTouched(cocos2d::CCNode *pNode) = 0;

};

class FWAbstractView : public cocos2d::CCLayer
{
public:
    FWAbstractView();
    
    virtual ~FWAbstractView();
    
    /**
     * Create funciton.
     */
    CREATE_FUNC(FWAbstractView);
    CREATE_FUNC_TWO_PARAMETERS(FWAbstractView, FWAbstractModel*, model, FWAbstractViewDelegate*, delegate);

    virtual bool                    init(FWAbstractModel *model = NULL, FWAbstractViewDelegate *delegate = NULL);
    
    
    /**
     * Macro
     */
    CC_SYNTHESIZE(FWAbstractModel *,           model,      Model);
    CC_SYNTHESIZE(FWAbstractViewDelegate *,    delegate,   Delegate);
    
    /**
     * Inherit methods
     */
    virtual void                    onExit();
    
    virtual void                    onEnterTransitionDidFinish();
    
    /**
     * Called if got the notification message.
     */
    virtual void                    onNotificationCalled(cocos2d::CCNotificationObserver *notification);
    
    /**
     * Get the touch point.
     */
    cocos2d::CCPoint                locationFromTouch(cocos2d::CCTouch *touch);
    
    /**
     * Get the touch point.
     */
    cocos2d::CCPoint                locationFromTouches(cocos2d::CCSet *touches);
    
    /**
     * Call it in every interval time.
     * Should call [scene scheduleWithInterval:interval] firstly.
     */
    virtual void                    onUpdateWithInterval(float fInterval);
    
    virtual void                    ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
private:
    FWAbstractModel *               m_pModel;
    
    // deleage object.
    FWAbstractViewDelegate *        m_pDelegate;
};

#endif // __FWAbstractView__LAYER_H__