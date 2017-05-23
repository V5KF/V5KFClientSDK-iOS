//
//  V5VideoMessage.h
//  mcss
//
//  Created by chyrain on 16/8/16.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "V5MediaMessage.h"

@class UIImage;

@interface V5VideoMessage : V5MediaMessage

// 媒体id
@property (nonatomic, strong) NSString * media_id;
// 媒体thumb_id
@property (nonatomic, strong) NSString * thumb_id;
// 标题
@property (nonatomic, strong) NSString *title;
// 描述
@property (nonatomic, strong) NSString *desc;
// 视频URL
@property (nonatomic, strong) NSString * url;
// 视频封面
@property (nonatomic, strong) UIImage *coverImage;

- (instancetype)initWithFilePath:(NSString *)path;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
