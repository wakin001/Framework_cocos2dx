//
//  FWAbstractScene.cpp
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAbstractScene.h"

using namespace cocos2d;

FWAbstractScene::FWAbstractScene()
{
}

FWAbstractScene::~FWAbstractScene()
{
}

bool FWAbstractScene::init()
{
	if ( !init() )
	{
		return false;
	}
    
	return true;
}

