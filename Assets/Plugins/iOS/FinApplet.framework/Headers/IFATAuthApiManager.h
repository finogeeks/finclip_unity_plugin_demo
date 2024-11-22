//
//  IFATAuthApiManager.h
//  FinApplet
//
//  Created by 滔 on 2023/4/4.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#ifndef IFATAuthApiManager_h
#define IFATAuthApiManager_h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FATAuthModel.h"
#import "FATPrivacyInfo.h"
#import "FATError.h"
#import "FATConstant.h"
#import "FATExternalPageConfig.h"

@protocol IFATAuthApiManager<NSObject>

/// 打开个人信息与权限管理页面
/// @param parentViewController 父控制器，打开的个人信息与权限管理页面会在父控制器上模态弹出
- (void)openPrivacyManage:(UIViewController *)parentViewController;

/// 打开个人信息与权限管理页面
/// @param parentViewController parentViewController 父控制器，打开的个人信息与权限管理页面会在父控制器上模态弹出
/// @param pageConfig 页面的I配置，如返回按钮图片 标题位置
- (void)openPrivacyManage:(UIViewController *)parentViewController pageConfig:(FATExternalPageConfig *)pageConfig;


/// 获取小程序的隐私协议配置
/// @param appletId  小程序id
/// @param complete  结果回调，privacyInfo包含隐私配置相关信息
- (void)getAppletPrivacyInfo:(NSString *)appletId complete:(void (^)(FATPrivacyInfo *privacyInfo, FATError *error))complete;

/// 获取小程序权限设置
/// @param appletId  小程序id
- (NSArray<FATAuthModel *> *)getAppletAuthSetting:(NSString *)appletId;


/// 更新小程序的权限设置
/// @param authType  权限类型
/// @param authValue  新的权限值
/// @param appletId  小程序id
- (BOOL)updateAppletAuth:(FATAuthorizationType)authType authValue:(NSInteger)authValue forApplet:(NSString *)appletId;



@end

#endif /* IFATAuthApiManager_h */
