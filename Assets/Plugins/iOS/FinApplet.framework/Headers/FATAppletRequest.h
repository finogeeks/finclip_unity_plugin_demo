//
//  FATAppletRequest.h
//  FinApplet
//
//  Created by Haley on 2020/11/15.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FATConstant.h"

@class FATDebugInfo;

@interface FATAppletBaseRequest : NSObject
#pragma mark - server info

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apiServer;

#pragma mark - 小程序 info

/**
小程序id，必填
*/
@property (nonatomic, copy) NSString *appletId;

/**
小程序名称，非必填
*/
@property (nonatomic, copy) NSString *appName;

/**
 小程序图标的网络地址，非必填
 */
@property (nonatomic, copy) NSString *appletLogo;

/**
小程序的启动参数，非必填。
支持的key，请参考FATStartParamKey
*/
@property (nonatomic, copy) NSDictionary<FATStartParamKey, NSString *> *startParams;

/**
打开小程序时的转场动画方式
*/
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

/**
 自定义的scheme数组（非必填）
 */
@property (nonatomic, strong) NSArray<NSString *> *schemes;

/**
 小程序右上角关闭按钮的配置项。
 默认是false，如果设置成true的话，首次打开的小程序的关闭按钮会被隐藏，使用api打开其他小程序时，关闭按钮正常显示
*/
@property (nonatomic, assign) BOOL hideMiniProgramCloseButton;

@end

@interface FATAppletRequest : FATAppletBaseRequest

/**
 小程序的索引。
 每提交一次小程序，都会生成一个索引，所以想打开指定版本小程序，就必须传该值
*/
@property (nonatomic, strong) NSNumber *sequence;

/**
 离线小程序压缩包路径
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
 离线基础库压缩包路径
 */
@property (nonatomic, copy) NSString *offlineFrameworkZipPath;

/// 体验版小程序会带小程序信息
@property (nonatomic, copy) NSDictionary *trialInfo;

@end

/// 小程序解密请求（二维码打开小程序）
@interface FATAppletDecryptRequest : NSObject

@property (nonatomic, copy) NSString *appletId; //管理小程序打开体验版，info加密信息中没有带appletId字段
/**
 加密信息
*/
@property (nonatomic, copy) NSString *info;

/**
打开小程序时的转场动画方式
*/
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

@interface FATAppletQrCodeRequest : NSObject

/**
 二维码内容
*/
@property (nonatomic, strong) NSString *qrCode;

/**
 打开小程序时的转场动画方式
 */
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

/**
 运行本地小程序
 */
@interface FATLocalAppletRequest : FATAppletBaseRequest

/**
 小程序的logo图片对象，非必填
 如果为nil，则会加载appletLogo。
 */
@property (nonatomic, strong) UIImage *logoImage;

/**
 小程序可访问的域名白名单列表，非必填
 如果domainList 为空，即nil 或[]，则不校验域名
 */
@property (nonatomic, copy) NSArray *domainList;

/**
 小程序分包信息，必填。
 */
@property (nonatomic, copy) NSArray *packages;

/**
 小程序分包配置。示例如下：
 {
    "compatibleMode":@(YES),   //小游戏是否使用webView渲染：YES:WebView；NO:JSCore
    "isLazyLoading":@(YES),   //是否开启按需注入
    "entryPagePath":"pages/index/inede"    //小程序首页路径
 }
 */
@property (nonatomic, copy) NSDictionary *packageConfig;

/**
 小程序压缩包密码，必填
 */
@property (nonatomic, copy) NSString *zipPassword;

/**
 基础库离线包地址，必填
 */
@property (nonatomic, copy) NSString *offlineFrameworkZipPath;

/**
 是否使用基础库缓存，非必填
 如果设置为YES，则会使用的基础库缓存。
 否则，则每次打开小程序都会使用传入的基础库
 */
@property (nonatomic, assign) BOOL useFrameworkCache;

#pragma mark - 小程序分包加载
/**
 可以是小程序版本号，也可以是小程序版本的唯一标识比如md5（适用于小程序分包加载，小程序分包加载必填）
 小程序会根据version来缓存小程序，小程序需要加载分包时优先查找缓存中相同version的小程序，没找到则会触发代理方法，由宿主app提供
 小程序分包路径通过[FATClient sharedClient].delegate的代理方法localApplet:packDict:zipPathCallback:设置
 */
@property (nonatomic, copy) NSString *version;

/**版本描述*/
@property (nonatomic, copy) NSString *versionDescription;

#pragma mark - 加载整个小程序
/**
 是否使用本地小程序缓存，默认值为NO（适用于加载整个小程序，加载整个小程序非必填）
 如果设置为YES，则会使用的小程序缓存。
 否则，则每次打开小程序都会使用传入的小程序离线包
 */
@property (nonatomic, assign) BOOL useAppletCache;

/**
 小程序的离线包地址（适用于加载整个小程序，加载整个小程序必填）
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
 小程序的自定义API白名单列表（非必填）
 */
@property (nonatomic, strong) NSArray<NSString *> *extApiWhiteList;

/**
项目类型，默认为小程序
 */
@property (nonatomic, assign) FATProjectType projectType;

/**
小程序版本类型
 */
@property (nonatomic, assign) FATAppletVersionType appletVersionType;

/**
 远程调试信息
 */
@property (nonatomic, strong) FATDebugInfo *debugInfo;

@end

@interface FATLocalInterfaceAppletRequest : FATAppletBaseRequest

/**
小程序版本类型
 */
@property (nonatomic, assign) FATAppletVersionType appletVersionType;

/**
 远程调试信息
 */
@property (nonatomic, strong) FATDebugInfo *debugInfo;

/**
 拓展信息（在代理方法中透传使用）
 */
@property (nonatomic, copy) NSDictionary *extraData;

/**
 强制更新
 */
@property (nonatomic, assign) BOOL forceUpdate;


@end

/**
 远程调试信息
 */
@interface FATDebugInfo : NSObject

/**
 远程调试链接（类型为字符串数组）
 */
@property (nonatomic, copy) NSArray<NSString *> *url;

/**
 channelId：远程服务唯一标识
 */
@property (nonatomic, copy) NSString *channelId;

@end
