//
//  GameView.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "GameView.h"
#include "Defines.h"
#include "GameBackgroundBatchNode.h"

using namespace cocos2d;

GameView::GameView()
{
}

GameView::~GameView()
{
    CC_SAFE_DELETE(m_backgroundBatchNodes);
}

bool GameView::init(FWAbstractModel *model, FWAbstractViewDelegate *delegate)
{
    if (!FWAbstractView::init(model, delegate))
    {
        return false;
    }
    
    setTouchEnabled(true);
    m_gameState = KTE_GAMESTATE_START;
    m_walkDuration = 1.6f;
    m_walkSpeed = 160.0f;
    m_totalTime = 0.0f;
    
    const char *layerNameBase = "bg_quest_plane";
    float speedFactors[SD_GAME_BACKGROUND_NUM] = {
        0.2f, 0.5f, 1.0f, 2.0f,
    };
    float zOrders[SD_GAME_BACKGROUND_NUM] = {
        -100, 10, -1, 10,
    };
    
    m_backgroundBatchNodes = CCArray::createWithCapacity(SD_GAME_BACKGROUND_NUM);
    m_backgroundBatchNodes->retain();
    for (int i = 0; i < SD_GAME_BACKGROUND_NUM; ++i)
    {
        CCString *layerName = CCString::createWithFormat("%s_%d", layerNameBase, i + 1);
        float speed = speedFactors[i];
        
        GameBackgroundBatchNode *bgBatchNode = GameBackgroundBatchNode::creat(layerName->getCString(), speed);
        bgBatchNode->setZOrder(zOrders[i]);
        addChild(bgBatchNode, zOrders[i]);
        m_backgroundBatchNodes->addObject(bgBatchNode);
    }
    return true;
}

void GameView::update(float delta)
{
    switch (m_gameState)
    {
        case KTE_GAMESTATE_START:
        {
            break;
        }
        case KTE_GAMESTATE_SCROLL:
        {
            scrollBackground(delta);
            break;
        }
        case KTE_GAMESTATE_RUNNING:
        {
            break;
        }
            
        default:
            break;
    }
}

void GameView::scrollBackground(float delta)
{
    m_totalTime += delta;
    if (m_totalTime > m_walkDuration)
    {
        m_totalTime = 0.0f;
        m_gameState = KTE_GAMESTATE_IDLE;
    }
    
    CCObject *oneObject = NULL;
    CCARRAY_FOREACH(m_backgroundBatchNodes, oneObject)
    {
        GameBackgroundBatchNode *batchNode = (GameBackgroundBatchNode *)oneObject;
        batchNode->scrollBy(m_walkSpeed, delta);
    }    
}