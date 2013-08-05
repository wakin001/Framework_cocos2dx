//
//  FWRayCastCallback.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/30.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWRayCastCallback__OBJECT_H__
#define __FWRayCastCallback__OBJECT_H__

#include "Box2D.h"

class FWRayCastCallback : public b2RayCastCallback
{
public:
    FWRayCastCallback();
    
    ~FWRayCastCallback();
    
    float32                 ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float32 fraction);
    
protected:
    
};

#endif // __FWRayCastCallback__OBJECT_H__