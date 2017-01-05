//
//  V5KFDefination.h
//  V5KFClientSDK
//
//  Created by V5KF_MBP on 15/11/30.
//  Copyright © 2015年 V5KF. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  消息方向枚举
 */
typedef NS_ENUM(NSInteger, KV5MessageDir) {
    // 坐席发给客户
    MessageDir_ToCustomer = 0,
    // 客户发出
    MessageDir_ToWorker = 1,
    // 机器人发给客户
    MessageDir_FromRobot = 2,
    // 相关问题
    MessageDir_RelativeQuestion = 8,
    // 评价消息
    MessageDir_Comment = 9
};

/**
 *  消息类型枚举
 */
typedef NS_ENUM(NSInteger, KV5MessageType) {
    // 文本
    MessageType_Text = 1,
    // 图片
    MessageType_Image = 2,
    // 位置
    MessageType_Location = 3,
    // 链接
    MessageType_Link = 4,
    // 事件
    MessageType_Event = 5,
    // 语音
    MessageType_Voice = 6,
    // 视频
    MessageType_Video = 7,
    // 短视频
    MessageType_ShortVideo = 8,
    // 图文
    MessageType_Articles = 9,
    // 音乐
    MessageType_Music = 10,
    // 切换微信客服
    MessageType_WXCS = 11,
    // 第三方URL
    MessageType_APPUrl = 22,
    // 评价
    MessageType_Comment = 23,
    // 留言
    MessageType_Note = 24,
    // 控制消息
    MessageType_Control = 25
};

/**
 *  消息发送状态枚举
 */
typedef NS_ENUM(NSInteger, KV5MessageSendStatus) {
    // 未发送、未知
    MessageSendStatus_Unknown = 0,
    // 已送达
    MessageSendStatus_Arrived = 1,
    // 发送失败
    MessageSendStatus_Failure = 2,
    // 发送中
    MessageSendStatus_Sending = 3
};

/**
 *  问题命中与否
 */
typedef NS_ENUM(NSInteger, KV5QuestionHitState) {
    // 未命中
    QuestionHitState_None = 0,
    // 命中
    QuestionHitState_Ok = 1
};

/**
 *  链接类型枚举
 */
typedef NS_ENUM(NSInteger, KV5LinkType) {
    // URL链接
    LinkTypeURL = 0,
    // 图文链接
    LinkTypeArticle = 1,
    // 电话号码
    LinkTypePhoneNumber = 2
};

/**
 * 异常或错误。没有异常时返回0
 */
typedef NS_ENUM(NSInteger, KV5ExceptionStatus) {
    Exception_No_Error = 0,      // 没有错误
    //Exception_Error_Parameter,          // 参数错误
    
    /* 初始化相关的错误 */
    Exception_Init_Param_Invalid,       // 初始化参数无效
    //Exception_Init_AppKey_Invalid,      // appkey无效
    Exception_Init_Failed,              // 初始化中出现错误
    Exception_NotInitialized,           // SDK未初始化
    
    Exception_Account_Failed,           // 账号信息认证失败，未返回Authorization
    Exception_NotConnected,             // 尚未建立连接
    
    Exception_Message_SendFailed,       // 消息发送失败
    Exception_Image_UploadFailed,       // 图片上传失败
    Exception_No_Network,               // 没有网络
    Exception_Connection_Timeout,       // 连接超时
    Exception_Connection_Error,         // 网络请求错误
    //Exception_User_IsOffline,           // 顾客为离线状态，当前操作无法操作
    //Exception_ServiceError,             // 服务器出错
    
    Exception_WSAuth_Failed,            // ws的Authorization认证失败
    
    Exception_UnknownError,             // 未知错误
    
    // 服务端返回码
    Exception_Server_50001 = 50001,     // 50001 - 无效的方法(GET/POST/PUT)
    Exception_Server_50002 = 50002,     // 50002 - 无效参数
    Exception_Server_50003 = 50003,     // 50003 - 无效账号
    Exception_Server_50004 = 50004,     // 50004 - 账号被禁止
    Exception_Server_50005 = 50005,     // 50005 - 错误的请求域
    Exception_Server_50006 = 50006,     // 50006 - 内部错误
    Exception_Server_50007 = 50007,     // 50007 - 请求URL错误
    Exception_Server_50008 = 50008,     // 50008 - 请求超时
    Exception_Server_50009 = 50009,     // 50009 - 请求数据错误
    Exception_Server_50010 = 50010,     // 50010 - 会话结束关闭
    Exception_Server_50011 = 50011      // 50011 - 无效会话ID
};

typedef NS_ENUM(NSInteger, KV5ClientOpenMode) {
    ClientOpenModeDefault = 0,          // 默认开场方式（无消息记录显示默认开场白，带参则参数作为开场白，否则显示历史消息）
    ClientOpenModeQuestion = 1,         // 自定义开场白，设置开场问题获得对应开场白
    ClientOpenModeNone = 2,             // 无开场白方式，有则显示历史消息
    ClientOpenModeAutoHuman = 3         // 开场自动转人工客服
};

typedef NS_ENUM(NSInteger, KV5ClientServingStatus) {
    ServingStatus_robot = 0,            // 机器人服务
    ServingStatus_queue = 1,            // 排队(转人工，等待人工客服接入中，当前为机器人服务)
    ServingStatus_worker = 2,           // 人工服务
    ServingStatus_inTrust = 3           // 人工交给机器人托管
};
