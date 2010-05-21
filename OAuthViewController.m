//
//  OAuthViewController.m
//  OAuthOniPhone
//
//  Created by xu xhan on 5/20/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import "OAuthViewController.h"


@implementation OAuthViewController

@synthesize textField = _textField;

- (IBAction)onAuthorize
{
//	NSLog(@"%@",_textField.text);
	[_textField resignFirstResponder];
	[_engine requestAccessTokenWithVerifier:_textField.text];
}

- (IBAction)onTestUpdate
{
	[_engine requestAccessToken];
}


- (void)viewDidLoad {
    [super viewDidLoad];
	NSLog(@"loaded");
	_engine = [[OAuthEngine alloc] initWithConsumerKey:@"117701862"
												Secret:@"b83db63d8ac0256918b0bdaaaacec0d7"
									   RequestTokenURL:@"http://api.t.sina.com.cn/oauth/request_token"
										  AuthorizeURL:@"http://api.t.sina.com.cn/oauth/authorize"
										AccessTokenURL:@"http://api.t.sina.com.cn/oauth/access_token"];
	_engine.delegate = self;
	[_engine requestRequestToken];
}


- (void)OAuthEngineFailed:(NSData*)data
{
	NSLog(@"failed: %@",data);
}

- (void)OAuthEngineRequestTokenSuccess
{
	_webView = [[UIWebView alloc] initWithFrame:CGRectMake(10, 50, 300, 300)];
	[_webView loadRequest:[_engine authorizeURLRequest]];
	[self.view addSubview:_webView];
}

- (void)OAuthEngineAccessTokenSuccess
{
	NSLog(@"success access");
}




- (void)dealloc {
    [_textField release], _textField = nil;
    [super dealloc];
}


@end

