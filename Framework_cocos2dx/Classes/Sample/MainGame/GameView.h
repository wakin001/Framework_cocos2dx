//
//  GameView.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __GameView__OBJECT_H__
#define __GameView__OBJECT_H__

typedef enum
{
    KTE_GAMESTATE_START,
    KTE_GAMESTATE_IDLE,
    KTE_GAMESTATE_SCROLL,
    KTE_GAMESTATE_RUNNING,
    KTE_GAMESTATE_PAUSE,
    KTE_GAMESTATE_FINISHED,
} KTE_GAMESTATE;

#include "FWAbstractView.h"

class GameView : public FWAbstractView
{
public:
    GameView();
    
    ~GameView();
    
    // Should demostrate this fucntion for each sub-class.
    CREATE_FUNC_TWO_PARAMETERS(GameView, FWAbstractModel*, model, FWAbstractViewDelegate*, delegate);
    virtual bool                    init(FWAbstractModel *model, FWAbstractViewDelegate *delegate);
    
    virtual bool                    ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void                            ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    // inherit methods.
    virtual void                    update(float delta);
    
    void                            scrollBackground(float delta);
    
    /**
     * Set/Get functions.
     */
    CC_SYNTHESIZE(KTE_GAMESTATE, m_gameState, GameState);
    
protected:
    cocos2d::CCArray *              m_backgroundBatchNodes;
    
    cocos2d::SEL_CallFunc           m_callBack;
    float                           m_walkSpeed;
    float                           m_walkDuration;
    
//    KTE_GAMESTATE                   m_gameState;
    float                           m_totalTime;
};

#endif // __GameView__OBJECT_H__