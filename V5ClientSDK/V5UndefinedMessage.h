//
//  V5UndefinedMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"

@interface V5UndefinedMessage : V5Message

// 未定义消息均以字典方式保存
@property (nonatomic, strong) NSDictionary *data;

- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
