//
//  ViewController.m
//  ClientDemo
//
//  Created by chyrain on 16/1/13.
//  Copyright © 2016年 V5KF. All rights reserved.
//

#import "ViewController.h"
#import "V5ClientAgent.h"

@interface ViewController () <V5ChatViewDelegate> {
    BOOL userViewSomething;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)clickStartClient:(id)sender {
    /**
     * 下面为会话界面配置选项，注释的为非必须
     */
    
    /**
     * 下面为会话界面配置选项，注释的为非必须
     */
    
    // 获得V5ClientAgent配置项
    V5Config *config = [V5ClientAgent shareClient].config;
    
    // 用户信息单次设置即生效，更新用户信息或者切换用户时需调用shouldUpdateUserInfo,然后再设置uid切换访客
    //[config shouldUpdateUserInfo];
    
    // 设置用户信息，坐席端可查看
    config.nickname = @"iso-sdk-test－李四";
    config.gender = 1; //性别：0-未知 1－男 2－女
    config.avatar = @"http://tcdn21.wn517.com/dev/avatar/nl2fci00fzwpx6m4o2xi.jpg@0o_0l_64w_90q_1pr.jpg"; //客户头像URL
    config.uid = @"ios-customer-id-for-test"; //用户唯一ID,不同的uid消息记录单独保存
    
    V5ChatViewController *chatViewController = [V5ClientAgent createChatViewController];
    // 不显示底部栏（有底部栏的需加此配置）
    chatViewController.hidesBottomBarWhenPushed = YES;
    // 会话界面的代理
    chatViewController.delegate = self;
    //chatViewController.deviceToken = @"设备的deviceToken"; // 也可在config设置deviceToken
    // 允许并设置消息铃声SystemSoundID
    chatViewController.allowSound = YES;
    chatViewController.soundID = 1007;
    // 允许发送语音
    chatViewController.enableVoiceRecord = YES;
    // 允许显示头像
    chatViewController.showAvatar = YES;
    // 头像圆角
    chatViewController.avatarRadius = 6;
    
    // 每次下拉获取历史消息最大数量，默认10
    //chatViewController.numOfMessagesOnRefresh = 10;
    // 开场显示历史消息数量，默认10（显示历史消息>0则无开场白）
    chatViewController.numOfMessagesOnOpen = 10;
    
    // 设置会话界面标题
    chatViewController.title = @"V5客服"; // 设置标题，默认@“小五”
    // 设置返回按钮标题（默认为前一页面标题）
    UIBarButtonItem *myBackItem = [[UIBarButtonItem alloc] init];
    myBackItem.title = @"返回";
    self.navigationItem.backBarButtonItem = myBackItem;
    
    // 设置开场白方式,启动会话前设置，默认ClientOpenModeDefault
    // ClientOpenModeQuestion结合后台机器人培训内容可根据使用场景配置不同需求的开场消息
    //[chatViewController setClientOpenMode:ClientOpenModeDefault withParam:nil];
    
    // 修改对话界面UI属性
    // 对话列表背景色
    //chatViewController.chatTableView.backgroundColor = [UIColor groupTableViewBackgroundColor];
    
    // 启动会话界面，使用导航模式推出视图
    [self.navigationController pushViewController:chatViewController animated:YES];

}

#pragma mark - V5ChatViewDelegate
/**
 *  即将打开会话视图
 */
- (void)clientViewWillAppear {
    NSLog(@"<--- clientViewWillAppear --->");
}

/**
 *  会话视图打开后
 */
- (void)clientViewDidAppear {
    NSLog(@"<--- clientViewDidAppear --->");
}

/**
 *  即将关闭会话视图
 */
- (void)clientViewWillDisappear {
    NSLog(@"<--- clientViewWillDisappear --->");
}

/**
 *  关闭会话视图后
 */
- (void)clientViewDidDisappear {
    NSLog(@"<--- clientViewDidDisappear --->");
}

/**
 *  会话连接成功
 */
- (void)onClientViewConnect {
    NSLog(@"<--- onClientViewConnect --->");
    
    // 连接建立后找指定客服
    //[[V5ClientAgent shareClient] humanServiceOfGroupId:1 workerId:114052];
}

/**
 *  用户点击链接，包括普通URL(HTML超链接)、图文链接、电话号码
 *
 *  @param url 链接地址
 */
//- (void)userClickLink:(NSString *)url linkType:(KV5LinkType)linkType {
//    NSLog(@"<--- userClickLink:%@ --->", url);
//    //可以跳转到你自己的WebView界面打开链接内容
//}

/**
 *  用户点击位置消息
 *
 *  @param lat 纬度
 *  @param lng 经度
 */
//- (void)userClickLocationWithLatitude:(double)lat longitude:(double)lng {
//    NSLog(@"<--- userClickLocationWithLat:%lf lng:%lf --->", lat, lng);
//    //可以跳转到你自己的位置查看页面
//}

/**
 *  用户点击图片消息
 *
 *  @param image 图片
 *  @param url   图片链接
 */
//- (void)userClickImageWithImage:(UIImage *)image picUrl:(NSString *)url {
//    NSLog(@"<--- userClickImageWithImage:%@ --->", url);
//    //可以跳转到你自己的图片查看界面
//}

/**
 *  用户在会话视图中收到消息
 *
 *  @param message 消息对象
 */
- (void)clientDidReceiveMessage:(V5Message *)message {
    NSLog(@"<--- clientDidReceiveMessage:%@ --->", [message getDefaultContent]);
    //在这里可以处理接收消息的额外行为，比如通知震动等
}

/**
 *  用户将要发送消息
 *
 *  @param message 将要发送的消息(开发者可修改替换发送内容，消息类型和方向不可修改)
 *
 *  @return 修改处理过的消息
 */
- (V5Message *)userWillSendMessage:(V5Message *)message {
    NSLog(@"<--- userWillSendMessage:%@ --->", [message getDefaultContent]);
    if (userViewSomething) { //用户浏览某商品
        message.customContent = @{@"用户等级": @"VIP",
                                  @"用户积分": @"300",
                                  @"商品名称": @"牛仔裤",
                                  @"商品价格": @"¥168.00"};
        userViewSomething = NO; //标识置为NO，单条消息有效
    }
    return message;
}

/**
 *  客户服务状态改变(可在此相应改变对话页标题)
 *
 *  @param status KV5ClientServingStatus
 */
- (void)clientViewController:(V5ChatViewController *)chatVC ServingStatusChange:(KV5ClientServingStatus)status {
    switch (status) {
        case ServingStatus_queue: // 正在排队等待人工，当前为机器人服务
        case ServingStatus_robot: // 机器人服务中
            chatVC.title = @"机器人服务中";
            break;
        case ServingStatus_worker:
            chatVC.title = [V5ClientAgent shareClient].config.workerName; // 当前正在服务的坐席名
            break;
        default:
            break;
    }
}

@end
