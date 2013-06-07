//
//  FWMacro.h
//  Framework_Cocos2dx
//
//  Created by ou-h on 13/06/05.
//
//

#ifndef __FWMACROS_HEAD_H__
#define __FWMACROS_HEAD_H__

#include "platform/CCCommon.h"
#include "CCStdC.h"

/**
 * define a create function for a specific type, such as CCLayer
 * @__TYPE__ class type to add create(), such as CCLayer
 * Have one parameter.
 */
#define CREATE_FUNC_ONE_PARAMETER(__TYPE__, varType, varName) \
static __TYPE__* create(varType varName) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init(varName)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

/**
 * define a create function for a specific type, such as CCLayer
 * @__TYPE__ class type to add create(), such as CCLayer
 * Have two parameters.
 */
#define CREATE_FUNC_TWO_PARAMETERS(__TYPE__, varType1, varName1, varType2, varName2) \
static __TYPE__* create(varType1 varName1, varType2 varName2) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init(varName1, varName2)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}


#endif // __FWMACROS_HEAD_H__