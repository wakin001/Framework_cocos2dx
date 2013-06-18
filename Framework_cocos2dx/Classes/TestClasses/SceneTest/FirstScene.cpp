//
//  FirstScene.cpp
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#include "FirstScene.h"
#include "FirstView.h"
#include "FirstModel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpClient.h"

using namespace cocos2d;
using namespace cocos2d::extension;

FirstScene::FirstScene()
{
}

FirstScene::~FirstScene()
{
}

bool FirstScene::init(FWAbstractModel * model)
{
    // Don't need set model if model is not NULL, since we have done it in super class.
    if (NULL == model)
    {
        m_model = FirstModel::create();
        m_model->retain();
    }
    
    m_view = FirstView::create(m_model, this);
    addChild(m_view);
    
    testURLRequest();
    
    return true;
}

void FirstScene::testURLRequest()
{
    CCHttpRequest *requestor = new CCHttpRequest;
    requestor->setRequestType(CCHttpRequest::kHttpPost);
    requestor->setUrl("www.google.com");
    requestor->setResponseCallback(this, callfuncND_selector(FirstScene::onHttpRequestCompleted));
    
    CCHttpClient::getInstance()->send(requestor);
}

void FirstScene::onHttpRequestCompleted(cocos2d::CCObject *pSender, void *data)
{
    CCHttpResponse *response = (CCHttpResponse *)data;
    CCHttpRequest::HttpRequestType type = response->getHttpRequest()->getRequestType();
    
    if (type == CCHttpRequest::kHttpPost)
    {
        if (response->isSucceed())
        {
            CCLog("Get Request Completed!");
            CCLog("Content: %s", response->getResponseData());
        }
        else
        {
            CCLog("Get error: %s", response->getResponseData());
        }
    }
    
    delete response->getHttpRequest();
}

