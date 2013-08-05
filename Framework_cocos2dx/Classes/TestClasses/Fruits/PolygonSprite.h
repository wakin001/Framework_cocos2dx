//
//  PolygonSprite.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/08/05.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __PolygonSprite__OBJECT_H__
#define __PolygonSprite__OBJECT_H__

typedef enum
{
    STATE_FRUITS_IDEL = 0,
    STATE_FRUITS_TOSSED,
} STATE_FRUITS;

typedef enum
{
    TYPE_FRUITS_WATERMELON = 0,
    TYPE_FRUITS_STRAWBERRY,
    TYPE_FRUITS_PINEAPPLE,
    TYPE_FRUITS_GRAPES,
    TYPE_FRUITS_BANANA,
    TYPE_FRUITS_BOMN,
} TYPE_FRUITS;


#include "FWPolygonSprite.h"

class PolygonSprite : public FWPolygonSprite
{
public:
    PolygonSprite();
    
    ~PolygonSprite();
    
    static PolygonSprite *  spriteWithTexture(CCTexture2D *texture, b2Body *body, bool original);
    static PolygonSprite *  spriteWithFile(const char *filename, b2Body *body, bool original);
    static PolygonSprite *  spriteWithWorld(b2World *world, TYPE_FRUITS type, const char *physicPlistFile);
    
    /**
     * Our main initialization. PRFilledPolygon needs a texture and all the vertices of the polygon it fills.
     * Since the previous step already handled the texture part, this step handles the vertices by collecting
     * them from the sprite’s Box2D body. After passing them to PRFilledPolygon, it proceeds to initialize the
     * variables that you have previously declared.
     */
    virtual bool            initWithTexture(CCTexture2D *texture, b2Body *body, bool original);
    
    /**
     * This is intended for subclasses of FWPolygonSprite so you do nothing except return nil, and deal with it later.
     */
    virtual bool            initWithWorld(b2World *world, TYPE_FRUITS type, const char *physicPlistFile);
    
public:
    CC_SYNTHESIZE(STATE_FRUITS, m_state, State);
    CC_SYNTHESIZE(TYPE_FRUITS, m_type, Type);
    
protected:
    
};

#endif // __PolygonSprite__OBJECT_H__