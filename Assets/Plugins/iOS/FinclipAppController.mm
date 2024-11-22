#import "UnityAppController.h"
#import <FinApplet/FinApplet.h>

@interface FinclipAppController : UnityAppController
- (void)appStart:(NSString *)appId;
@end

IMPL_APP_CONTROLLER_SUBCLASS (FinclipAppController)

@implementation FinclipAppController

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    [super application:application didFinishLaunchingWithOptions:launchOptions];
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[NSClassFromString(@"ViewController") new]];
    [self.window makeKeyAndVisible];
    
    NSMutableArray *storeArrayM = [NSMutableArray array];
    FATStoreConfig *storeConfig = [[FATStoreConfig alloc] init];
    storeConfig.sdkKey = @"22LyZEib0gLTQdU3MUauAbdAy0lL3+wYQ2qWJM71nJA=";
    storeConfig.sdkSecret = @"16c31e3fc3db24a9";
    storeConfig.apiServer = @"https://www.finclip.com";
    storeConfig.apmServer = @"https://www.finclip.com";
    storeConfig.cryptType = FATApiCryptTypeSM;
    
    
    [storeArrayM addObject:storeConfig];
    
    FATConfig *config = [FATConfig configWithStoreConfigs:storeArrayM];
    BOOL result = [[FATClient sharedClient] initWithConfig:config error:nil];
    
    NSLog(@"注册SDK%@！！！！", result? @"成功" : @"失败");
    
    
    return YES;
}

- (void)appStart:(NSString *)appId {
    FATAppletRequest *request = [[FATAppletRequest alloc] init];
    request.appletId = appId;
    [[FATClient sharedClient] startAppletWithRequest:request InParentViewController:self.rootViewController completion:nil closeCompletion:nil];
}


#ifdef __cplusplus
extern "C" {
#endif
    
extern void appletStart(const char *appIdChar)
{
    NSLog(@"打开小程序");
    NSString *appId = [NSString stringWithUTF8String:appIdChar];
    NSLog(@"%@", appId);
    
    FinclipAppController *controller = (FinclipAppController *)[UIApplication sharedApplication].delegate;
    [controller appStart:appId];
}
    
#ifdef __cplusplus
}
#endif

@end
