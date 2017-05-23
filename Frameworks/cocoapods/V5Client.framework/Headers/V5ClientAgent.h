//
//  V5ClientAgent.h
//  V5KFClientSDK
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
typedef void (^V5InitExceptionBlock)(KV5ExceptionStatus status, NSString * _Nullable desc);

NS_ASSUME_NONNULL_BEGIN
@class V5SRWebSocket;
@interface V5ClientAgent : NSObject

@property (nullable, nonatomic, strong) V5Config * config;
@property (nonatomic, weak) id<V5MessageDelegate> messageDelegate;
@property (nullable, nonatomic, strong) V5SRWebSocket *webSocket;
@property (nonatomic, assign, getter=isConnected) BOOL connected;

@property (nonatomic, assign, getter=isPhotoLibrary) BOOL photoLibrary; // 打开图库标识，用于控制屏幕方向
@property (nonatomic, assign) NSUInteger photoLibraryInterfaceOrientations; // 图库屏幕方向

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
 *  @param block    异常回调block
 */
+ (void)initWithSiteId:(NSString * _Nonnull)siteId
               account:(NSString * _Nullable)account
                 appId:(NSString * _Nonnull)appId
     exceptionBlock:(nullable V5InitExceptionBlock)block DEPRECATED_MSG_ATTRIBUTE("此方法将被废弃,不再需要account参数,请使用不带account参数的init方法代替");

/**
 *  初始化SDK
 *
 *  @param siteId   站点编号
 *  @param block    异常回调block
 */
+ (void)initWithSiteId:(NSString * _Nonnull)siteId
                 appId:(NSString * _Nonnull)appId
        exceptionBlock:(nullable V5InitExceptionBlock)block;

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
 *  添加自定义客户信息键值对
 *
 *  @param info NSDictionary
 *      示例：
 *          @{@"用户等级": @"VIP",
 *          @"用户积分": @"300",
 *          @"商品名称": @"牛仔裤",
 *          @"商品价格": @"¥168.00"}
 */
- (void)addUserInfo:(NSDictionary * _Nonnull)info;

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
 *  @param param 参数可为nil,当mode为ClientOpenModeCommand时不为nil
 */
- (void)getOpeningMessageOfMode:(KV5ClientOpenMode)mode withParam:(nullable NSString *)param;

/**
 *  更新站点信息：机器人name、头像等信息
 */
- (void)updateSiteInfo;

@end

NS_ASSUME_NONNULL_END
