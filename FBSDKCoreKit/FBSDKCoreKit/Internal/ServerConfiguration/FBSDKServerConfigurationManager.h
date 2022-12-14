/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <Foundation/Foundation.h>

#import "FBSDKServerConfiguration.h"

#define FBSDK_SERVER_CONFIGURATION_MANAGER_CACHE_TIMEOUT (60 * 60)

@protocol FBSDKGraphRequestFactory;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ServerConfigurationManager)
@interface FBSDKServerConfigurationManager : NSObject <FBSDKServerConfigurationProviding>

@property (class, readonly) FBSDKServerConfigurationManager *shared;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nullable, nonatomic) id<FBSDKGraphRequestFactory> graphRequestFactory;
@property (nullable, nonatomic) id<FBSDKGraphRequestConnectionFactory> graphRequestConnectionFactory;
@property (nullable, nonatomic) id<FBSDKDialogConfigurationMapBuilding> dialogConfigurationMapBuilder;

// UNCRUSTIFY_FORMAT_OFF
- (void)configureWithGraphRequestFactory:(id<FBSDKGraphRequestFactory>)graphRequestFactory
           graphRequestConnectionFactory:(id<FBSDKGraphRequestConnectionFactory>)graphRequestConnectionFactory
           dialogConfigurationMapBuilder:(id<FBSDKDialogConfigurationMapBuilding>)dialogConfigurationMapBuilder
  NS_SWIFT_NAME(configure(graphRequestFactory:graphRequestConnectionFactory:dialogConfigurationMapBuilder:));
// UNCRUSTIFY_FORMAT_ON

- (void)clearCache;

@end

NS_ASSUME_NONNULL_END
