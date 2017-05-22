//
//  V5ImageMessage.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"

@class UIImage;

@interface V5ImageMessage : V5Message

// 图片URL
@property (nonatomic, strong) NSString * picUrl;
// 图片媒体id
@property (nonatomic, strong) NSString * mediaId;
// 本地图片
@property (nonatomic, strong) UIImage * image;
// 是否已上传
@property (nonatomic, assign) BOOL isUpload;

// 图片类型[new add]
@property (nonatomic, strong) NSString * format;
// 图片名称[new add]
@property (nonatomic, strong) NSString * fileName;

- (instancetype)initWithPicUrl:(NSString *)picUrl mediaId:(NSString *)mediaId;
- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

- (NSData *)getImageData;
- (NSString *)getFileName;
- (NSString *)getMimeType;

@end
