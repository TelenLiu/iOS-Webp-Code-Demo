//
//  ViewController.m
//  TLWebP_Demo
//
//  Created by telen on 16/7/16.
//  Copyright © 2016年 telen. All rights reserved.
//

#import "ViewController.h"
#import "UIImage+TLWebP.h"
#import "WebImage.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString* path = [[NSBundle mainBundle] pathForResource:@"bg.webp" ofType:nil];
    NSData* data = [NSData dataWithContentsOfFile:path];
    //UIImage* img = [UIImage imageWithData:data];
    UIImage* img = [[UIImage alloc] initWithContentsOfFile:path];
    //UIImage* img = [UIImage imageNamed:@"bg.webp"];
    UIImageView* imgv = [[UIImageView alloc] initWithImage:img];
    [self.view addSubview:imgv];
    
//    [imgv sd_setImageWithURL:[NSURL URLWithString:@"http://www.etherdream.com/WebP/Test.webp"] placeholderImage:img completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
//    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
