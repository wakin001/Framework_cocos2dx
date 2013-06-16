//
//  FWAbstractViewController.h
//  Cocos2dxPRG
//
//  Created by wang feng on 13/06/02.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWAbstractViewController__NODE_H__
#define __FWAbstractViewController__NODE_H__

typedef enum
{
    FWE_CHANGESCENE_TYPE_PUSH,
    FWE_CHANGESCENE_TYPE_REPLACE,
} FWE_CHANGESCENE_TYPE;

#include "cocos2d.h"
#include "FWAbstractModel.h"
#include "FWAbstractView.h"
#include "FWCommons.h"

class FWAbstractViewController : public cocos2d::CCScene, public FWAbstractViewDelegate
{
public:
    FWAbstractViewController();
    FWAbstractViewController(FWAbstractModel * model);
    
    virtual ~FWAbstractViewController();

#pragma mark - Create function
    /**
     * Create scene with FWAbstractModel.
     */
    CREATE_FUNC(FWAbstractViewController);
    CREATE_FUNC_ONE_PARAMETER(FWAbstractViewController, FWAbstractModel*, model);

    virtual bool                init(FWAbstractModel *model = NULL);
    
    /**
     * Macro
     */
    CC_SYNTHESIZE(FWAbstractModel *,           model,          Model);
    CC_SYNTHESIZE(FWAbstractView *,            view,           View);
    CC_SYNTHESIZE(bool,                        isDataLoaded,   IsDataLoaded);
    CC_SYNTHESIZE(FWE_CHANGESCENE_TYPE,        type,           ChangeSceneType);
    CC_SYNTHESIZE(FWE_TRANSITION,              transitionId,   TransitionId);
    
    
#pragma mark - delegate methods
    
    virtual bool                touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesCancelledWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                onNodeTouched(cocos2d::CCNode *pNode);
    
#pragma mark - Scene operation
    
    /**
     * Change scene.
     */
    void                        executeChangingScene();
    
    /**
     * Replace scene with transition. Do not add it to stack.
     */
    void                        replaceScene(FWAbstractViewController *scene, FWE_TRANSITION transitionId = FWE_TRANS_FADE);
    
    /**
     * Push scene with the transition to the scene stack.
     */
    void                        pushScene(FWAbstractViewController *scene, FWE_TRANSITION transitionId = FWE_TRANS_FADE);
    
    /**
     * Pop up a scene with transition.
     */
    void                        popScene(FWE_TRANSITION transitionId = FWE_TRANS_FADE);
    
    /**
     * Pop up stack top with no tranistion.
     */
    void                        removeCurrentScene();
    
    /**
     * Clear all scenes in the scene stack except self.
     */
    void                        clearAllScenesExceptSelf();
    
    /**
     * Add loading view and set isDataLoaded to NO.
     */
    void                        showLoadingView();
    
    /**
     * Remove loading view and set isDataLoaded to YES.
     */
    void                        removeLoadingView();
    
    /**
     * Show OK button and change message in loading view.
     */
    void                        showConnectionErrorViewWithMessage(cocos2d::CCString *pMessage);
    
    /**
     * Enable or disable all views in this scene.
     */
    void                        setEnableAllViews(bool bEnable);
    
    /**
     * Remove used sprites and textures
     */
    void                        clearCache();
    
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
    
#pragma mark - inherit
    
    virtual void                onEnterTransitionDidFinish();
    
    /**
     * Only call super.onEnter.
     */
    void                        onEnterSuper();
    
    /**
     * Set bgm.
     */
    virtual void                setBGM();
    
    /**
     *  Get Previous scene class
     *  If there is one scene in SceneStacks, return nil
     */
//    Class                       previousSceneClass();
    

    
protected:
    
    FWAbstractModel             *m_pModel;
    FWAbstractView              *m_pView;
    
    FWAbstractViewController    *m_pNextScene;
    bool                        m_bIsDataLoaded;
    
    FWE_CHANGESCENE_TYPE        m_eChangeSceneType;
    
    FWE_TRANSITION              m_eTransitionId;
    
};

#endif // __FWAbstractViewController__NODE_H__