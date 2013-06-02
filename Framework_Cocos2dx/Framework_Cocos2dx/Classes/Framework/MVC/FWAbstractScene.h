//
//  FWAbstractScene.h
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAbstractScene__NODE_H__
#define __FWAbstractScene__NODE_H__

#include "cocos2d.h"

class FWAbstractScene : public cocos2d::CCScene
{
public:
    FWAbstractScene();
    
    ~FWAbstractScene();
    
	virtual bool init();  
    
//	LAYER_NODE_FUNC(FWAbstractScene);
    CREATE_FUNC(FWAbstractScene);
    
private:
    
};

#endif // __FWAbstractScene__NODE_H__