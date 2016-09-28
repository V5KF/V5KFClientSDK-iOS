//
//  V5MediaMessage.h
//  mcss
//
//  Created by chyrain on 16/8/19.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "V5Message.h"

@class V5MediaMessage;
typedef void (^V5MediaLoadSuccessBlock)(V5MediaMessage *message);
typedef void (^V5MediaLoadFailureBlock)(V5MediaMessage *message, NSString *reason);

@interface V5MediaMessage : V5Message

// 本地路径
@property (nonatomic, strong) NSString *filePath;
// 格式
@property (nonatomic, strong) NSString * format;

- (NSString *)getDefaultFormat;
- (NSString *)getDefaultURL;
- (void)loadMediaSuccess:(V5MediaLoadSuccessBlock)success
                 failure:(V5MediaLoadFailureBlock)failure
                progress:(void (^)(float progress))progress;

@end
