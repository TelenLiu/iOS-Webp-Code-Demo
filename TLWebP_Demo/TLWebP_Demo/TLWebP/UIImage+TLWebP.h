//
//  UIImage+TLWebP.h
//  TLWebP_Demo
//
//  Created by telen on 16/7/16.  cccsee.cn
//  Copyright © 2016年 telen. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "./webp/webp/decode.h"
#include "./webp/webp/encode.h"

#define __isIpad_1x_To_iPhone_2x  0  //是否开启 1x to 2x
#define __isSupportSystemMethods  1  //是否开启 支持系统方法，（失败后，尝试webp加载）

/**
 * 说明  支持 系统原始访问 webp  需要开启上面宏   
 * 如果知道是 webp  建议直接调用，减少无畏的运算
 *
 
 * Demo中SDWebIamge，已经修改，只需配置在工程添加 SD_TLWEBP=1 （位置搜索“DEBUG=1”,上下都添加）
 
 * 如果要支持自己的SDWebImage,需要修改，UIImage+MultiFormat.m 中方法 如下
 
 #ifdef SD_TLWEBP
 else if ([imageContentType isEqualToString:@"image/webp"])
 {
 image = [UIImage tl_webpImageWithData:data];
 }
 #endif
 
 欢迎交流  
 博客： http://blog.cccsee.cn
 微博： http://weibo.com/telen
 github：https://github.com/Telenliu
 
 *
 */

@interface UIImage (TLWebP)

- (UIImage*)tl_imageByApplyingAlpha:(CGFloat)alpha;
//
+ (UIImage*)tl_webpImageWithData:(NSData *)data;
//
+ (UIImage*)tl_webpImageNamed:(NSString*)name;
//
+ (UIImage*)tl_webpImageFromFilePath:(NSString*)file;
//
#pragma mark-
+ (NSData*)tl_imageToWebP:(UIImage*)image quality:(CGFloat)quality;

+ (void)tl_imageToWebP:(UIImage*)image
            quality:(CGFloat)quality
              alpha:(CGFloat)alpha
             preset:(WebPPreset)preset
    completionBlock:(void (^)(NSData* result))completionBlock
       failureBlock:(void (^)(NSError* error))failureBlock;

+ (void)tl_imageToWebP:(UIImage*)image
            quality:(CGFloat)quality
              alpha:(CGFloat)alpha
             preset:(WebPPreset)preset
        configBlock:(void (^)(WebPConfig* config))configBlock
    completionBlock:(void (^)(NSData* result))completionBlock
       failureBlock:(void (^)(NSError* error))failureBlock;

+ (void)tl_imageWithWebP:(NSString*)filePath
      completionBlock:(void (^)(UIImage* result))completionBlock
         failureBlock:(void (^)(NSError* error))failureBlock;

@end


//支持系统方法直接调取
#if __isSupportSystemMethods
@interface UIImage (TLWebP_SystemMethods)
@end
#endif