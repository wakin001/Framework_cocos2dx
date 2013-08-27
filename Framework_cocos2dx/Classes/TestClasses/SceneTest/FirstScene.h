//
//  FirstScene.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FirstScene__OBJECT_H__
#define __FirstScene__OBJECT_H__

#include "cocos2d.h"
#include "FWAbstractViewController.h"
#include "FirstModel.h"
#include "FirstView.h"

class FirstScene : public FWAbstractViewController
{
public:
    FirstScene();
    
    ~FirstScene();
    
    CREATE_FUNC(FirstScene);
    CREATE_FUNC_ONE_PARAMETER(FirstScene, FirstModel*, model);
    
    virtual bool                init(FWAbstractModel * model = NULL);
    
    void                        testURLRequest();
    void                        onHttpRequestCompleted(cocos2d::CCObject *pSender, void *data);
    
    virtual void                onNodeTouched(cocos2d::CCNode *pNode);

private:
    
};

#endif // __FirstScene__OBJECT_H__