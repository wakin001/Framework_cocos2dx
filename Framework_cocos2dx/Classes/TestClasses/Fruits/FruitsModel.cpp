//
//  FruitsModel.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FruitsModel.h"

using namespace cocos2d;

FruitsModel::FruitsModel()
{
}

FruitsModel::~FruitsModel()
{
}

bool FruitsModel::init()
{
    if (!FWAbstractModel::init())
    {
        return false;
    }
    return true;
}
