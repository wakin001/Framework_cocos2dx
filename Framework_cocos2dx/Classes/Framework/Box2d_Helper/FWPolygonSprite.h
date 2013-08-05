//
//  FWPolygonSprite.h
//  Framework_cocos2dx
//
//  Created by ou-h on 13/07/29.
//  Copyright 2013年 Erawppa Co., Ltd.. All rights reserved.
//

#ifndef __FWPolygonSprite__OBJECT_H__
#define __FWPolygonSprite__OBJECT_H__

#include "cocos2d.h"
#include "Box2D.h"
#include "PRFilledPolygon.h"
#include "FWCommons.h"

using namespace cocos2d;

class FWPolygonSprite : public PRFilledPolygon
{
public:
    FWPolygonSprite();
    
    ~FWPolygonSprite();
    
    static FWPolygonSprite *  spriteWithTexture(CCTexture2D *texture, b2Body *body, bool original);
    static FWPolygonSprite *  spriteWithFile(const char *filename, b2Body *body, bool original);
    static FWPolygonSprite *  spriteWithWorld(b2World *world);

    /**
     * Our main initialization. PRFilledPolygon needs a texture and all the vertices of the polygon it fills. 
     * Since the previous step already handled the texture part, this step handles the vertices by collecting 
     * them from the sprite’s Box2D body. After passing them to PRFilledPolygon, it proceeds to initialize the 
     * variables that you have previously declared.
     */
    virtual bool            initWithTexture(CCTexture2D *texture, b2Body *body, bool original);
    
    /**
     * This adds the texture from our file and passes everything to initWithTexture.
     */
    virtual bool            initWithFile(const char *filename, b2Body *body, bool original);
    
    /**
     * This is intended for subclasses of FWPolygonSprite so you do nothing except return nil, and deal with it later.
     */
    virtual bool            initWithWorld(b2World *world);
    
    b2Body *                createBodyForWorld(b2World *    world,
                                               b2Vec2       position,
                                               float        rotation,
                                               b2Vec2 *     vertices,
                                               int32        vertexCount,
                                               float        density,
                                               float        friction,
                                               float        restitution);
    
    void                    activateCollisions();
    void                    deactivateCollisions();
    
    virtual void            setPosition(const CCPoint &position);
    
    /**
     * All this does is to make sure that our Box2D shape and our sprite are in the same position when moving.
     */
    virtual CCAffineTransform nodeToParentTransform(void);
    
public:
    //  This is the Box2D body that is attached to our sprite. It is needed for physics simulation.
    CC_SYNTHESIZE(b2Body *,         m_body,         Body);
    // Complete and sliced sprites will use the same FWPolygonSprite class, as such, differentiating
    // between the two will be important. If this is YES, it means that it is the uncut, or original
    // object that you created, otherwise, it is just a piece of the whole.
    CC_SYNTHESIZE(bool,             m_original,     Original);
    // The center of the polygon within the image won’t always be the same as the center of the image,
    // so it is useful to store this value.
    CC_SYNTHESIZE(b2Vec2,           m_centroid,     Centroid);
    
    // Determines if the polygon has been intersected.
    CC_SYNTHESIZE(bool,             m_sliceEntered, SliceEntered);
    // Determines if there has been 1 complete slice for this polygon.
    CC_SYNTHESIZE(bool,             m_sliceExited,  SliceExited);
    // The point where the slice first intersects the polygon.
    CC_SYNTHESIZE(b2Vec2,           m_entryPoint,   EntryPoint);
    // The point where the slice intersects the polygon for the second time.
    CC_SYNTHESIZE(b2Vec2,           m_exitPoint,    ExitPoint);
    // The exact time the slice entered the polygon. Used to eliminate swipes that are too slow to be considered as cuts.
    CC_SYNTHESIZE(double,           m_sliceEntryTime, SliceEntryTime);
protected:
    
};

#endif // __FWPolygonSprite__OBJECT_H__