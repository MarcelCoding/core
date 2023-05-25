#ifndef _BUILD_NATIVE_CONTROL_JS_EMBED_H_
#define _BUILD_NATIVE_CONTROL_JS_EMBED_H_

#include "./js_base.h"

#ifndef JS_ENGINE_JAVASCRIPTCORE

#include "v8.h"

inline NSJSBase::CJSEmbedObject* unwrap_native(const v8::Local<v8::Object>& value)
{
	v8::Handle<v8::External> field = v8::Handle<v8::External>::Cast(value->GetInternalField(0));
	return (NSJSBase::CJSEmbedObject*)field->Value();
}

#endif

#ifdef JS_ENGINE_JAVASCRIPTCORE

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol JSEmbedObjectProtocol
- (void*) getNative;
@end

#if __has_feature(objc_arc)
#define SUPER_DEALLOC
#else
#define SUPER_DEALLOC [super dealloc]
#endif

#define EMBED_OBJECT_WRAPPER_METHODS(CLASS)     \
-(id) init                                      \
{                                               \
	self = [super init];                        \
	if (self)                                   \
		m_internal = new CLASS();               \
	return self;                                \
}                                               \
-(void) dealloc                                 \
{                                               \
	RELEASEOBJECT(m_internal);                  \
	SUPER_DEALLOC;								\
}                                               \
- (void*) getNative                             \
{                                               \
	return m_internal;                          \
}

#endif

#endif // _BUILD_NATIVE_CONTROL_JS_EMBED_H_
