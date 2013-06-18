//
//  GameBackgroundBatchNode.cpp
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#define SD_BACKGOURND_MARGIN    2.0f
const int SC_NUMOFIMAGES_HORIZONTALLY = 3.0f;

#include "GameBackgroundBatchNode.h"

using namespace cocos2d;

GameBackgroundBatchNode::GameBackgroundBatchNode()
{
}

GameBackgroundBatchNode::~GameBackgroundBatchNode()
{
}

/**
 * Create function.
 * Notice that fileName has no suffix.
 */
GameBackgroundBatchNode * GameBackgroundBatchNode::creat(const char *fileName, float speed)
{
    GameBackgroundBatchNode *batchNode = new GameBackgroundBatchNode;
    if (batchNode != NULL && batchNode->init(fileName, speed))
    {
        batchNode->autorelease();
        return batchNode;
    }
    CC_SAFE_DELETE(batchNode);
    return NULL;
}

bool GameBackgroundBatchNode::init(const char *fileName, float speed)
{
    CCString *textureFileName = CCString::createWithFormat("%s.png", fileName);
    CCString *plistFileName = CCString::createWithFormat("%s.plist", fileName);
    
    if (CCSpriteBatchNode::initWithFile(textureFileName->getCString(), SC_NUMOFIMAGES_HORIZONTALLY))
    {
        CCSpriteFrameCache *frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
        frameCache->addSpriteFramesWithFile(plistFileName->getCString());
        
        // Set speed.
        m_speed = speed;
        
        for (int i = 0; i < SC_NUMOFIMAGES_HORIZONTALLY; ++i)
        {
            CCString *frameName = CCString::createWithFormat("%s_%d.png", fileName, i + 1);
            CCSprite *bgSprite = CCSprite::createWithSpriteFrameName(frameName->getCString());
            CCSize imageSize = CCSizeMake(bgSprite->getContentSize().width - SD_BACKGOURND_MARGIN,
                                          bgSprite->getContentSize().height);
            bgSprite->setAnchorPoint(ccp(0.0f, 0.5f));
            bgSprite->setPosition(ccp(imageSize.width * i, imageSize.height * 0.5f));
            addChild(bgSprite);
        }
    }
    return true;
}

void GameBackgroundBatchNode::scrollBy(float scrollSpeed, float delta)
{
    float scrollLength = m_speed * scrollSpeed * delta;
    
    CCObject *oneobject = NULL;
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    
    CCArray *children = this->getChildren();
    CCARRAY_FOREACH(children, oneobject)
    {
        CCSprite *bgSprite = (CCSprite *)oneobject;
        CCPoint newPos = bgSprite->getPosition();
        CCSize  size   = CCSizeMake(bgSprite->getContentSize().width - SD_BACKGOURND_MARGIN,
                                    bgSprite->getContentSize().height);
        newPos.x -= scrollLength;
        float direction = scrollLength > 0 ? 1 : -1;
        // Change the position of background image according to the window size.
        if ((newPos.x < -winsize.width && direction == 1) || (newPos.x > winsize.width && direction == -1))
        {
            newPos.x += size.width * SC_NUMOFIMAGES_HORIZONTALLY * direction;
        }
        bgSprite->setPosition(newPos);
    }
}
