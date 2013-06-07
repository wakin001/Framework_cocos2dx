//
//  FWAnimation.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/06.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAnimation__OBJECT_H__
#define __FWAnimation__OBJECT_H__

#include "cocos2d.h"

class FWAnimation : public cocos2d::CCAnimation
{
public:
    FWAnimation();
    
    ~FWAnimation();
    
    static CCAnimation *        create(const char * frameName, int frameCount, float delay);
    
protected:
    
};

#endif // __FWAnimation__OBJECT_H__