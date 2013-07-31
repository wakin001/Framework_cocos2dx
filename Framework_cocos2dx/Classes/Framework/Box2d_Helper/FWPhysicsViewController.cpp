//
//  FWPhysicsViewController.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWPhysicsViewController.h"

using namespace cocos2d;

FWPhysicsViewController::FWPhysicsViewController()
: m_world(NULL),
  m_debugDraw(NULL)
{
}

FWPhysicsViewController::~FWPhysicsViewController()
{
    CC_SAFE_DELETE(m_world);
    CC_SAFE_DELETE(m_debugDraw);
}

void FWPhysicsViewController::initPhysics()
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    b2Vec2 gravity;
    gravity.Set(0.0f, -10.0f);
    m_world = new b2World(gravity);
    
    // Do we want to let bodies sleep?
    m_world->SetAllowSleeping(true);
    
    m_world->SetContinuousPhysics(true);
    
    m_debugDraw = new extension::GLESDebugDraw( PTM_RATIO );
    m_world->SetDebugDraw(m_debugDraw);
    
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    //        flags += b2Draw::e_jointBit;
    //        flags += b2Draw::e_aabbBit;
    //        flags += b2Draw::e_pairBit;
    //        flags += b2Draw::e_centerOfMassBit;
    m_debugDraw->SetFlags(flags);
    
    
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); // bottom-left corner
    
    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = m_world->CreateBody(&groundBodyDef);
    
    // Define the ground box shape.
    b2EdgeShape groundBox;
    
    // bottom
    
    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    
    // top
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    
    // left
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    
    // right
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
}

void FWPhysicsViewController::draw()
{
    //
    // IMPORTANT:
    // This is only for debug purposes
    // It is recommend to disable it
    //
    FWAbstractViewController::draw();
    
    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
    
    kmGLPushMatrix();
    
    m_world->DrawDebugData();
    
    kmGLPopMatrix();
}

void FWPhysicsViewController::update(float dt)
{
    //It is recommended that a fixed time step is used with Box2D for stability
    //of the simulation, however, we are using a variable time step here.
    //You need to make an informed choice, the following URL is useful
    //http://gafferongames.com/game-physics/fix-your-timestep/
    
    int velocityIterations = 8;
    int positionIterations = 1;
    
    // Instruct the world to perform a single step of simulation. It is
    // generally best to keep the time step and iterations fixed.
    m_world->Step(dt, velocityIterations, positionIterations);
    
    //Iterate over the bodies in the physics world
    for (b2Body* b = m_world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            //Synchronize the AtlasSprites position and rotation with the corresponding body
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
        }
    }
}
