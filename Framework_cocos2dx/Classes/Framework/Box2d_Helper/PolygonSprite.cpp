//
//  PolygonSprite.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "PolygonSprite.h"

using namespace cocos2d;

PolygonSprite::PolygonSprite()
: m_sliceExited(false),
  m_sliceEntered(false),
  m_entryPoint(b2Vec2(0.0f, 0.0f)),
  m_exitPoint(b2Vec2(0.0f, 0.0f)),
  m_sliceEntryTime(0.0)
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

PolygonSprite * PolygonSprite::spriteWithWorld(b2World *world)
{
    PolygonSprite * polygonSprite = new PolygonSprite;
    if (polygonSprite == NULL || !polygonSprite->initWithWorld(world))
    {
        CC_SAFE_DELETE(polygonSprite);
        return NULL;
    }
    polygonSprite->autorelease();
    return polygonSprite;
}

bool PolygonSprite::initWithTexture(CCTexture2D *texture, b2Body *body, bool original)
{
    // gather all the verticles from out Box2D shape.
    b2Fixture *originalFixture = body->GetFixtureList();
    b2PolygonShape *shape = (b2PolygonShape *)originalFixture->GetShape();
    
    int vertexCount = shape->GetVertexCount();
    Vector2dVector points;
    for (int i = 0; i < vertexCount; i++)
    {
        Vector2d point(shape->GetVertex(i).x * PTM_RATIO,
                       shape->GetVertex(i).y * PTM_RATIO);
        points.push_back(point);
    }
    
    if (PRFilledPolygon::initWithPointsAndTexture(points, texture))
    {
        m_body = body;
        m_body->SetUserData(this);
        m_original = original;
        // Get the center of the polygon.
        m_centroid = m_body->GetLocalCenter();
        
        // assign an anchor point base on the center.
        setAnchorPoint(CCPoint(m_centroid.x * PTM_RATIO / texture->getContentSize().width,
                               m_centroid.y * PTM_RATIO / texture->getContentSize().height));
        return true;
    }
    return false;
}

bool PolygonSprite::initWithFile(const char *filename, b2Body *body, bool original)
{
    CCAssert(filename != NULL, "Invalide filename for sprite.");
    CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(filename);
    return initWithTexture(texture, body, original);
}

bool PolygonSprite::initWithWorld(b2World *world)
{
    // nothing to do here.
    return false;
}

/**
 * To create a body, you need to define a body definition, a body object, a shape, 
 * and a fixture definition. No real hard values are being assigned here yet since 
 * this method will be used by subclasses of PolygonSprite later on.
 */
b2Body * PolygonSprite::createBodyForWorld(b2World *    world,
                                           b2Vec2       position,
                                           float        rotation,
                                           b2Vec2 *     vertices,
                                           int32        vertexCount,
                                           float        density,
                                           float        friction,
                                           float        restitution)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.angle = rotation;
    b2Body *body = world->CreateBody(&bodyDef);
    
    b2FixtureDef fixtureDef;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.restitution = restitution;
    fixtureDef.filter.categoryBits = 0;
    fixtureDef.filter.maskBits = 0;
    
    b2PolygonShape shape;
    shape.Set(vertices, vertexCount);
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
    
    return body;
}

/**
 * These two are used for filtering collisions between objects such that if a category 
 * bit of an object matches a mask bit of another object and vice versa, there will be a 
 * collision between those two objects. You set these to 0 first because you don’t want any 
 * collisions happening when the objects are first initialized.
 */
void PolygonSprite::activateCollisions()
{
    b2Fixture *fixture = m_body->GetFixtureList();
    b2Filter filter = fixture->GetFilterData();
    filter.categoryBits = 0x0001;
    filter.maskBits = 0x0001;
    fixture->SetFilterData(filter);
}
void PolygonSprite::deactivateCollisions()
{
    b2Fixture *fixture = m_body->GetFixtureList();
    b2Filter filter = fixture->GetFilterData();
    filter.categoryBits = 0;
    filter.maskBits = 0;
    fixture->SetFilterData(filter);
}

void PolygonSprite::setPosition(const CCPoint &position)
{
    PRFilledPolygon::setPosition(position);
    m_body->SetTransform(b2Vec2(position.x / PTM_RATIO, position.y / PTM_RATIO), m_body->GetAngle());
}

/**
 * All this does is to make sure that our Box2D shape and our sprite are in the same position when moving.
 */
CCAffineTransform PolygonSprite::nodeToParentTransform(void)
{
    b2Vec2 pos  = m_body->GetPosition();
    
    float x = pos.x * PTM_RATIO;
    float y = pos.y * PTM_RATIO;
    
    if ( isIgnoreAnchorPointForPosition() )
    {
        x += m_obAnchorPointInPoints.x;
        y += m_obAnchorPointInPoints.y;
    }
    
    // Make matrix
    float radians = m_body->GetAngle();
    float c = cosf(radians);
    float s = sinf(radians);
    
    if( ! m_obAnchorPointInPoints.equals(CCPointZero) )
    {
        x += c*-m_obAnchorPointInPoints.x + -s*-m_obAnchorPointInPoints.y;
        y += s*-m_obAnchorPointInPoints.x + c*-m_obAnchorPointInPoints.y;
    }
    
    // Rot, Translate Matrix
    m_sTransform = CCAffineTransformMake( c,  s,
                                         -s,    c,
                                         x,    y );
    
    return m_sTransform;
}