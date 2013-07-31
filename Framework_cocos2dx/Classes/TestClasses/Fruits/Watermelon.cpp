//
//  Watermelon.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "Watermelon.h"

using namespace cocos2d;

Watermelon::Watermelon()
{
}

Watermelon::~Watermelon()
{
}

PolygonSprite * Watermelon::spriteWithTexture(CCTexture2D *texture, b2Body *body, bool original)
{
    PolygonSprite * polygonSprite = new Watermelon;
    if (polygonSprite == NULL || !polygonSprite->initWithTexture(texture, body, original))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

PolygonSprite * Watermelon::spriteWithFile(const char *filename, b2Body *body, bool original)
{
    PolygonSprite * polygonSprite = new Watermelon;
    if (polygonSprite == NULL || !polygonSprite->initWithFile(filename, body, original))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

PolygonSprite * Watermelon::spriteWithWorld(b2World *world)
{
    PolygonSprite * polygonSprite = new Watermelon;
    if (polygonSprite == NULL || !polygonSprite->initWithWorld(world))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

bool Watermelon::initWithWorld(b2World *world)
{
    int32 count = 7;
    const char *file = "watermelon.png";
    b2Vec2 vertices[] = {
        b2Vec2(5.0/PTM_RATIO,15.0/PTM_RATIO),
        b2Vec2(18.0/PTM_RATIO,7.0/PTM_RATIO),
        b2Vec2(32.0/PTM_RATIO,5.0/PTM_RATIO),
        b2Vec2(48.0/PTM_RATIO,7.0/PTM_RATIO),
        b2Vec2(60.0/PTM_RATIO,14.0/PTM_RATIO),
        b2Vec2(34.0/PTM_RATIO,59.0/PTM_RATIO),
        b2Vec2(28.0/PTM_RATIO,59.0/PTM_RATIO)
    };
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    b2Body *body = createBodyForWorld(world,
                                      b2Vec2(screenSize.width * 0.5f / PTM_RATIO, screenSize.height * 0.5f / PTM_RATIO),
                                      0,
                                      vertices,
                                      count,
                                      5.0f,
                                      0.2f,
                                      0.2f);
    if (!PolygonSprite::initWithFile(file, body, true))
    {
        return false;
    }
    
    // init more values later.
    
    return true;
}
