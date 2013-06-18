//
//  FWActionBase.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWActionBase.h"

using namespace cocos2d;

FWActionBase::FWActionBase()
{
}

FWActionBase::~FWActionBase()
{
//    CC_SAFE_RELEASE(m_pCompleteCallBack);
}

bool FWActionBase::init()
{    
	return true;
}

CCNode * FWActionBase::getChildObjectWithParent(CCNode *parent, int tag)
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
void FWActionBase::cleanUpSelf(CCObject *object)
{   
    removeFromParentAndCleanup(true);
}
