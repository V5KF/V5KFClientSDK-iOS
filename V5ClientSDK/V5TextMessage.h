//
//  V5TextMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/2.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"

@interface V5TextMessage : V5Message

// 文本内容
@property (nonatomic, strong) NSString * content;

- (instancetype)initWithContent:(NSString *)content;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
