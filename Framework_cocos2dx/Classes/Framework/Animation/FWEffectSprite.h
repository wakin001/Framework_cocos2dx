//
//  FWEffectNode.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/06.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWEffectNode__NODE_H__
#define __FWEffectNode__NODE_H__

#include "cocos2d.h"

class FWEffectSprite : public cocos2d::CCSprite
{
public:
    FWEffectSprite();
    
    ~FWEffectSprite();
    
	virtual bool                init();  
    
	CREATE_FUNC(FWEffectSprite);
    
    static FWEffectSprite *     create(const char *effectName,
                                       int frameCount,
                                       float delay,
                                       bool deleteAfterFinishing);
    bool                         init(const char *effectName,
                                     int frameCount,
                                     float delay,
                                     bool deleteAfterFinishing);
    
    virtual void                removeSelf();
    
protected:
};

#endif // __FWEffectNode__NODE_H__