//
//  FWDevice.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/20.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWDevice.h"

using namespace cocos2d;

FWDevice::FWDevice()
{
    updateRunningDevice();
}

FWDevice::~FWDevice()
{
}


bool FWDevice::isIPad()
{
    return (m_deviceType == FWE_DEVICE_IPAD);
}

bool FWDevice::isIPadRetina()
{
    return (m_deviceType == FWE_DEVICE_IPAD_RETINA);
}

bool FWDevice::isIPhone()
{
    return (m_deviceType == FWE_DEVICE_IPHONE);
}

bool FWDevice::isIPhoneRetina()
{
    return (m_deviceType == FWE_DEVICE_IPHONE_RETINA);
}

bool FWDevice::isIPhone5()
{
    return (m_deviceType == FWE_DEVICE_IPHONE5);
}

void FWDevice::updateRunningDevice()
{
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    switch (platform)
    {
        case kTargetIphone:
        {
            CCSize winsize = CCDirector::sharedDirector()->getWinSize();
            if (winsize.width > FWD_IPHONE_LANDSCAPE_WIDTH || winsize.height > FWD_IPHONE_LANDSCAPE_WIDTH)
            {
                m_deviceType = FWE_DEVICE_IPHONE5;
            }
            else if( CC_CONTENT_SCALE_FACTOR() == 2 )
            {
                m_deviceType = FWE_DEVICE_IPHONE_RETINA;
            }
            else
            {
                m_deviceType = FWE_DEVICE_IPHONE;
            }
            break;
        }
        case kTargetIpad:
        {
            if (CC_CONTENT_SCALE_FACTOR() == 2)
            {
                m_deviceType = FWE_DEVICE_IPAD_RETINA;
            }
            else
            {
                m_deviceType = FWE_DEVICE_IPAD;
            }
            break;
        }
            
        default:
            m_deviceType = FWE_DEVICE_OTHER;
            break;
    }
}


