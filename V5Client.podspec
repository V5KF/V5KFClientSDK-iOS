Pod::Spec.new do |s|
  s.name             = "V5Client"
  s.version          = "1.3.0"
  s.summary          = "A customer service SDK for users of V5KF.COM used on iOS."
  s.description      = <<-DESC
                       It is a customer service SDK used on iOS, which implement by Objective-C. More info in http://ww.v5kf.com.
                       DESC
                       
  s.homepage         = "https://github.com/V5KF/V5KFClientSDK-iOS"
  s.license          = 'MIT'
  s.author           = { "Chyrain" => "chyrain_v5kf@qq.com" }
  s.source           = { :git => "https://github.com/V5KF/V5KFClientSDK-iOS.git", :tag => s.version }
  s.social_media_url = 'http://www.v5kf.com'

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  # s.ios.exclude_files = 'Classes/osx'
  # s.osx.exclude_files = 'Classes/ios'
  # s.public_header_files = 'Classes/**/*.h'
  s.frameworks = 'Foundation', 'AVFoundation', 'CoreTelephony', 'Security', 'AudioToolbox', 'CFNetwork', 'MediaPlayer'
  s.libraries = 'sqlite3', 'icucore', 'stdc++'
  s.vendored_frameworks = "Frameworks/cocoapods/V5Client.framework"

end