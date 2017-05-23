//
//  V5ArticlesMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"
#import "V5Article.h"

@interface V5ArticlesMessage : V5Message

// 多图文数组
@property (nonatomic, strong) NSMutableArray<V5Article *> * articles;

- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
