//
//  DPDefine.h
//  DPCategory
//
//  Created by 麻小亮 on 2018/11/20.
//  Copyright © 2018 xllpp. All rights reserved.
//

#ifndef DPDefine_h
#define DPDefine_h
#import <UIKit/UIKit.h>
typedef NS_ENUM (NSInteger, DPBlankStatus){
    DPBlankStatusFalse,
    DPBlankStatusZero,
    DPBlankStatusNil
};

static inline DPBlankStatus DPDataBlankStatus (id data) {
    if (data == [NSNull null]) return DPBlankStatusNil;
    if (!data) return DPBlankStatusNil;
    BOOL isBlank = NO;
    if ([data isKindOfClass:[NSNumber class]]) {isBlank = [(NSNumber *)data integerValue] == 0;}
    else if ([data isKindOfClass:[NSString class]]) {isBlank = [(NSString *)data length] == 0;}
    else if ([data isKindOfClass:[NSArray class]]) {isBlank = [(NSArray *)data count] == 0;}
    else if ([data isKindOfClass:[NSDictionary class]]) {isBlank = [(NSDictionary *)data count] == 0;}
    else if ([data isKindOfClass:[NSSet class]]) {isBlank = [(NSSet *)data count] == 0;}
    else if ([data isKindOfClass:[NSIndexSet class]]) {isBlank = [(NSIndexSet *)data count] == 0;}
    else if ([data isKindOfClass:[NSData class]]) {isBlank = [(NSData *)data length] == 0;}
    return isBlank ? DPBlankStatusZero : DPBlankStatusFalse;
}

static inline BOOL DPIsNotBlank(id data){
    return DPDataBlankStatus(data) == DPBlankStatusFalse;
}

static inline BOOL DPIsNilBlank(id data){
    return DPDataBlankStatus(data) == DPBlankStatusNil;
}

static inline BOOL DPIsZeroBlank(id data){
    return DPDataBlankStatus(data) == DPBlankStatusZero;
}

static inline BOOL DPIsNotClassBlank(id data, Class clas){
    if (![data isKindOfClass:clas]) return YES;
    return DPDataBlankStatus(data) == DPBlankStatusFalse;
}

static inline BOOL DPIsNilClassBlank(id data, Class clas){
    if (![data isKindOfClass:clas]) return YES;
    return DPDataBlankStatus(data) == DPBlankStatusNil;
}

static inline BOOL DPIsZeroClassBlank(id data, Class clas){
    if (![data isKindOfClass:clas]) return YES;
    return DPDataBlankStatus(data) == DPBlankStatusZero;
}



/// Convert radians to degrees.
static inline CGFloat DPRadiansToDegrees(CGFloat radians) {
    
    return radians * 180 / M_PI;
}

#define BACKARROWIMAGE_BLACK @"Nav_arrow_back"
#define BACKARROWIMAGE_WHITE @"dh_icon_arrow_w"
#define DP_WIDTH [UIScreen screenWidth]

#define DP_HEIGHT [UIScreen screenHeight]

#define DP_SCALE [UIScreen screenScale]

#if __has_include("WTMacroDefine.h")
#import "WTMacroDefine.h"
#define ISIPHONE_X kWTIsIPhoneX
#else

#define _IPHONE_XR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)

#define _IPHONE_XS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define _IPHONE_XSMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

#define ISIPHONE_X (_IPHONE_XR || _IPHONE_XS || _IPHONE_XSMax ||[[[UIDevice currentDevice] machineModelName] containsString:@"iPhone X"]) 

#endif




#define kStatusBarHeight (ISIPHONE_X?44.f:20.f)
#define kNaviBarHeight (kStatusBarHeight + 44.f)
#define kHomeIndicatorHeight (ISIPHONE_X?34.f:0.f)
#define kTabbarHeight (kHomeIndicatorHeight + 49.f)
#define DPWEAK  __weak typeof(self)weakSelf = self;
#define DPSTRONG  __strong typeof(weakSelf)self = weakSelf;



#endif /* DPDefine_h */
