//
//  V5LocationMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"

@interface V5LocationMessage : V5Message

// 纬度
@property (nonatomic, assign) double x;
// 经度
@property (nonatomic, assign) double y;
// 精度
@property (nonatomic, assign) double scale;
// 标签
@property (nonatomic, strong) NSString * label;

- (instancetype)initWithLatitude:(double)x longitude:(double)y;
- (instancetype)initWithLatitude:(double)x
                       longitude:(double)y
                           scale:(double)scale
                           label:(NSString *)label;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
