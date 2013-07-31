//
//  FruitsViewController.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FruitsViewController__OBJECT_H__
#define __FruitsViewController__OBJECT_H__

#define calculate_determinant_2x2(x1, y1, x2, y2)       (x1 * y2 - y1 * x2)
#define calculate_determinant_2x3(x1, y1, x2, y2, x3, y3)       (x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)

//typedef int (*pf)(const void*, const void*);

#include "cocos2d.h"
#include "FruitsModel.h"
#include "FruitsView.h"
#include "FWPhysicsViewController.h"
#include "FWRayCastCallback.h"

class FruitsViewController : public FWPhysicsViewController
{
public:
    FruitsViewController();
    
    ~FruitsViewController();
    
    CREATE_FUNC(FruitsViewController);
    CREATE_FUNC_ONE_PARAMETER(FruitsViewController, FruitsModel*, model);
    
    virtual bool                init(FruitsModel * model = NULL);
    
    virtual void                draw();
    virtual void                update(float delta);
    
    virtual bool                touchesBeganWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesMoveWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    virtual void                touchesEndWithPoint(cocos2d::CCPoint point, cocos2d::CCEvent *pEvent);
    
    static int                  comparator(const void *a, const void *b);
    b2Vec2 *                    arrangeVertices(b2Vec2 *vertices, int count);
    void                        splitPolygonSprite(PolygonSprite *sprite);
    bool                        areVerticesAcceptable(b2Vec2 *vertices, int count);
    b2Body *                    createBodyWithPosition(b2Vec2 position, float rotation, b2Vec2 *vertices, int32 count, float density, float friction, float restitution);
    void                        clearSlices();
    
    void                        checkAndSliceObjects();
    
protected:
    cocos2d::CCPoint            m_startPoint;
    cocos2d::CCPoint            m_endPoint;
    FWRayCastCallback           *m_raycastCallback;
};

#endif // __FruitsViewController__OBJECT_H__