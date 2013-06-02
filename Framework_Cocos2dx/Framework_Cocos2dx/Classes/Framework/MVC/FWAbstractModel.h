//
//  FWAbstractModel.h
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAbstractModel__OBJECT_H__
#define __FWAbstractModel__OBJECT_H__

#include "cocos2d.h"

class FWAbstractModel : public cocos2d::CCObject
{
public:
    FWAbstractModel();
    
    ~FWAbstractModel();
    
    
    void parseJsonDic(cocos2d::CCDictionary *dic);
    
    void parseString(cocos2d::CCString *str);
    
private:
    
};

#endif // __FWAbstractModel__OBJECT_H__