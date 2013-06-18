//
//  GameViewController.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __GameViewController__OBJECT_H__
#define __GameViewController__OBJECT_H__

#include "FWAbstractViewController.h"
#include "GameView.h"

class GameViewController : public FWAbstractViewController
{
public:
    GameViewController();
    
    ~GameViewController();
    
    CREATE_FUNC(GameViewController);
    
    virtual bool                    init();
    
    virtual bool                    touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                    touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                    touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                    touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                    onNodeTouched(cocos2d::CCNode *pNode);
    
    
    void                            onScrollFinished();
    
    // inherit methods.
    virtual void                    update(float delta);
    
protected:
    GameView *                      m_gameView;
};

#endif // __GameViewController__OBJECT_H__