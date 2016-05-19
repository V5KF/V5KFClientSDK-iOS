//
//  V5ClientAgent.h
//  V5KFClientTest
//
//  Created by V5KF_MBP on 15/12/10.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Delegate.h"
#import "V5Config.h"
#import "V5Delegate.h"
#import "V5ChatViewController.h"
#import "V5MessageManager.h"
#import <Systemconfiguration/SystemConfiguration.h>
#import <Mobilecoreservices/MobileCoreServices.h>

#define _AFNETWORKING_ALLOW_INVALID_SSL_CERTIFICATES_

NS_ASSUME_NONNULL_BEGIN

@interface V5ClientAgent : NSObject

@property (nullable, nonatomic, strong) V5Config * config;
@property (nonatomic, assign, getter=isConnected) BOOL connected;

/**
 *  单例对象获取
 *
 *  @return V5ClientAgent对象
 */
+ (instancetype _Nonnull)shareClient;

/**
 *  单例对象销毁(慎用，除非程序退出)
 */
+ (void)destroyDealloc;

/**
 *  当前版本号
 *
 *  @return 版本号NSString
 */
+ (nullable NSString *)version;

/**
 *  初始化SDK
 *
 *  @param siteId   站点编号
 *  @param account  应用账号
 *  @param delegate 异常代理
 */
+ (void)initWithSiteId:(nullable NSString *)siteId
               account:(nullable NSString *)account
     exceptionDelegate:(nullable id<V5ExpcetionDelegate>)delegate;

/**
 *  开启消息服务(账号认证->参数保存->建立连接)
 *
 *  @param delegate 消息代理
 */
- (void)startClientWithDelegate:(id<V5MessageDelegate> _Nonnull)delegate;

/**
 *  关闭消息服务以节省资源(配置推送仍可接收推送通知)
 */
- (void)stopClient;

/**
 *  发送V5Message消息
 *
 *  @param message V5Message消息对象
 */
- (void)sendMessage:(V5Message * _Nonnull)message;

/**
 *  连接检查并重连
 */
- (void)checkConnect;

/**
 *  刷新消息(用于从后台或其他界面回到会话时主动刷新消息)
 *  已在onApplicationWillEnterForeground内有执行
 */
- (void)refresh;

/**
 *  发送文本消息
 *
 *  @param content 文本消息
 */
- (V5TextMessage *)sendTextMessageWithContent:(NSString *)content;

/**
 *  发送本地图片
 *
 *  @param image 图片
 */
- (V5ImageMessage *)sendImageMessageWithImage:(UIImage *)image;

/**
 *  获取消息记录，获取结果通过getMessagesResult:offset:size:finish:expcetion:
 *  回调返回，参数offset和size均为0时为查询会话全部消息,消息数量较多尽量分页查询
 *
 *  @param offset 请求消息的起始位置
 *  @param size   最多返回消息数
 */
- (void)getMessagesWithOffset:(NSInteger)offset messageSize:(NSInteger)size;

/**
 *  清空历史消息缓存
 */
- (void)clearMessagesCache;

/**
 *  清空语音图片等媒体缓存
 */
+ (void)clearMediaCache;

/**
 *  找指定客服
 *
 *  @param gid 客服组ID，无分组则为0
 *  @param wid 客服ID
 */
- (void)humanServiceOfGroupId:(NSInteger)gid workerId:(NSInteger)wid;

/**
 *  转人工客服
 */
- (V5ControlMessage *)switchToArtificialService;

/**
 *  上线，开启在线对话
 */
- (void)shouldClientOnline;

/**
 *  下线，进入离线推送
 */
- (void)shouldClientOffline;

/**
 *  应用进入后台
 */
- (void)onApplicationDidEnterBackground;

/**
 *  应用进入前台
 */
- (void)onApplicationWillEnterForeground;

/**
 *  创建会话界面(使用navigationController pushViewController启动界面)
 *
 *  @return V5ChatViewController
 */
+ (V5ChatViewController * _Nonnull)createChatViewController;

/**
 *  获得开场消息
 *
 *  @param mode  KV5ClientOpenMode 开场白模式
 *  @param patam 参数可为nil,当mode为ClientOpenModeCommand时不为nil
 */
- (void)getOpeningMessageOfMode:(KV5ClientOpenMode)mode withParam:(nullable NSString *)param;

@end

NS_ASSUME_NONNULL_END
