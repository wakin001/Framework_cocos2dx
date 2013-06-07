//
//  FWAnimationBase.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAnimationBase.h"

using namespace cocos2d;

FWAnimationBase::FWAnimationBase()
{
}

FWAnimationBase::~FWAnimationBase()
{
//    CC_SAFE_RELEASE(m_pCompleteCallBack);
}

bool FWAnimationBase::init()
{    
	return true;
}

CCNode * FWAnimationBase::getChildObjectWithParent(CCNode *parent, int tag)
{
    CCNode *pNode = parent->getChildByTag(tag);
    if (NULL != pNode)
    {
        return pNode;
    }
    
    CCArray *paChildren = parent->getChildren();
    CCObject *pChild = NULL;
    CCARRAY_FOREACH(paChildren, pChild)
    {
        pNode = getChildObjectWithParent((CCNode *)pChild, tag);
        if (NULL != pNode)
        {
            return pNode;
        }
    }
    return NULL;
}

// Clean up call back.
void FWAnimationBase::cleanUpSelf(CCObject *object)
{   
    removeFromParentAndCleanup(true);
}
