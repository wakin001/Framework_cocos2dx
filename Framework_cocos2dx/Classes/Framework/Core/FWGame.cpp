//
//  FWGame.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/20.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWGame.h"

using namespace cocos2d;

FWGame * FWGame::m_instance = NULL;

FWGame * FWGame::sharedGame()
{
    if (m_instance == NULL)
    {
        m_instance = new FWGame();
    }
    return m_instance;
}

FWGame::FWGame()
{
    m_device = new FWDevice();
}

FWGame::~FWGame()
{
    CC_SAFE_DELETE(m_device);
}

/**
 * Setup the screen resolution acoording to the device.
 * Set the resources search directory.
 */
void FWGame::setupScreenResolution()
{
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    std::vector<std::string> searchPaths;
    
    // Set
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)     // iOS platform
    
    if (m_device->isIPhoneRetina())
    {
        CCLOG("is iphone retina.");
        //3.5-inch
        searchPaths.push_back("./images/iphonehd");  //Resources/Published-iOS/resources-iphonehd
        
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionNoBorder);
        pDirector->setContentScaleFactor(2.0f);         //2倍のスケールサイズ
    }
    else if (m_device->isIPhone5()) // 4-inch
    {
        CCLOG("is iphone 5.");
        searchPaths.push_back("./images/iphonehd");  //Resources/Published-iOS/resources-iphonehd
        
        
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE5_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionNoBorder);
        pDirector->setContentScaleFactor(2.f);         //2倍のスケールサイズ
    }
    else if (m_device->isIPhone())
    {
        CCLOG("is iphone3GS.");
        searchPaths.push_back("./images/iphone");  //Resources/Published-iOS/resources-iphone
        
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionNoBorder);
        pDirector->setContentScaleFactor(1.0f);
    }

#else        // Other plateform. (Android...)

    searchPaths.push_back("./images"); // Resources/Published-iOS
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                           FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                           kResolutionExactFit);

#endif
    // About search path, please check: http://www.cocos2d-x.org/projects/cocos2d-x/wiki/Mechanism_of_loading_resources
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
}

