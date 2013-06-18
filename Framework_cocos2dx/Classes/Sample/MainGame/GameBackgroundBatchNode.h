//
//  GameBackgroundBatchNode.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/06/17.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __GameBackgroundBatchNode__OBJECT_H__
#define __GameBackgroundBatchNode__OBJECT_H__

#include "cocos2d.h"

class GameBackgroundBatchNode : public cocos2d::CCSpriteBatchNode
{
public:
    GameBackgroundBatchNode();
    
    ~GameBackgroundBatchNode();
    
    /**
     * Create function.
     * Notice that fileName has no suffix.
     */
    static GameBackgroundBatchNode *        creat(const char *fileName, float speed);
    bool                                    init(const char *fileName, float speed);
    
    void                                    scrollBy(float scrollSpeed, float delta);
    
protected:
//    cocos2d::CCString *                     m_textureFileName;
//    cocos2d::CCString *                     m_plistFileName;
    float                                   m_speed;
};

#endif // __GameBackgroundBatchNode__OBJECT_H__