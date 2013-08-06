//
//  PolygonSprite.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/08/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "PolygonSprite.h"

using namespace cocos2d;

PolygonSprite::PolygonSprite()
{
}

PolygonSprite::~PolygonSprite()
{
}

PolygonSprite * PolygonSprite::spriteWithTexture(CCTexture2D *texture, b2Body *body, bool original)
{
    PolygonSprite * polygonSprite = new PolygonSprite;
    if (polygonSprite == NULL || !polygonSprite->initWithTexture(texture, body, original))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

PolygonSprite * PolygonSprite::spriteWithFile(const char *filename, b2Body *body, bool original)
{
    PolygonSprite * polygonSprite = new PolygonSprite;
    if (polygonSprite == NULL || !polygonSprite->initWithFile(filename, body, original))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

PolygonSprite * PolygonSprite::spriteWithWorld(b2World *world, TYPE_FRUITS type, const char *physicPlistFile)
{
    PolygonSprite * polygonSprite = new PolygonSprite;
    if (polygonSprite == NULL || !polygonSprite->initWithWorld(world, type, physicPlistFile))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

/**
 * Our main initialization. PRFilledPolygon needs a texture and all the vertices of the polygon it fills.
 * Since the previous step already handled the texture part, this step handles the vertices by collecting
 * them from the sprite’s Box2D body. After passing them to PRFilledPolygon, it proceeds to initialize the
 * variables that you have previously declared.
 */
bool PolygonSprite::initWithTexture(CCTexture2D *texture, b2Body *body, bool original)
{
    bool result = FWPolygonSprite::initWithTexture(texture, body, original);
    
    m_state = STATE_FRUITS_IDEL;
    
    return result;
}

bool PolygonSprite::initWithWorld(b2World *world, TYPE_FRUITS type, const char *physicPlistFile)
{
    if (!FWPolygonSprite::initWithWorld(world))
    {
        return false;
    }
    
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename("fruits.plist");
    if (fullPath.length() <= 0)
    {
        return false;
    }
    CCDictionary* pDict = CCDictionary::createWithContentsOfFile(fullPath.c_str());
    CCDictionary* dicData = (CCDictionary*)pDict->objectForKey("bodies");
    dicData = (CCDictionary*)dicData->objectForKey(physicPlistFile);
    CCArray *fixtures = (CCArray*)dicData->objectForKey("fixtures");
    if (fixtures == NULL || fixtures->count() <= 0)
    {
        return false;
    }
    dicData = (CCDictionary*)fixtures->objectAtIndex(0);
    CCArray *polygonData = (CCArray*)dicData->objectForKey("polygons");
    if (polygonData == NULL || polygonData->count() <= 0)
    {
        return false;
    }
    polygonData = (CCArray*)polygonData->objectAtIndex(0);
    
    // Parse vertiecs.
    int32 count = polygonData->count();
    std::vector<b2Vec2> vertices;
    for (int i = 0; i < count; ++i)
    {
        CCString *value = (CCString *)polygonData->objectAtIndex(i);
        CCPoint point = CCPointFromString(value->getCString());
        vertices.push_back(b2Vec2(point.x / FWBox2dHelper::pixelsToMeterRatio(), point.y / FWBox2dHelper::pixelsToMeterRatio()));
    }
    
    // Create body
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    b2Body *body = createBodyForWorld(world,
                                      b2Vec2(screenSize.width * 0.5f / FWBox2dHelper::pixelsToMeterRatio(), screenSize.height * 0.5f / FWBox2dHelper::pixelsToMeterRatio()),
                                      0,
                                      &vertices[0],
                                      count,
                                      5.0f,
                                      0.2f,
                                      0.2f);
    
    const char *file = (std::string(physicPlistFile) + std::string(".png")).c_str();
    if (!PolygonSprite::initWithFile(file, body, true))
    {
        return false;
    }
    
    // Set fruits type.
    setType(type);
    
    // init particle system.
    std::string particleFileName = std::string(physicPlistFile) + std::string("_splurt.plist");
    m_splurt = CCParticleSystemQuad::create(particleFileName.c_str());
    m_splurt->stopSystem();
    
    return true;
}

