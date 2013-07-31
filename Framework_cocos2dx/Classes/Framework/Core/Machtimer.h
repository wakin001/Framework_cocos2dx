//
//  Mathtimer.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __Mathtimer__OBJECT_H__
#define __Mathtimer__OBJECT_H__

#include <assert.h>
#include <unistd.h>
#include "CCObject.h"
#include "cocos2d.h"

class Machtimer :public cocos2d::CCObject
{
private:
    long t0;
    
public:
    void init();
    void start();
    long elapsed();
    // return elapsed of time in Sec Unit:
    long elapsedSec();
    // return elasped of time in MS
    long elapsedMS();
    static void initialize();
    static long currentTimeInMS();
};

#endif // __Mathtimer__OBJECT_H__