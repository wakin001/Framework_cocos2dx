//
//  FWCommons.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/03.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWCommons__OBJECT_H__
#define __FWCommons__OBJECT_H__

#include "cocos2d.h"
#include "FWBox2dHelper.h"

/**
 * Check device is ipad or iphone.
 */
#ifdef UI_USER_INTERFACE_IDIOM
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#else
#define IS_IPAD (false)
#endif

// transition lasting time.
#define FWD_TRANSITION_TIME                         0.15f
#define FWD_TRANSITION_TIME_HALF                    FWD_TRANSITION_TIME * 0.5f


/**
 * Transition id.
 */
typedef enum
{
    FWE_TRANS_FADE,
    FWE_TRANS_ENCOUNT,
} FWE_TRANSITION;


class FWCommons : public cocos2d::CCObject
{
public:
    FWCommons();
    
    ~FWCommons();
    
    static float                    randomFloat(float fromFloat, float toFloat);
    static int                      randomInt(int fromInt, int toInt);
    
    /**
     * Convert NSData to Hex NSString.
     */
    cocos2d::CCString *             hexStringFromData(void *data);
    
    /**
     * Convert Hex NSString to NSData.
     */
    void *                          dataFromHexString(cocos2d::CCString *hexString);
    
    
private:
    
};

#endif // __FWCommons__OBJECT_H__