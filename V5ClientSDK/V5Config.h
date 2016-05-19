//
//  V5Config.h
//  V5KFClientTest
//
//  Created by V5KF_MBP on 15/12/10.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface V5Config : NSObject

@property (nonatomic, strong) NSString *uid; // 用户id
@property (nonatomic, readonly) NSString *visitor; // 关联uid
@property (nonatomic, strong) NSString *deviceToken; // APNs推送设备标识
@property (nonatomic, strong) NSString *nickname; // 昵称
@property (nonatomic, strong) NSString *avatar; // 头像
@property (nonatomic, assign) NSInteger gender; // 性别
@property (nonatomic, strong) NSString *site; // 站点编号
@property (nonatomic, strong) NSString *account; // 应用账号
//@property (nonatomic, strong) NSDictionary *customContent; // 取消自定义用户信息，该用消息携带自定义参数方式
@property (nonatomic) BOOL pushEnable; //是否开启了推送

@property (nonatomic, strong) NSString *authorization;
@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) long expires;

@property (nonatomic, strong) NSString *workerPhoto;
@property (nonatomic, strong) NSString *workerName;
@property (nonatomic, assign) long long workerId;

- (instancetype)initWithUserDefaults:(NSUserDefaults *)userData;

/**
 *  需要更新用户信息时调用
 */
- (void)shouldUpdateUserInfo;

@end
