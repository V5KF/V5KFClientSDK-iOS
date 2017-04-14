//
//  V5Delegate.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/12/10.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import "V5Defination.h"
#import "V5Message.h"

@protocol V5ExpcetionDelegate <NSObject>
@optional

/**
 * 发生异常
 * @param status 异常类型
 * @param description 异常描述
 */
- (void)initExpcetionStatus:(KV5ExceptionStatus)status desc:(NSString *)description;
@end


@protocol V5MessageDelegate <NSObject>

/**
 * 收到即时消息
 * @param message 消息对象，元素为V5Message类型
 */
- (void)receiveV5Message:(V5Message *)message;

/**
 * 收到即时消息--JSON字符串(接口扩展预留)
 * @param json JSON字符串消息，元素为NSString类型
 */
- (void)receiveJSONString:(NSString *)json;


@optional
/**
 *  连接建立成功
 */
- (void)onConnect;
/**
 *  连接建立成功,并返回获取到的未读消息
 */
- (void)onConnectWithUnreadCount:(NSInteger)count;

/**
 *  链接断开
 */
- (void)disconnectWithCode:(NSInteger)code reason:(NSString *)reason;

/**
 *  收到异常信息
 *
 *  @param status      异常类型
 *  @param description 异常描述
 */
- (void)receiveExceptionStatus:(KV5ExceptionStatus)status desc:(NSString *)description;

/**
 * 发送消息结果
 * @param message 发送后的消息（包含该消息当前发送状态）
 * @param expcetion 失败原因（如果为0，则代表发送成功）
 */
- (void)sendMessageResult:(V5Message*)message expcetion:(KV5ExceptionStatus)expcetion;

/**
 *  获取消息记录完成
 *
 *  @param messages  消息数组，元素为V5Message类型
 *  @param offset    起始位置
 *  @param size      返回消息最大数量
 *  @param finish    是否获取完全部消息
 *  @param expcetion 异常类型
 */
- (void)getMessagesResult:(NSArray<V5Message *> *)messages
                   offset:(NSInteger)offset
                     size:(NSInteger)size
                   finish:(bool)finish
                expcetion:(KV5ExceptionStatus)expcetion;

/**
 *  客户服务状态改变
 *
 *  @param status KV5ClientServingStatus
 */
- (void)servingStatusChange:(KV5ClientServingStatus)status;

@end


