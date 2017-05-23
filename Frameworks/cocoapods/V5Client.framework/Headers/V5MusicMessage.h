//
//  V5MusicMessage.h
//  mcss
//
//  Created by chyrain on 16/2/18.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "V5MediaMessage.h"

@interface V5MusicMessage : V5MediaMessage

// 标题
@property (nonatomic, strong) NSString *title;
// 描述
@property (nonatomic, strong) NSString *desc;
// 音乐URL
@property (nonatomic, strong) NSString * music_url;

// 高品质音频URL
@property (nonatomic, strong) NSString * hq_music_url;
// 图片媒体id
@property (nonatomic, strong) NSString * thumb_id;

- (instancetype)initWithTitle:(NSString *)title desc:(NSString *)desc url:(NSString *)url;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (NSString *)toJSONString;

@end
