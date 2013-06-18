//
//  FirstModel.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FirstModel__OBJECT_H__
#define __FirstModel__OBJECT_H__

#include "cocos2d.h"
#include "FWAbstractModel.h"

class FirstModel : public FWAbstractModel
{
public:
    FirstModel();
    
    ~FirstModel();
    
    virtual bool                init();
    
    /**
     * Get/ Set functions.
     */
    CC_SYNTHESIZE(cocos2d::CCString *, name, MyName);
    
protected:
    cocos2d::CCString *         m_sMyName;
    int                         m_iMyAge;
};

#endif // __FirstModel__OBJECT_H__