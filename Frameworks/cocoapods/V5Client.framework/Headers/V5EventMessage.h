//
//  V5TextMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 20/10/27.
//  Copyright © 2020年 V5KF. All rights reserved.
//

#import "V5Message.h"

@interface V5EventMessage : V5Message

// 事件类型
@property (nonatomic, strong) NSString *event;

// 正在输入事件
@property (nonatomic, strong) NSString *content;
@property (nonatomic, assign) BOOL cancel;

// 撤回消息事件
@property (nonatomic, assign) long long cancelId;
@property (nonatomic, assign) long long cancelWId;
@property (nonatomic, assign) long long cancelMId;

// 消息已读/未读事件
@property (nonatomic, assign) BOOL readAll;


- (instancetype)initWithTyping:(BOOL)typing andContent:(NSString *)content;
- (instancetype)initWithReadAll:(BOOL)readed;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
