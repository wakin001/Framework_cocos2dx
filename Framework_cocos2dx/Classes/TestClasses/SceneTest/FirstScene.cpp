//
//  FirstScene.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FirstScene.h"
#include "FirstView.h"
#include "FirstModel.h"

using namespace cocos2d;

FirstScene::FirstScene()
{
}

FirstScene::~FirstScene()
{
}

bool FirstScene::init(FWAbstractModel * model)
{
    // Don't need set model if model is not NULL, since we have done it in super class.
    if (NULL == model)
    {
        m_pModel = FirstModel::create();
        m_pModel->retain();
    }
    
    m_pView = FirstView::create(m_pModel, this);
    addChild(m_pView);
    
    return true;
}

