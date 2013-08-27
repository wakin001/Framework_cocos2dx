//
//  Framework_cocos2dxAppDelegate.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/18.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "GameViewController.h"
#include "FirstScene.h"
#include "FWGame.h"
#include "FruitsViewController.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    FWGame::sharedGame()->setupScreenResolution();
    
    CCSize frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    CCLOG("framesize : %f, %f", frameSize.width, frameSize.height);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCLOG("winSize : %f, %f", winSize.width, winSize.height);
   
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLOG("visibleSize : %f, %f", visibleSize.width, visibleSize.height);

    CCSize visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCLOG("visibleOrigin : %f, %f", visibleOrigin.width, visibleOrigin.height);

    // create a scene. it's an autorelease object
    FirstScene *pScene = FirstScene::create();
    
//    FruitsViewController *pScene = FruitsViewController::create();
    // run
    pDirector->runWithScene(pScene);
    
//    GameViewController *mainScene = GameViewController::create();
//    pDirector->runWithScene(mainScene);
    
//    pDirector->runWithScene(HelloWorld::scene());
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
