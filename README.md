# V5KFClientSDK-iOS
V5KF客服SDK iOS

### iOS10兼容
由于SDK中使用到相册和相机，在Info.plist中需要加入以下内容:
(Version Editor模式):

```
	<key>NSPhotoLibraryUsageDescription</key>
	<string>Choose photo</string>
	<key>NSCameraUsageDescription</key>
	<string>Take pictures</string>
```

## V5智能客服 SDK 导入

### Objective-C 项目

把V5ClientSDK 文件夹拷贝到您的工程路径下面，然后在工程目录结构中，右键选择 *Add Files to “工程名”* 。或者将这个文件夹拖入 Xcode 工程目录结构中，并选择Create groups。

### Swift 项目

* 按照上面的方法引入V5ClientSDK 的文件。
* 在 Bridging Header 头文件中，加入`#import “V5ClientAgent.h”`等相关头文件。注：[如何添加 Bridging Header](http://bencoding.com/2015/04/15/adding-a-swift-bridge-header-manually/)。

## 引入依赖库

V5Client的实现依赖了一些系统框架，在开发应用时，要在工程里加入这些框架。开发者首先点击工程右边的工程名,然后在工程名右边依次选择 *TARGETS* -> *BuiLd Phases* -> *Link Binary With Libraries*，展开 *LinkBinary With Libraries* 后点击展开后下面的 *+* 来添加下面的依赖项:

- libsqlite3.tbd
- libicucore.tbd
- stdc++.tbd
- AVFoundation.framework
- CoreTelephony.framework
- AudioToolbox.framework
- CFNetwork.framework
- Security.framework
- MediaPlayer.framework

# CocoaPods 导入

在 Podfile 中加入：

```
platform :ios, '7.0'

pod 'V5ClientSDK', '~> 1.1.8'
```

接着pod安装 即可：

```
$ pod install
```
