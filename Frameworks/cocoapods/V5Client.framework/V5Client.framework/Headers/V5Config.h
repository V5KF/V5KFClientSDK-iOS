//
//  V5Config.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/10.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface V5Config : NSObject

@property (nonatomic, strong) NSString *openId; // [修改]用户id => openId

@property (nonatomic, strong) NSString *uid DEPRECATED_MSG_ATTRIBUTE("此属性将被废弃,请使用openId代替,openId将会透传到座席端用于更多扩展功能"); // 用户id
@property (nonatomic, readonly) NSString *visitor; // 关联uid
@property (nonatomic, strong) NSString *deviceToken; // APNs推送设备标识
@property (nonatomic, strong) NSString *nickname; // 昵称
@property (nonatomic, strong) NSString *avatar; // 头像
@property (nonatomic, assign) NSInteger gender; // 性别
@property (nonatomic, assign) NSInteger vip; // vip等级
@property (nonatomic, strong) NSString *site; // 站点编号
@property (nonatomic, strong) NSString *account; // 应用账号
@property (nonatomic, strong) NSString *appId; // 应用AppId
@property (nonatomic, strong) NSDictionary *userInfo; // 自定义用户信息,字符串键值对格式
@property (nonatomic) BOOL pushEnable; //是否开启了推送

/* 机器人信息 */
@property (nonatomic, strong) NSString *robotName; // 机器人名字
@property (nonatomic, strong) NSString *robotPhoto; // 机器人头像
@property (nonatomic, strong) NSString *robotIntro; // 机器人开场白
@property (nonatomic, strong) NSString *workerIntro; // 接入人工开场白

@property (nonatomic, strong) NSString *authorization;
@property (nonatomic, assign) long timestamp;
@property (nonatomic, assign) long expires;

@property (nonatomic, strong) NSString *workerPhoto;
@property (nonatomic, strong) NSString *workerName;
@property (nonatomic, assign) NSInteger workerId;

/* 适配ATS，自动处理http链接为https，默认YES */
@property (nonatomic, assign) BOOL autoSSL;

- (instancetype)initWithUserDefaults:(NSUserDefaults *)userData;

/**
 *  需要更新用户信息时调用
 */
- (void)shouldUpdateUserInfo;

@end
