//
//  AppDelegate.m
//  ClientDemo
//
//  Created by chyrain on 16/1/13.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "AppDelegate.h"
#import "V5ClientAgent.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    // 初始化SDK
    [V5ClientAgent initWithSiteId:@"10000" account:@"v5kf" exceptionDelegate:nil];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    
    // 退出到后台时，通知SDK用户离线
    [[V5ClientAgent shareClient] onApplicationDidEnterBackground];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    
    // 移动到前台时，通知SDK用户上线并连接
    [[V5ClientAgent shareClient] onApplicationWillEnterForeground];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    /* 解决限制旋转方向导致打开相册报错问题 */
    if ([V5ClientAgent shareClient].isPhotoLibrary) { // 允许打开相册时任意方向
        return UIInterfaceOrientationMaskAll;
    } else { // 恢复到您需要指定的方向
        return UIInterfaceOrientationMaskPortrait;
    }
}

@end
