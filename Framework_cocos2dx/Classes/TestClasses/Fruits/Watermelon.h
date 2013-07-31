//
//  Watermelon.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __Watermelon__OBJECT_H__
#define __Watermelon__OBJECT_H__

#include "cocos2d.h"
#include "PolygonSprite.h"

class Watermelon : public PolygonSprite
{
public:
    Watermelon();
    
    ~Watermelon();
    
    static PolygonSprite *      spriteWithTexture(CCTexture2D *texture, b2Body *body, bool original);
    static PolygonSprite *      spriteWithFile(const char *filename, b2Body *body, bool original);
    static PolygonSprite *      spriteWithWorld(b2World *world);
    
    virtual bool                initWithWorld(b2World *world);
    
protected:
    
};

#endif // __Watermelon__OBJECT_H__