//
//  Mathtimer.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include <time.h>
#include "Machtimer.h"
#include "platform.h"

using namespace cocos2d;

void Machtimer::initialize() {
}

void Machtimer::init() {
    t0 = currentTimeInMS();
}

void Machtimer::start() {
    t0 = currentTimeInMS();
}

long Machtimer::elapsed() {
    return currentTimeInMS()- t0;
}

long Machtimer::elapsedSec() {
    return elapsed() * 10000;
}
long Machtimer::elapsedMS() {
    
    return elapsed();
}

long Machtimer::currentTimeInMS() {
    
    struct cocos2d::cc_timeval now;
    
    cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL);
    return (now.tv_sec * 1000 + now.tv_usec /1000.0)/10;
}

