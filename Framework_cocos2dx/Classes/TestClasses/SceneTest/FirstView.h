//
//  FirstView.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FirstView__OBJECT_H__
#define __FirstView__OBJECT_H__

#include "cocos2d.h"
#include "FWAbstractView.h"
#include "FirstModel.h"

class FirstView : public FWAbstractView
{
public:
    FirstView();
    
    ~FirstView();
    
    CREATE_FUNC(FirstView);
    CREATE_FUNC_TWO_PARAMETERS(FirstView, FWAbstractModel*, model, FWAbstractViewDelegate*, delegate);

    virtual bool                    init(FWAbstractModel *model = NULL, FWAbstractViewDelegate *delegate = NULL);
    
    void                            onBackButtonClicked();
    
    virtual void                    ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
private:
    
};

#endif // __FirstView__OBJECT_H__