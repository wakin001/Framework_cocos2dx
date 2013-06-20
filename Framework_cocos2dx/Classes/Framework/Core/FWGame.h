//
//  FWGame.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/20.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWGame__NODE_H__
#define __FWGame__NODE_H__

#include "cocos2d.h"
#include "FWDevice.h"

class FWGame : public cocos2d::CCObject
{
public:
    ~FWGame();
    
    static FWGame *         sharedGame();
    
    /**
     * Setup the screen resolution acoording to the device.
     * Set the resources search directory.
     */
    void                    setupScreenResolution();
    
    /**
     * Properties.
     */
    CC_SYNTHESIZE_READONLY(FWDevice *, m_device, Device);
    
private:
    FWGame();
    static FWGame *         m_instance;
};

#endif // __FWGame__NODE_H__