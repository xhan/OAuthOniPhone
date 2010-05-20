//
//  OAuthOniPhoneAppDelegate.h
//  OAuthOniPhone
//
//  Created by xu xhan on 5/20/10.
//  Copyright xu han 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OAuthOniPhoneViewController;

@interface OAuthOniPhoneAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    OAuthOniPhoneViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet OAuthOniPhoneViewController *viewController;

@end

