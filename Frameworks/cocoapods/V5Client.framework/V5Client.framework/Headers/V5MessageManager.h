//
//  V5MessageManager.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/2.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Message.h"
#import "V5TextMessage.h"
#import "V5LocationMessage.h"
#import "V5ImageMessage.h"
#import "V5MusicMessage.h"
#import "V5VoiceMessage.h"
#import "V5VideoMessage.h"
#import "V5ControlMessage.h"
#import "V5ArticlesMessage.h"
#import "V5UndefinedMessage.h"

@interface V5MessageManager : NSObject

/**
 *  从字典构造消息对象
 *
 *  @param jsonData json
 *
 *  @return V5Message
 */
+ (V5Message *)receiveMessageFromJSON:(NSDictionary *)jsonData;

/**
 *  获得文本消息
 *
 *  @param content 文本内容
 *
 *  @return V5TextMessage
 */
+ (V5TextMessage *)obtainTextMessageWithContent:(NSString *)content;

/**
 *  获得位置消息
 *
 *  @param x     纬度
 *  @param y     经度
 *  @param scale 精度
 *  @param label 标签
 *
 *  @return V5LocationMessage
 */
+ (V5LocationMessage *)obtainLocationMessageWithX:(double)x
                                                y:(double)y
                                            scale:(double)scale
                                            label:(NSString *)label;

/**
 *  获得图片消息（URL方式）
 *
 *  @param picUrl  图片地址
 *  @param mediaId 媒体ID
 *
 *  @return V5ImageMessage
 */
+ (V5ImageMessage *)obtainImageMessageWithPicUrl:(NSString *)picUrl mediaId:(NSString *)mediaId;

/**
 *  获得图片消息（本地图片）
 *
 *  @param image UIImage
 *
 *  @return V5ImageMessage
 */
+ (V5ImageMessage *)obtainImageMessageWithImage:(UIImage *)image;

/**
 *  获得控制消息
 *
 *  @param code 控制码
 *  @param argc 参数数量
 *  @param argv 参数内容
 *
 *  @return V5ControlMessage
 */
+ (V5ControlMessage *)obtainControlMessageWithCode:(NSInteger)code
                                              argc:(NSInteger)argc
                                              argv:(NSString *)argv;

@end
