//
//  OAuthEngine.h
//  OAuthOniPhone
//
//  Created by xu xhan on 5/20/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OAuthConsumer.h"

// OAuth 1.0a add "oauth_verifier" at the last step of auth

@protocol OAuthEngineDelegate <NSObject>

@optional
- (void)OAuthEngineFailed:(NSData*)data;
- (void)OAuthEngineRequestTokenSuccess;
- (void)OAuthEngineAccessTokenSuccess;

@end



@interface OAuthEngine : NSObject {
	NSString	*_consumerSecret;
	NSString	*_consumerKey;
	NSURL		*_requestTokenURL;
	NSURL		*_accessTokenURL;
	NSURL		*_authorizeURL;	

	id<OAuthEngineDelegate> _delegate;
	OAConsumer	*_consumer;
	OAToken		*_requestToken;
	OAToken		*_accessToken; 	
	
}

@property (nonatomic, retain) OAToken *accessToken;
@property (nonatomic, retain) OAToken *requestToken;
@property (nonatomic, retain) OAConsumer *consumer;
@property (nonatomic, assign) id<OAuthEngineDelegate> delegate;
@property (nonatomic, retain) NSURL *authorizeURL;
@property (nonatomic, retain) NSURL *accessTokenURL;
@property (nonatomic, retain) NSURL *requestTokenURL;
@property (nonatomic, copy) NSString *consumerKey;
@property (nonatomic, copy) NSString *consumerSecret;

- (id)initWithConsumerKey:(NSString*)key Secret:(NSString*)secret RequestTokenURL:(NSString*)requestURLstr AuthorizeURL:(NSString*)authorizeURLstr AccessTokenURL:(NSString*)accessURLstr;

// 1.0
- (void) requestAccessToken;
// 1.0a
- (void) requestAccessTokenWithVerifier:(NSString*)verifier;
- (void) requestRequestToken;
- (void) requestAuthorizeAction;

- (NSURLRequest*)authorizeURLRequest;


@end


