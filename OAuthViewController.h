//
//  OAuthViewController.h
//  OAuthOniPhone
//
//  Created by xu xhan on 5/20/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OAuthEngine.h"

@interface OAuthViewController : UIViewController<UIWebViewDelegate,UITextFieldDelegate,OAuthEngineDelegate> {
	OAuthEngine* _engine;
	UIWebView* _webView;
	UITextField* _textField;
	
}

@property (nonatomic, retain) IBOutlet UITextField *textField;

- (IBAction)onAuthorize;
- (IBAction)onTestUpdate;

@end

