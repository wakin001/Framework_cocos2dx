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

/**
 * FWAbstractView Delegate
 */
class FWAbstractViewDelegate
{
public:
    virtual bool                    touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *event);
    virtual void                    touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *event);
    virtual void                    touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *event);
    virtual void                    touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *event);
    virtual void                    onNodeTouched(cocos2d::CCNode *node);

};

class FWAbstractView : public cocos2d::CCLayer
{
public:
    FWAbstractView();
    
    ~FWAbstractView();
    
	virtual bool                    init();
    
    virtual void                    onExit();
    
    virtual void                    onEnterTransitionDidFinish();
    
	CREATE_FUNC(FWAbstractView);
    
    /**
     * Create funciton.
     */
    static FWAbstractView           *create(FWAbstractModel *model, FWAbstractViewDelegate *delegate);
    void                            init(FWAbstractModel *model, FWAbstractViewDelegate *delegate);
    
    /**
     * Called if got the notification message.
     */
    void                            onNotificationCalled(cocos2d::CCNotificationObserver *notification);
    
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
    void                            onUpdateWithInterval(float interval);
    
    virtual bool                    ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void                    ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
private:
    FWAbstractModel                 *m_pModel;
    
    // deleage object.
    FWAbstractViewDelegate          *m_pDelegate;
};

#endif // __FWAbstractView__LAYER_H__