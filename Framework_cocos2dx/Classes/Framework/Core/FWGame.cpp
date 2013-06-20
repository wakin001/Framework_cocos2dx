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
    CCDirector *director = CCDirector::sharedDirector();
    CCSize winsize = director->getWinSize();
    CCSize winsizeInPixel = director->getWinSizeInPixels();
    CCSize visibleSize = director->getVisibleSize();
    CCSize visibleOrigin = director->getVisibleOrigin();
    
    CCSize framesize = CCEGLView::sharedOpenGLView()->getFrameSize();
    
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    std::vector<std::string> searchPaths;
    std::vector<std::string> resDirOrders;
    
    // Set
    if (m_device->isIPhoneRetina())
    {
        //3.5-inch
        resDirOrders.push_back("resources-iphonehd");  //Resources/Published-iOS/resources-iphonehd
        
        pDirector->setContentScaleFactor(2.f);         //2倍のスケールサイズ
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(FWD_IPHONE_LANDSCAPE_WIDTH,
                                                               FWD_IPHONE_LANDSCAPE_HEIGHT,
                                                               kResolutionShowAll);
    }
//    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(568 * 2, 320 * 2, kResolutionNoBorder);
//    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
//    if (platform == kTargetIphone || platform == kTargetIpad)
//    {
//        searchPaths.push_back("Published-iOS"); // Resources/Published-iOS
//        if (screenSize.height > 480)
//        {
//            //Retainaによる幅調整
//            resDirOrders.push_back("resources-iphonehd");  //Resources/Published-iOS/resources-iphonehd
//            pDirector->setContentScaleFactor(2.f);         //2倍のスケールサイズ
//            if (screenSize.width==1136.0 || screenSize.height==1136.0 )
//            {
//                //4-inch
//                CCEGLView::sharedOpenGLView()->setDesignResolutionSize(568, 320, kResolutionShowAll);
//            }
//            else
//            {
//                //3.5-inch
//                CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionShowAll);
//            }
//        }
//        else
//        {
//            //通常サイズ
//            resDirOrders.push_back("resources-iphone");    //Resources/Published-iOS/resources-iphone
//            CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionShowAll);
//        }
//        
//    }
//    else
//    {
//        // iOS以外（Androidなど)
//        searchPaths.push_back("Published-iOS"); // Resources/Published-iOS
//        resDirOrders.push_back("resources-iphone");
//        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionExactFit);
//        
//    }
//    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
//    CCFileUtils::sharedFileUtils()->setSearchResolutionsOrder(resDirOrders);
}

