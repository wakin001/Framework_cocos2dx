//
//  FWPhysicsViewController.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWPhysicsViewController__OBJECT_H__
#define __FWPhysicsViewController__OBJECT_H__

#include "cocos2d.h"
#include "FWAbstractViewController.h"
#include "Box2D.h"
#include "GLES-Render.h"

class FWPhysicsViewController : public FWAbstractViewController
{
public:
    FWPhysicsViewController();
    
    ~FWPhysicsViewController();
    
    void                        initPhysics();
    virtual void                draw();
    virtual void                update(float delta);
    
protected:
    b2World                     *m_world;
    cocos2d::extension::GLESDebugDraw    *m_debugDraw;
    
};

#endif // __FWPhysicsViewController__OBJECT_H__