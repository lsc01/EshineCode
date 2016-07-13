//
//  StoreAccount.h
//  jobCompany
//
//  Created by 陈广川 on 16/1/5.
//  Copyright © 2016年 liaolx. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void(^APGetDateBlock)(NSString *Acount,NSString *PassWord);
@interface AccountPasswordMannger : NSObject

+ (void)GetAccountAndPassword:(APGetDateBlock)DateBlock;

+ (void)SaveAccount:(NSString *)account andPassword:(NSString *)password;

+ (BOOL)ClearPassWord;

+(BOOL)DeletePassWithAcount:(NSString*)acount;

@end
