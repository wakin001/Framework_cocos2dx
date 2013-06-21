//
//  FWDevice.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/20.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWDevice__OBJECT_H__
#define __FWDevice__OBJECT_H__

typedef enum
{
	FWE_DEVICE_IPHONE,
    FWE_DEVICE_IPHONE_RETINA,
    FWE_DEVICE_IPHONE5,
    FWE_DEVICE_IPAD,
    FWE_DEVICE_IPAD_RETINA,
    
    FWE_DEVICE_OTHER,
} FWE_DEVICE;

#define FWD_IPHONE_LANDSCAPE_WIDTH      480
#define FWD_IPHONE_LANDSCAPE_HEIGHT     320
#define FWD_IPHONE5_LANDSCAPE_WIDTH     568
#define FWD_IPAD_LANDSCAPE_WIDTH        1024
#define FWD_IPAD_LANDSCAPE_HEIGHT       768

#include "cocos2d.h"

class FWDevice
{
public:
    FWDevice();
    
    ~FWDevice();
    
    bool                    isIPad();
    bool                    isIPadRetina();
    
    bool                    isIPhone();
    bool                    isIPhoneRetina();
    bool                    isIPhone5();
    
    bool                    isPlateformIOS();
    
    void                    updateRunningDevice();
    
protected:
    FWE_DEVICE              m_deviceType;
    bool                    m_isIOS;
};

#endif // __FWDevice__OBJECT_H__