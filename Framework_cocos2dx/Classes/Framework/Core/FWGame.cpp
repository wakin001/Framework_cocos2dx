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
    std::vector<std::string> resDirOrders;
    
    // Set
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)     // iOS platform
        
    if (m_device->isIPhoneRetina())
    {
        //3.5-inch
        resDirOrders.push_back("resources-iphonehd");  //Resources/Published-iOS/resources-iphonehd
        
        
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(400,
                                                               200,
                                                               kResolutionNoBorder);
//        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
//                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
//                                                               kResolutionNoBorder);
        
        pDirector->setContentScaleFactor(768.0f / 200);         //2倍のスケールサイズ
    }
    else if (m_device->isIPhone5()) // 4-inch
    {
        resDirOrders.push_back("resources-iphonehd");  //Resources/Published-iOS/resources-iphonehd
        
        pDirector->setContentScaleFactor(2.f);         //2倍のスケールサイズ
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE5_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionShowAll);
    }
    else if (m_device->isIPhone())
    {
        resDirOrders.push_back("resources-iphone");  //Resources/Published-iOS/resources-iphone
        
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionShowAll);
    }

#else        // Other plateform. (Android...)

    searchPaths.push_back("Published-iOS"); // Resources/Published-iOS
    resDirOrders.push_back("resources-iphone");
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                           FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                           kResolutionExactFit);

#endif
    
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    CCFileUtils::sharedFileUtils()->setSearchResolutionsOrder(resDirOrders);
}

