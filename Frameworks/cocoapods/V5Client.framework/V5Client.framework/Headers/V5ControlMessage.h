//
//  V5ControlMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"

@interface V5ControlMessage : V5Message

// 控制命令值
@property (nonatomic, assign) NSInteger code;
// 参数数量
@property (nonatomic, assign) NSInteger argc;
// 参数内容
@property (nonatomic, strong) NSString * argv;

- (instancetype)initWithCode:(NSInteger)code
                        argc:(NSInteger)argc
                        argv:(NSString *)argv;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
