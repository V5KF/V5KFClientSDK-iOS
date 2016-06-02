//
//  V5ChatViewController.h
//  V5KFClientTest
//
//  Created by V5KF_MBP on 15/12/18.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "V5Delegate.h"

@class V5ChatViewController;

@protocol V5ChatViewDelegate <NSObject>
@optional
/**
 *  即将打开会话视图
 */
- (void)clientViewWillAppear;

/**
 *  会话视图打开后
 */
- (void)clientViewDidAppear;

/**
 *  即将关闭会话视图
 */
- (void)clientViewWillDisappear;

/**
 *  关闭会话视图后
 */
- (void)clientViewDidDisappear;

/**
 *  客户端会话连接成功
 */
- (void)onClientViewConnect;

/**
 *  用户点击链接，包括普通URL(HTML超链接)、图文链接、电话号码
 *
 *  @param url      链接地址
 *  @param linkType 链接类型
 *
 *  @return 返回是否消费此事件
 */
- (BOOL)userClickLink:(NSString *)url linkType:(KV5LinkType)linkType;

/**
 *  用户点击位置消息
 *
 *  @param lat 纬度
 *  @param lng 经度
 *
 *  @return 返回是否消费此事件
 */
- (BOOL)userClickLocationWithLatitude:(double)lat longitude:(double)lng;

/**
 *  用户点击图片消息
 *
 *  @param image 图片
 *  @param url   图片链接
 * 
 *  @return 返回是否消费此事件
 */
- (BOOL)userClickImageWithImage:(UIImage *)image picUrl:(NSString *)url;

/**
 *  用户在会话视图中收到消息
 *
 *  @param message 消息对象
 */
- (void)clientDidReceiveMessage:(V5Message *)message;

/**
 *  用户将要发送消息
 *
 *  @param message 将要发送的消息(开发者可修改替换发送内容，消息类型和方向不可修改)
 *
 *  @return 修改处理过的消息
 */
- (V5Message *)userWillSendMessage:(V5Message *)message;

/**
 *  服务状态改变（正在排队、机器人服务、人工服务）
 *
 *  @param status KV5ClientServingStatus
 */
- (void)clientViewController:(V5ChatViewController *)chatVC ServingStatusChange:(KV5ClientServingStatus)status;

@end

@interface V5ChatViewController : UIViewController <V5MessageDelegate>

/**
 *  下方为界面基础功能参数，建议设置
 *
 */
//会话界面操作相关代理
@property (nonatomic, strong) id<V5ChatViewDelegate> delegate;

//设备唯一标识符。当视图控制器关闭，则将顾客离线并开启推送
@property (nonatomic, strong) NSString * deviceToken;

//系统提示音id
@property (nonatomic, assign) UInt32 soundID;
//来消息是否响铃
@property (nonatomic, assign) BOOL allowSound;
//每次下拉获取历史消息最大数量（默认10）
@property (nonatomic, assign) NSUInteger numOfMessagesOnRefresh;
//开场显示历史消息最大条数（默认0）
@property (nonatomic, assign) NSUInteger numOfMessagesOnOpen;
//是否允许发送语音（默认允许）
@property (nonatomic, assign) BOOL enableVoiceRecord;
//是否显示对话双方头像（默认显示）
@property (nonatomic, assign) BOOL showAvatar;
//头像圆角0～20(矩形－>圆形)
@property (nonatomic, assign) CGFloat avatarRadius;

/**
 *  下方为UI相关控件，可选择性修改界面参数，如背景色
 *  （请勿修改frame等信息）
 */
//气泡的容器是UITableView（请勿修改frame等信息）
@property (nonatomic, strong) UITableView *chatTableView;
//底部多功能输入栏（请勿修改frame等信息）
@property (nonatomic, strong) UIView *footerView;

/**
 *  设置开场方式与参数，需在进入会话前设置
 *
 *  @param mode  KV5ClientOpenMode
 *  @param patam 参数可为nil,当mode为ClientOpenModeCommand时不为nil
 */
- (void)setClientOpenMode:(KV5ClientOpenMode)mode withParam:(nullable NSString *)param;

@end
