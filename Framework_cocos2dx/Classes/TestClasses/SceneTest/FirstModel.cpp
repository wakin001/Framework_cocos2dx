//
//  FirstModel.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FirstModel.h"

using namespace cocos2d;

FirstModel::FirstModel()
{
}

FirstModel::~FirstModel()
{
    CC_SAFE_RELEASE(m_sMyName);
}

bool FirstModel::init()
{
    m_sMyName = CCString::create("Wang Feng");
    m_sMyName->retain();
    
    m_iMyAge = 30;
	return true;
}