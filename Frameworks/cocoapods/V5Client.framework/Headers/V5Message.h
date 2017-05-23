//
//  V5Message.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/2.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "V5Defination.h"

#ifdef V5_DEBUG
#define JSON_OPTION NSJSONWritingPrettyPrinted // 1
#else
#define JSON_OPTION 0
#endif


@interface V5Message : NSObject

// 系统消息id
@property (nonatomic, assign) long long messageId;
// 坐席id
@property (nonatomic, assign) long long wId;
// 会话起始时间
@property (nonatomic, assign) NSInteger sessionStart;
// 发送状态
@property (nonatomic, assign) KV5MessageSendStatus state;
// 问题命中与否
@property (nonatomic, assign) KV5QuestionHitState hit;
// 消息类型
@property (nonatomic, assign) KV5MessageType messageType;
// 消息标志
@property (nonatomic, assign) KV5MessageDir direction;
// 消息创建时间
@property (nonatomic, assign) unsigned long createTime;
// 相关问题消息数组
@property (nonatomic, strong) NSMutableArray<V5Message *> *candidate;
// 自定义参数
@property (nonatomic, strong) NSDictionary *customContent;
// 自定义消息id
@property (nonatomic, assign) long long msgId;

- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)getDefaultContent;
- (NSString *)toJSONString;
- (void)addPropertyToJSONObject:(NSMutableDictionary *)JSONObj;

@end
