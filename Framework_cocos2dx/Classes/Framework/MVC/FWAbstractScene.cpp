//
//  FWAbstractScene.cpp
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FWAbstractScene.h"

using namespace cocos2d;

FWAbstractScene::FWAbstractScene() :
    m_pModel(NULL),
    m_pView(NULL)
{
}

FWAbstractScene::FWAbstractScene(FWAbstractModel * model) :
    m_pModel(model),
    m_pView(NULL)
{
    
}

FWAbstractScene::~FWAbstractScene()
{
    CC_SAFE_RELEASE(m_pModel);
    CC_SAFE_RELEASE(m_pView);
}

#pragma mark - Create function

bool FWAbstractScene::init(FWAbstractModel *model)
{
    m_pModel = model;
    if (m_pModel != NULL)
    {
        m_pModel->retain();
    }
    
    m_eTransitionId = FWE_TRANS_FADE;
    
    m_bIsDataLoaded = true;
    m_eChangeSceneType = FWE_CHANGESCENE_TYPE_PUSH;
    
    return true;
}

//void FWAbstractScene::initialize()
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

bool FWAbstractScene::touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    return false;
}
void FWAbstractScene::touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractScene::touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractScene::touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent)
{
    
}
void FWAbstractScene::onNodeTouched(cocos2d::CCNode *pNode)
{
    
}


#pragma mark - Scene operation
/**
 * Change scene.
 */
void FWAbstractScene::executeChangingScene()
{
    if (m_pNextScene == NULL)
    {
        return;
    }
    // begine ignore interaction events.
    
    CCTransitionScene *pTranScene = NULL;
    switch (m_eTransitionId)
    {
        case FWE_TRANS_FADE:
            pTranScene = CCTransitionScene::create(FWD_TRANSITION_TIME, m_pNextScene);
            break;
            
        default:
            break;
    }
    
    if (pTranScene == NULL)
    {
        return;
    }
    
    switch (m_eChangeSceneType)
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
void FWAbstractScene::replaceScene(FWAbstractScene *scene, FWE_TRANSITION transitionId)
{
    m_pNextScene = scene;
    m_eChangeSceneType = FWE_CHANGESCENE_TYPE_REPLACE;
    m_eTransitionId = transitionId;
    
    if (scene->m_bIsDataLoaded)
    {
        executeChangingScene();
    }
}

/**
 * Push scene with the transition to the scene stack.
 */
void FWAbstractScene::pushScene(FWAbstractScene *scene, FWE_TRANSITION transitionId)
{
    m_pNextScene = scene;
    m_eChangeSceneType = FWE_CHANGESCENE_TYPE_PUSH;
    m_eTransitionId = transitionId;
    
    if (scene->m_bIsDataLoaded)
    {
        executeChangingScene();
    }
}

/**
 * Pop up a scene with transition.
 */
void FWAbstractScene::popScene(FWE_TRANSITION transitionId)
{
    
}

/**
 * Pop up stack top with no tranistion.
 */
void FWAbstractScene::removeCurrentScene()
{
    CCDirector::sharedDirector()->popScene();
    
    // Because we don't use this function to change scenes.
    // Simply set the currentScene to nil.
//    [KTGame sharedGame].currentScene = nil;
}

/**
 * Clear all scenes in the scene stack except self.
 */
void FWAbstractScene::clearAllScenesExceptSelf()
{
//    CCDirector::sharedDirector()->clearAllScenesExceptSelf();
    
    // refresh the currentScene in KTGame.
//    [KTGame sharedGame].currentScene = self;
}

/**
 * Add loading view and set isDataLoaded to NO.
 */
void FWAbstractScene::showLoadingView()
{
    m_bIsDataLoaded = false;
//    [[FWLoadingViewManager sharedManager] showLoadingView];
}

/**
 * Remove loading view and set isDataLoaded to YES.
 */
void FWAbstractScene::removeLoadingView()
{
//    [[FWLoadingViewManager sharedManager] removeLoadingView];
}

/**
 * Show OK button and change message in loading view.
 */
void FWAbstractScene::showConnectionErrorViewWithMessage(cocos2d::CCString *pMessage)
{
//    FWLoadingView * loadingView = [[FWLoadingViewManager sharedManager] loadingView];
//    [loadingView showErrorMessage:message];
}

/**
 * Enable or disable all views in this scene.
 */
void FWAbstractScene::setEnableAllViews(bool bEnable)
{
    
}

/**
 * Remove used sprites and textures
 */
void FWAbstractScene::clearCache()
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


void FWAbstractScene::onEnterTransitionDidFinish()
{
    CCScene::onEnterTransitionDidFinish();
    
    // Ignore interaction events.
    
    // play bgm music.
    setBGM();
}

/**
 * Only call super.onEnter.
 */
void FWAbstractScene::onEnterSuper()
{
    CCScene::onEnter();
}

/**
 * Set bgm.
 */
void FWAbstractScene::setBGM()
{
    
}

/**
 *  Get Previous scene class
 *  If there is one scene in SceneStacks, return nil
 */
//    Class                       previousSceneClass();