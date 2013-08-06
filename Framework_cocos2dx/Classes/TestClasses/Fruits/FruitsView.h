//
//  FruitsView.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FruitsView__OBJECT_H__
#define __FruitsView__OBJECT_H__

#include "cocos2d.h"
#include "FruitsModel.h"
#include "FWAbstractView.h"
#include "Box2D.h"

class FruitsView : public FWAbstractView
{
public:
    FruitsView();
    
    ~FruitsView();
    
    
    CREATE_FUNC(FruitsView);
    CREATE_FUNC_TWO_PARAMETERS(FruitsView, FruitsModel*, model, FWAbstractViewDelegate*, delegate);
    
    virtual bool                    init(FruitsModel *model = NULL, FWAbstractViewDelegate *delegate = NULL);
    
    void                            initSprites(b2World *world);
    
    void                            initBackground();
    
public:
    CC_SYNTHESIZE(cocos2d::CCArray *,   m_cache,        Cache);
    CC_SYNTHESIZE(cocos2d::CCParticleSystemQuad *, m_bladeSparkle, BladeSparkle);
    
protected:
    
};

#endif // __FruitsView__OBJECT_H__