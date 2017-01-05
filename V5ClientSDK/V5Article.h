//
//  V5Article.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/3.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface V5Article : NSObject

// 标题
@property (nonatomic, strong) NSString * title;
// 图片URL
@property (nonatomic, strong) NSString * picUrl;
// 文章URL
@property (nonatomic, strong) NSString * url;
// 简述
@property (nonatomic, strong) NSString * desc;

- (instancetype)initWithTitle:(NSString *)title
                       picUrl:(NSString *)picUrl
                          url:(NSString *)url
                         desc:(NSString *)desc;
- (instancetype)initWithJSON:(NSDictionary *)data;
- (void)addPropertyToJSONObject:(NSMutableDictionary *)JSONObj;

@end
