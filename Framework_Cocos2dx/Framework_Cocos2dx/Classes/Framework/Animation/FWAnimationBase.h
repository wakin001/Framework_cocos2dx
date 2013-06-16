//
//  FWAnimationBase.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAnimationBase__NODE_H__
#define __FWAnimationBase__NODE_H__

#include "cocos2d.h"

class FWAnimationBase : public cocos2d::CCNode
{
public:
    FWAnimationBase();
    
    ~FWAnimationBase();
    
	virtual bool                init();  
    
	CREATE_FUNC(FWAnimationBase);
    
    CCNode *                    getChildObjectWithParent(CCNode *parent, int tag);
    
    // Clean up call back.
    virtual void                cleanUpSelf(CCObject *object);
    
protected:
    // Call this callback function after the animation is finished.
    cocos2d::SEL_CallFuncO      onCompletedCallBack;
    
};

#endif // __FWAnimationBase__NODE_H__