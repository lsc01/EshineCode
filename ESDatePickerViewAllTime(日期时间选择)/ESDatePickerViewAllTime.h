//
//  ESDatePickerView.h
//  ESDatePickerViewDemo
//
//  Created by eshine_lsc on 16/7/7.
//  Copyright © 2016年 eshine_lsc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ESDatePickerViewAllTimeDelegate <NSObject>

/**
 *  日期选择代理方法
 *
 *  @param date 日期字符串
 */
-(void)ESDPGetYear:(NSString *)year month:(NSString *)month day:(NSString *)day hour:(NSString *)hour minute:(NSString *)minute second:(NSString *)second;

@end

@interface ESDatePickerViewAllTime : UIView

@property(nonatomic,assign)id<ESDatePickerViewAllTimeDelegate> delegate;


@end
