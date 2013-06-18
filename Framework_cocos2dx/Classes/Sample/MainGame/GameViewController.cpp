//
//  GameViewController.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "GameViewController.h"
#include "GameModel.h"
#include "GameView.h"

using namespace cocos2d;

GameViewController::GameViewController()
{
}

GameViewController::~GameViewController()
{
    CC_SAFE_DELETE(m_model);
    CC_SAFE_DELETE(m_view);
}


bool GameViewController::init()
{
    m_model = GameModel::create();
    m_model->retain();
    
    m_view = GameView::create(m_model, this);
    m_view->retain();
    addChild(m_view);
    
    m_gameView = (GameView *)m_view;

    // schedule update.
    scheduleUpdate();
    
    return true;
}

#pragma mark - delegate methods

bool GameViewController::touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
//    float duration = 1.6f;
//    m_gameView->scrollBy(duration, callfunc_selector(GameViewController::onScrollFinished));
    m_gameView->setGameState(KTE_GAMESTATE_SCROLL);
    return false;
}
void GameViewController::touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void GameViewController::touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void GameViewController::touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void GameViewController::onNodeTouched(cocos2d::CCNode *pNode)
{
    
}

void GameViewController::onScrollFinished()
{
    
}

void GameViewController::update(float delta)
{
    m_gameView->update(delta);
}
