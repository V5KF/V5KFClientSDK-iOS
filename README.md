
# V5KFClientSDK-iOS
> 此为V5KF智能客服iOS客户端SDK快速接入文档，包含接入客服系统的基本配置和代码接口，更全面详细的文档可参考[这里](./README.full.md)

## 1 开发环境准备

1. V5KF客服系统账号
> 没有 V5KF 账号需要前往[官网](http://www.v5kf.com)注册账号。

2. 获得应用账号、站点编号
> 应用账号、站点编号作为 SDK 连接服务端的身份凭证，可登录V5KF管理后台在 "系统接入" -> "移动应用APP" 配置界面获取。

3. 填写对应平台的推送服务器地址(非必需)
> 为了使您的 APP 在集成本 SDK 后具有离线消息推送，建议填写您的推送服务器地址，同时也支持第三方推送平台，需要按照本文档规定填写您的 device_token 和绑定的用户 ID。

4. 下载 SDK
> 您可以到 V5KF 官网或者[V5KF Github](https://github.com/V5KF/V5KFClientSDK-iOS)*(建议)*页下载智能客服 SDK，包含了开发包和带 UI 界面的 Demo 示例工程，使用CocoaPods导入则可不用下载。

5. 环境要求
> 在您集成智能客服 SDK 前环境要求如下:
	- 支持的最低版本 iOS 8.0。
	- 支持 ARC 的 Xcode 编译器，建议使用最新版本。

## 2 SDK导入

### 2.1 Objective-C项目

把V5ClientSDK 文件夹拷贝到您的工程路径下面，然后在工程目录结构中，右键选择 *Add Files to “工程名”* 。或者将这个文件夹拖入 Xcode 工程目录结构中，并选择Create groups。

### 2.2 Swift项目

* 按照上面的方法引入`V5ClientSDK`的文件。
* 在 Bridging Header 头文件中，加入`#import “V5ClientAgent.h”`等相关头文件。注：[如何添加 Bridging Header](http://bencoding.com/2015/04/15/adding-a-swift-bridge-header-manually/)。

> 注：此SDK为Objective-C开发，可能存在不适用swift的情况

### 2.3 引入依赖库

V5Client的实现依赖了一些系统框架，在开发应用时，要在工程里加入这些框架。开发者首先点击工程右边的工程名，然后在工程名右边依次选择 *TARGETS* -> *General* -> *Linked Frameworks and Libraries*，展开 *Linked Frameworks and Libraries* 后点击展开后下面的 *+* 来添加下面的依赖项:

- libsqlite3.tbd
- libicucore.tbd
- stdc++.tbd
- AVFoundation.framework
- AudioToolbox.framework
- CFNetwork.framework
- Security.framework
- MediaPlayer.framework

### 2.4 CocoaPods导入
使用CocoaPods管理依赖库的可以更方便的导入SDK。只需要在 `Podfile` 中加入（此处导入的SDK为静态库，动态库请参考[2.5](#25-动态库)）：

```
platform :ios, '7.0'

pod 'V5ClientSDK'
```

接着pod安装 即可：

	$ pod install

有新版本更新时：

	$ pod update V5ClientSDK

如果运行以上命令，没有搜到或者搜不到最新版本，您可以运行以下命令，更新一下您本地的 CocoaPods 源列表：

	pod repo update  

### 2.5 动态库

为应对不断发展的开发需求，本SDK自1.2.7版本开始提供动态库解决方案，命名为`V5Client.framework`，并支持使用Cocoapods和Carthage导入，静态库版本亦会继续支持。

#### 使用CocoaPods导入

```
platform :ios, '8.0'
use_frameworks!

target 'ClientDemo' do
  pod 'V5Client'
end
```

target那里的`ClientDemo`改为你的target

#### 使用Carthage引入

```
github "V5KF/V5KFClientSDK-iOS"
```

然后把`Carthage/Build/iOS/V5Client.framework`拖入项目配置的`General`->`Embedded Binaries`，并选择`Copy items if needed`

## 3 Info.plist配置

### 3.1 ATS

由于 iOS 9 的新特性默认使用 `ATS`，所有网络请求都需要在安全的连接下(当前 App Store 尚未强制使用iOS 9这一新特性)，所以一些不兼容的服务需要进行额外的配置，本SDK使用到了语音和图片服务的 webservice 接口，需在 `Info.plist` 添加下述配置:

```
<key>NSAppTransportSecurity</key> 
	<dict>
		<key>NSAllowsArbitraryLoads</key>
       <true/>
    </dict>
```

关于这一特性的详细说明和解决方案可参考:
[https://github.com/ChenYilong/iOS9AdaptationTips](https://github.com/ChenYilong/iOS9AdaptationTips)

**注:** 本SDK 1.1.10 以上版本已完全兼容 `HTTPS`，若无特殊需求，无需配置此 ATS 项， 可直接采用 https 方式连接，SDK 默认会将访问的网络图片(比如用户头像)和其他网络请 求进行自动转为 `https` 方式访问，若目标站点未支持 https 仍需要 http 访问，可通过设置` [V5ClientAgent shareClient].config.autoSSL = NO `来取消自动转 `https`，并自行配置好对应的 `ATS` 选项。

### 3.2 权限
由于 SDK 中使用到相册和相机，在 Info.plist 中需要加入以下内容: (文中以 XML 格式描述)

```
<key>NSPhotoLibraryUsageDescription</key> 
<string>Choose photo</string> 
<key>NSCameraUsageDescription</key> 
<string>Take pictures</string>
<key>NSMicrophoneUsageDescription</key>
<string>Record voice</string>
```

## 4 SDK接口快速集成

### 4.1 初始化SDK

将SDK文件添加到工程后，在`AppDelegate`中`import “V5ClientAgent.h“`文件，然后在`application: willFinishLaunchingWithOptions:`函数中初始化 SDK 。示例如下:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch. 
    // 初始化SDK
    [V5ClientAgent initWithSiteId:@"10000"
                            appId:@"19cfb0800f474"
                   exceptionBlock:nil];
    return YES;
}
```
其中 `siteId` 和 `account` 分别是从 V5 后台可以获取到的站点编号和AppID。
![SDK后台配置](./pictures/ios_sdk_6.png)

### 4.2 用户信息和参数设置
使用 SDK 提供的 UI 集成，需要在**启动会话界面之前**进行用户信息和参数配置。配置项如下:

```objective-c
//需要#import "V5ClientAgent.h"
//获得V5ClientAgent配置对象
V5Config *config = [V5ClientAgent shareClient].config;
//设置用户信息，坐席端可查看
config.nickname = @"test-张三";
config.gender = 1; //性别:0-未知 1-男 2-女
config.avatar = @"头像URL"; //客户头像URL
//openId:用户唯一ID,长度32字节以内,不同的openId消息记录单独保存,可透传到座席端提供给座席插件,替代v1.2.0之前版本的uid（uid不再使用）
//若您是旧版本SDK用户，只是想升级，为兼容旧版，避免客户信息改变可继续使用config.uid，可不用openId
config.openId = @"ios-user-id-for-test";
// 注：openId尽量不要携带特殊字符（$&+,/:;=?@%#[]以及空格之类的字符），若包含则会经过urlencode编码，客席插件收到这样的oid后要相应的解码处理(decodeURIComponent)
// 添加自定义用户信息NSDictionary,(仅在开启对话页面前设置生效)
config.userInfo = @{@"商品名称": @"牛仔裤", 
					@"商品价格": @"¥168.00"};

//用户信息单次设置即生效，更新用户信息或者切换用户时需调用shouldUpdateUserInfo 
//[config shouldUpdateUserInfo];
```

当 `nickname`、`openId`、`avatar`、`device_token` 等配置项配置完，下次需要修改(如App内切换了登录账号，修改了客户昵称或头像时)并向座席更新时需要在开启会话前调用 **`[config shouldUpdateUserInfo]`**，这样才会向服务端更新这几个配置项。
同样若想更新站点信息（站点信息包含机器人信息和转人工开场白等V5后台可设置的信息，系统会隔7天自动更新，一般无需处理），需要在`onChatActivityConnect`中调用 **`[[V5ClientAgent shareClient] updateSiteInfo]`**。

### 4.3 启动会话界面

通过简单地添加一个在线咨询按钮即可使用智能客服客户端功能，在按钮点击事件处理中加入启动会话界面的代码:

```objective-c
V5ChatViewController *chatViewController = [V5ClientAgent createChatViewController];
// 不显示底部栏(有底部栏的需加此配置) 
chatViewController.hidesBottomBarWhenPushed = YES;

/* 下面为会话界面配置，非必须，可根据需求自定义配置，均有默认值 */
// 会话界面的代理V5ChatViewDelegate
//chatViewController.delegate = self; 
// 设备的ID(也可在config设置deviceToken),有选择推送功能的需要配置
// chatViewController.deviceToken = @"设备的deviceToken";
// 允许并设置消息铃声SystemSoundID 
chatViewController.allowSound = YES; 
chatViewController.soundID = 1007;
// 允许发送语音 
chatViewController.enableVoiceRecord = YES; 
// 允许显示头像
chatViewController.showAvatar = YES;
// 头像圆角(0~20之间)
chatViewController.avatarRadius = 6;
// 每次下拉获取历史消息最大数量，默认10 
chatViewController.numOfMessagesOnRefresh = 10;
// 开场显示历史消息数量，默认0(显示历史消息>0则无开场白)
chatViewController.numOfMessagesOnOpen = 10;
// 设置会话界面标题
chatViewController.title = @"V5客服"; // 设置标题
// 设置返回按钮标题(默认为前一页面标题)
UIBarButtonItem *myBackItem = [[UIBarButtonItem alloc] init]; 
myBackItem.title = @"返回";
self.navigationItem.backBarButtonItem = myBackItem;
// 设置开场白方式,启动会话前设置，默认ClientOpenModeDefault
// ClientOpenModeQuestion结合后台机器人培训内容可根据使用场景配置不同需求的开场消息
[chatViewController setClientOpenMode:ClientOpenModeDefault withParam:nil];

// 启动会话界面，使用导航模式推出视图
[self.navigationController pushViewController:(UIViewController *)chatViewController animated:YES];
```


如果SDK使用在iPad里，启动会话界面可采用`UIPopoverPresentationController`方式，以及限制横屏状态的处理方式，具体配置如下：

```objective-c
// 页面呈现方式presentType默认PresentType_Push, PopoverViewController下改为PresentType_Popover
chatViewController.presentType = PresentType_Popover;
chatViewController.view.transform = CGAffineTransformMakeScale(0.8, 0.8); //缩小页面内容

//使用UIPopoverPresentationController开启对话
chatViewController.modalPresentationStyle = UIModalPresentationPopover;
chatViewController.preferredContentSize = CGSizeMake(400, 500);
UIPopoverPresentationController* popover = chatViewController.popoverPresentationController;
//设置弹出的基准视图
popover.sourceView = self.button;
popover.sourceRect = self.button.bounds;//打开页面的入口按钮的bunds
popover.delegate = self;
[self presentViewController:chatViewController animated:YES completion:nil];

// 或者使用`UIPopoverController`，iOS9.0以后不再建议使用
// UIPopoverController* popover = [[UIPopoverController alloc] initWithContentViewController:chatViewController];
// [popover setBackgroundColor:[UIColor colorWithRed:235.0/255 green:235.0/255 blue:235.0/255 alpha:1]];
// popover.popoverContentSize = CGSizeMake(chatViewController.view.frame.size.width, chatViewController.view.frame.size.height);
// [popover presentPopoverFromRect:CGRectMake(0,618,1024,50) inView:self.view permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];

/* 需要手动控制屏幕方向时使用，比如iPad横屏情况 */
// 需要**限制横屏**打开时(UIInterfaceOrientationMaskLandscape)，为解决发送图片时选择图库打开页面异常问题，需要在AppDelegate做如下处理
- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    if ([V5ClientAgent shareClient].isPhotoLibrary) { //必须,否则打开图库异常
        return UIInterfaceOrientationMaskAll;
    } else {
        return UIInterfaceOrientationMaskLandscape;//or UIInterfaceOrientationMaskAll 允许全部屏幕方向
    }
}
```

### 4.4 生命周期处理
在使用 UI 集成的 SDK 中，**【必须】**在 `AppDelegate` 中添加下面代码:
	
```objective-c
- (void)applicationDidEnterBackground:(UIApplication *)application {
	//退出到后台时，通知 SDK 用户离线
	[[V5ClientAgent shareClient] onApplicationDidEnterBackground]; 
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
	//移动到前台时，通知 SDK 用户上线并连接
	[[V5ClientAgent shareClient] onApplicationWillEnterForeground];
}
```

此外，不使用客服功能时需要关闭会话服务以节省资源并避免客户离线的状态未更新到座席（已配置离线推送情况下还会影响消息推送）。在使用导航模式`pushViewController`方式打开时，页面返回时SDK内置V5ChatViewController会**自动调用**`[[V5ClientAgent shareClient] stopClient]`关闭会话服务，则无须参考以下内容，若开启页面的方式不是push或者修改了导航栏返回按钮，则必须**【手动调用】**来关闭会话。

下面列举几种需要手动关闭会话的情况：

> 修改或自定义了导航栏按钮或使用present弹出页面的，在开启会话界面的前一个界面的 `viewDidAppear:`方法中手动调用关闭客服的方法:

```objective-c
- (void)viewDidAppear:(BOOL)animated { // 前一 viewController 中 
  // 不使用客服功能时(在会话 VC 关闭后)退出消息客户端 
  if ([V5ClientAgent shareClient].isConnected) {
    [[V5ClientAgent shareClient] stopClient];
  }
}
```

> 以`UIPopoverPresentationController`方式打开的，则需要通过实现`UIPopoverPresentationControllerDelegate`的`popoverPresentationControllerDidDismissPopover:`来调用`[[V5ClientAgent shareClient] stopClient];`:

```objective-c
- (void)popoverPresentationControllerDidDismissPopover:(UIPopoverPresentationController *)popoverPresentationController {
    // 不使用客服功能时(在会话 VC 关闭后)退出消息客户端 
    if ([V5ClientAgent shareClient].isConnected) {
        [[V5ClientAgent shareClient] stopClient];
    }
}
```

> 此外，使用`UIPopoverController`或者其他方式开启的也是同理，需要手动关闭会话。

