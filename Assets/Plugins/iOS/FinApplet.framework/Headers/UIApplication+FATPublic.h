//
//  UIApplication+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIApplication (FATPublic)

/// 从keyWindow.rootViewController 查找最顶层视图控制器
- (UIViewController *)fat_topViewController;

/// 从指定页面，查找顶层视图控制器
/// - Parameter rootViewController: 指定的页面控制器
- (UIViewController *)fat_topViewController:(UIViewController *)rootViewController;

@end

