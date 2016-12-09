//
//  NSMutableDictionary+ValueForNil.m
//  给字典添加分类判断传入的值是否为nil
//
//  Created by lsc on 16/12/9.
//  Copyright © 2016年 eshine_lsc. All rights reserved.
//

#import "NSMutableDictionary+ValueForNil.h"
#import <objc/runtime.h>  
@implementation NSMutableDictionary (ValueForNil)

+ (void)load {
    
    Method fromMethod = class_getInstanceMethod(objc_getClass("__NSDictionaryM"), @selector(setObject:forKey:));
    Method toMethod = class_getInstanceMethod(objc_getClass("__NSDictionaryM"), @selector(em_setObject:forKey:));
    method_exchangeImplementations(fromMethod, toMethod);
}

- (void)em_setObject:(id)emObject forKey:(NSString *)key {
    if (emObject == nil) {
        @try {
            [self em_setObject:emObject forKey:key];
        }
        @catch (NSException *exception) {
            NSLog(@"--有字典设置value为nil--")
//            NSLog(@"---------- %s Crash Because Method %s  ----------\n", class_getName(self.class), __func__);
//            NSLog(@"%@", [exception callStackSymbols]);
            emObject = [NSString stringWithFormat:@""];
            [self em_setObject:emObject forKey:key];
        }
        @finally {}
    }else {
        [self em_setObject:emObject forKey:key];
    }
}

@end
