/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

/* FBSDKAuthenticationTokenStatusChecker_h */

#if !TARGET_OS_TV

#import <Foundation/Foundation.h>

#import <FBSDKCoreKit/FBSDKAccessTokenProviding.h>
#import <FBSDKCoreKit/FBSDKAuthenticationTokenProviding.h>
#import <FBSDKCoreKit_Basics/FBSDKCoreKit_Basics.h>

#import "FBSDKProfileProtocols.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AuthenticationStatusUtility)
@interface FBSDKAuthenticationStatusUtility : NSObject

@property (class, nullable, nonatomic) Class<FBSDKProfileProviding> profileSetter;
@property (class, nullable, nonatomic) id<FBSDKURLSessionProviding> sessionDataTaskProvider;
@property (class, nullable, nonatomic) Class<FBSDKAccessTokenProviding> accessTokenWallet;
@property (class, nullable, nonatomic) Class<FBSDKAuthenticationTokenProviding> authenticationTokenWallet;

/// Sets dependencies. This must be called during SDK initialization.
+ (void)configureWithProfileSetter:(Class<FBSDKProfileProviding>)profileSetter
           sessionDataTaskProvider:(id<FBSDKURLSessionProviding>)sessionDataTaskProvider
                 accessTokenWallet:(Class<FBSDKAccessTokenProviding>)accessTokenWallet
         authenticationTokenWallet:(Class<FBSDKAuthenticationTokenProviding>)authenticationWallet;

/**
 Fetches the latest authentication status from server. This will invalidate
  the current user session if the returned status is not authorized.
 */
+ (void)checkAuthenticationStatus;

#if DEBUG

+ (void)resetClassDependencies;

#endif

@end

NS_ASSUME_NONNULL_END

#endif
