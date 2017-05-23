//
//  V5VoiceMessage.h
//  mcss
//
//  Created by chyrain on 16/4/11.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "V5Message.h"
#import <UIKit/UIKit.h>

@interface V5VoiceMessage : V5Message

// 语音格式
@property (nonatomic, strong) NSString * format;
// 媒体id
@property (nonatomic, strong) NSString * media_id;
// match
@property (nonatomic, assign) NSInteger match;

// 自定义
@property (nonatomic, assign) BOOL isUpload; // 是否已上传
@property (nonatomic, strong) NSString *url; // 上传后的URL
@property (nonatomic, strong) NSString *local_url; // 本地路径
@property (nonatomic, assign) CGFloat voiceLength; // 语音时长s
// 上传语音文件名[new add]
@property (nonatomic, strong) NSString * fileName;

- (instancetype)initWithFormat:(NSString *)format mediaId:(NSString *)mediaId url:(NSString *)url;
- (instancetype)initWithLocalURL:(NSString *)localPath format:(NSString *)format;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

- (NSData *)getVoiceData;
- (NSString *)getFileName;
- (NSString *)getDefaultURL;

- (BOOL)loadLocalVoice;

@end
