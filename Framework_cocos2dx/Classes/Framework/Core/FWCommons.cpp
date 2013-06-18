//
//  FWCommons.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/03.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWCommons.h"

using namespace cocos2d;

FWCommons::FWCommons()
{
}

FWCommons::~FWCommons()
{
}

/**
 * Convert NSData to Hex NSString.
 */
cocos2d::CCString * FWCommons::hexStringFromData(void *data)
{
//    return CCString();
}

/**
 * Convert Hex NSString to NSData.
 */
void * FWCommons::dataFromHexString(cocos2d::CCString *hexString)
{
    
}

float FWCommons::randomFloat(float fromFloat, float toFloat)
{
    float diff = toFloat - fromFloat;
    return CCRANDOM_0_1() * diff + fromFloat;
}

int FWCommons::randomInt(int fromInt, int toInt)
{
    int diff = toInt - fromInt;
    return (int)(CCRANDOM_0_1() * diff + fromInt);
}