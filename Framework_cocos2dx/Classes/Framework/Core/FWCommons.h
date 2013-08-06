//
//  FWCommons.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/03.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWCommons__OBJECT_H__
#define __FWCommons__OBJECT_H__

#include "cocos2d.h"
#include "FWBox2dHelper.h"

/**
 * Check device is ipad or iphone.
 */
#ifdef UI_USER_INTERFACE_IDIOM
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#else
#define IS_IPAD (false)
#endif

/**
 * Check if item is nil before release it.
 */
#if defined(DEBUG) || defined(STAGING) || defined(AWS_TST) || defined(AWS_DEV)
#define FWD_SAFE_RELEASE(x)                         [x release]
#else
#define FWD_SAFE_RELEASE(x)                         [x release], x = nil
#endif

/**
 * Server Http path.
 */
#define FWD_API_ERRORREPORT                         @"other/report"

#define FWD_TIMESTAMP                               @"timestamp"
#define FWD_AES256_SECRETID                         @"21e2a7b5539c5ed965717ad9db287638"

#define FWD_OPENSOCIAL_VIEWERID                     @"opensocial_viewer_id"
#define FWD_KEYCHAIN_SECRETSALTID                   @"jp.klab.katatema.secretSalt"
#define FWD_KEYCHAIN_SECRETID                       @"jp.klab.katatema.secretId"
#define FWD_KEYCHAIN_SESSIONID                      @"jp.klab.katatema.sessionId"
#define FWD_KEYCHAIN_SESSIONCOUNT                   @"jp.klab.katatema.sessionCount"
#define FWD_BUNDLE_VERSION                          @"CFBundleVersion"  //@"CFBundleShortVersionString"
/**
 * Device information.
 */
#define FWD_APP_VERSION                             @"appVersion"       // app version
#define FWD_DEVICE_NAME                             @"deviceName"       // 端末名 delete
#define FWD_DEVICE_MODEL                            @"deviceModel"      // 機種
#define FWD_DEVICE_VERSION                          @"deviceVersion"    // os version
#define FWD_DEVICE_OS                               @"deviceOs"         // iphone android

// api
#define FWD_URL_REGISTERDEVICE                      @"api/registerDevice"

// Notification type
#define FWD_NOTIFICATION_REGISTER_DEVICE_SUCCEED    @"DidRegisterDeviceNotificationSucceed"
#define FWD_NOTIFICATION_REGISTER_DEVICE_FAILED     @"DidRegisterDeviceNotificationFailed"

// Use this id in the first time you enter the scene and download data.
#define FWD_NOTIFICATION_CHANGESCENE                @"change_scene"
#define FWD_NOTIFICATION_PRODUCT_PURCHASED          @"IAPHelperProductPurchasedNotification"
#define FWD_NOTIFICATION_PRODUCT_RESTORED           @"IAPHelperNotificationRestored"
#define FWD_NOTIFICATION_PRODUCT_NOSKPRODUCT        @"IAPHelperNoProductNotification"
#define FWD_NOTIFICATION_PRODUCT_FAILED             @"IAPHelperProductFailedNotification"
#define FWD_NOTIFICATION_PRODUCT_CANCEL             @"IAPHelperProductCancelNotification"

#define FWD_NOTIFICATION_MESSAGE_POPUP              @"message_popup"
#define FWD_NOTIFICATION_MUSICFINISHPLAYING         @"MusicTrackFinishedPlayingNotification";
#define FWD_NOTIFCATION_DID_HIDEOUTSHOWIN           @"remove_loadingview"

// transition lasting time.
#define FWD_TRANSITION_TIME                         0.15f
#define FWD_TRANSITION_TIME_HALF                    FWD_TRANSITION_TIME * 0.5f

#define FWD_JSON_JSON                               @"json"
#define FWD_JSON_ERROR                              @"error"
#define FWD_JSON_CODE                               @"code"
#define FWD_JSON_DESCRIPTION                        @"description"
#define FWD_JSON_TIMESTAMP                          @"timestamp"
#define FWD_JSON_LIST                               @"list"
#define FWD_JSON_ITEMID                             @"Id"
#define FWD_JSON_SESSIONID                          @"sessionId"
#define FWD_JSON_COUNTER                            @"counter"
#define FWD_JSON_SECRETSALT                         @"secretSalt"
#define FWD_JSON_SECRETID                           @"secretId"

#define FWD_ITEM_UPDATED                            @"itemUpdatedAt"    // アイテム
#define FWD_CARD_UPDATED                            @"cardUpdatedAt"    // カード
#define FWD_RAID_UPDATED                            @"raidUpdatedAt"    // レイド

// offset in x for iPhone 5
#define KTD_OFFSETX_IPHONE5                         44

//#define FWD_LOCAL_TEST


/**
 * Transition id.
 */
typedef enum
{
    FWE_TRANS_FADE,
    FWE_TRANS_ENCOUNT,
} FWE_TRANSITION;


/**
 * Language id.
 */
typedef enum
{
    FWE_LANGUAGE_ENGLISH,
    FWE_LANGUAGE_JAPANESE,
} FWE_LANGUAGE;

/**
 * Type of revision resource.
 */
typedef enum
{
    FWE_TYPE_RESOURCE_ITEM,
    FWE_TYPE_RESOURCE_CARD,
} FWE_TYPE_RESOURCE;


class FWCommons : public cocos2d::CCObject
{
public:
    FWCommons();
    
    ~FWCommons();
    
    static float                    randomFloat(float fromFloat, float toFloat);
    static int                      randomInt(int fromInt, int toInt);
    
    /**
     * Convert NSData to Hex NSString.
     */
    cocos2d::CCString *             hexStringFromData(void *data);
    
    /**
     * Convert Hex NSString to NSData.
     */
    void *                          dataFromHexString(cocos2d::CCString *hexString);
    
    
private:
    
};

#endif // __FWCommons__OBJECT_H__