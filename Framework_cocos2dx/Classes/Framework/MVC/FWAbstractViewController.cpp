//
//  FWAbstractViewController.cpp
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAbstractViewController.h"

using namespace cocos2d;

FWAbstractViewController::FWAbstractViewController() :
    m_model(NULL),
    m_view(NULL)
{
}

FWAbstractViewController::FWAbstractViewController(FWAbstractModel * model) :
    m_model(model),
    m_view(NULL)
{
    
}

FWAbstractViewController::~FWAbstractViewController()
{
    CC_SAFE_RELEASE(m_model);
    CC_SAFE_RELEASE(m_view);
}

#pragma mark - Create function

bool FWAbstractViewController::init(FWAbstractModel *model)
{
    m_model = model;
    if (m_model != NULL)
    {
        m_model->retain();
    }
    
    m_transitionId = FWE_TRANS_FADE;
    
    m_isDataLoaded = true;
    m_changeSceneType = FWE_CHANGESCENE_TYPE_PUSH;
    
    return true;
}

//void FWAbstractViewController::initialize()
//{
//    m_eTransitionId = FWE_TRANS_FADE;
//    
//    m_bIsDataLoaded = true;
//    m_eChangeSceneType = FWE_CHANGESCENE_TYPE_PUSH;
//    
//    //[self registerNotificationWithName:FWD_NOTIFICATION_CHANGESCENE];
//    
//    // Set default time scale.
////    [KTUtil setTimeScale:1.0f];
//
//}

#pragma mark - delegate methods

bool FWAbstractViewController::touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    return false;
}
void FWAbstractViewController::touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractViewController::touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractViewController::touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractViewController::onNodeTouched(cocos2d::CCNode *pNode)
{
    
}


#pragma mark - Scene operation
/**
 * Change scene.
 */
void FWAbstractViewController::executeChangingScene()
{
    if (m_nextScene == NULL)
    {
        return;
    }
    // begine ignore interaction events.
    
    CCTransitionScene *pTranScene = NULL;
    switch (m_transitionId)
    {
        case FWE_TRANS_FADE:
            pTranScene = CCTransitionScene::create(FWD_TRANSITION_TIME, m_nextScene);
            break;
            
        default:
            break;
    }
    
    if (pTranScene == NULL)
    {
        return;
    }
    
    switch (m_changeSceneType)
    {
        case FWE_CHANGESCENE_TYPE_PUSH:
            CCDirector::sharedDirector()->pushScene(pTranScene);
            break;
            
        case FWE_CHANGESCENE_TYPE_REPLACE:
            CCDirector::sharedDirector()->replaceScene(pTranScene);
            break;
            
        default:
            break;
    }

    // refresh the currentScene in KTGame.
//    [KTGame sharedGame].currentScene = self.nextScene;
//    
//    // Set the previousTransitionScene.
//    [KTGame sharedGame].currentScene.previousTransitionSceneClass = [self class];
//    
//    // Set nextScene to nil to avoid from call executeChangingScene for many times, which will
//    // be crashed!
//    self.nextScene = nil;
}

/**
 * Replace scene with transition. Do not add it to stack.
 */
void FWAbstractViewController::replaceScene(FWAbstractViewController *scene, FWE_TRANSITION transitionId)
{
    m_nextScene = scene;
    m_changeSceneType = FWE_CHANGESCENE_TYPE_REPLACE;
    m_transitionId = transitionId;
    
    if (scene->m_isDataLoaded)
    {
        executeChangingScene();
    }
}

/**
 * Push scene with the transition to the scene stack.
 */
void FWAbstractViewController::pushScene(FWAbstractViewController *scene, FWE_TRANSITION transitionId)
{
    m_nextScene = scene;
    m_changeSceneType = FWE_CHANGESCENE_TYPE_PUSH;
    m_transitionId = transitionId;
    
    if (scene->m_isDataLoaded)
    {
        executeChangingScene();
    }
}

/**
 * Pop up a scene with transition.
 */
void FWAbstractViewController::popScene(FWE_TRANSITION transitionId)
{
    
}

/**
 * Pop up stack top with no tranistion.
 */
void FWAbstractViewController::removeCurrentScene()
{
    CCDirector::sharedDirector()->popScene();
    
    // Because we don't use this function to change scenes.
    // Simply set the currentScene to nil.
//    [KTGame sharedGame].currentScene = nil;
}

/**
 * Clear all scenes in the scene stack except self.
 */
void FWAbstractViewController::clearAllScenesExceptSelf()
{
//    CCDirector::sharedDirector()->clearAllScenesExceptSelf();
    
    // refresh the currentScene in KTGame.
//    [KTGame sharedGame].currentScene = self;
}

/**
 * Add loading view and set isDataLoaded to NO.
 */
void FWAbstractViewController::showLoadingView()
{
    m_isDataLoaded = false;
//    [[FWLoadingViewManager sharedManager] showLoadingView];
}

/**
 * Remove loading view and set isDataLoaded to YES.
 */
void FWAbstractViewController::removeLoadingView()
{
//    [[FWLoadingViewManager sharedManager] removeLoadingView];
}

/**
 * Show OK button and change message in loading view.
 */
void FWAbstractViewController::showConnectionErrorViewWithMessage(cocos2d::CCString *pMessage)
{
//    FWLoadingView * loadingView = [[FWLoadingViewManager sharedManager] loadingView];
//    [loadingView showErrorMessage:message];
}

/**
 * Enable or disable all views in this scene.
 */
void FWAbstractViewController::setEnableAllViews(bool bEnable)
{
    
}

/**
 * Remove used sprites and textures
 */
void FWAbstractViewController::clearCache()
{
    
}

/**
 * Add a popup viewcontroller into self.viewController.
 * If self.viewController == nil, create a new one.
 */
//    void                        addPopupViewController(KTPopUpBaseViewController *popupVC);

/**
 * Remove popup view controller from self.viewController.
 * Remove popup view from parent view.
 */
//    void                        removePopupViewController(KTPopUpBaseViewController *popupVC);


void FWAbstractViewController::onEnterTransitionDidFinish()
{
    CCScene::onEnterTransitionDidFinish();
    
    // Ignore interaction events.
    
    // play bgm music.
    setBGM();
}

/**
 * Only call super.onEnter.
 */
void FWAbstractViewController::onEnterSuper()
{
    CCScene::onEnter();
}

/**
 * Set bgm.
 */
void FWAbstractViewController::setBGM()
{
    
}

/**
 *  Get Previous scene class
 *  If there is one scene in SceneStacks, return nil
 */
//    Class                       previousSceneClass();