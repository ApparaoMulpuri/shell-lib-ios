//
//  ScreenzSDKManager.h
//  ScreenzSDK
//
//  Created by Sebastian Castro on 2/10/16.
//  Copyright © 2016 Screenz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScreenzSDKConfigModel.h"
#import "ScreenzSDKAppConfigModel.h"
#import "ScreenzSDKServerDataModel.h"
#import "ScreenzSDKSchemeValues.h"

@import CoreLocation;

/**
 * This manager provides an unified entry point for the framework.
 * Was build to provide all the functionality for the framework and provide options to use it as a shared instance
 * accros the entire application, or to create multiple instance to handle different SDK intances independently.
 *
 * @author Sebastian Castro
 */

@interface ScreenzSDKManager : NSObject

@property (nonatomic,retain,readonly) ScreenzSDKAppConfigModel* appConfiguration;
@property (nonatomic,retain,readonly) ScreenzSDKConfigModel* sdkConfiguration;
@property (nonatomic,retain,readonly) ScreenzSDKServerDataModel* serverData;
@property (nonatomic,retain,readonly) ScreenzSDKSchemeValues* schemeValues;

@property (strong, nonatomic, readonly) NSString *carrier;
@property (strong, nonatomic, readonly) NSString *device;
@property (strong, nonatomic, readonly) NSString *language;
@property (strong, nonatomic) CLLocation *currentLocation;
@property (strong, nonatomic, readonly) NSString* udid;

/**
 * Get or create the current shared instance
 * @author Sebastian Castro
 *
 * @return The current instance
 */
+ (ScreenzSDKManager *)sharedInstance;

/**
 * Parse the JSON file and initialize configuration model.
 * @author Sebastian Castro
 *
 * @param fileName File name (with or without extension) of the JSON file (must be a .json file)
 * @return YES if the configuration is correctly loaded, NO on error (configuration set as nil)
 */
-(BOOL)loadConfigurationFromJSONFile:(NSString*)fileName;

/**
 * Parse the JSON string and initialize configuration model.
 * @author Sebastian Castro
 *
 * @param json string in JSON format
 * @return YES if the configuration is correctly loaded, NO on error (configuration set as nil)
 */
-(BOOL)loadConfigurationFromJSONString:(NSString*)json;

/**
 * Parse the JSON string and initialize server data model.
 * @author Sebastian Castro
 *
 * @param json string in JSON format
 * @return YES if model is correctly loaded, NO on error (model set as nil)
 */
-(BOOL)loadServerDataFromJSONString:(NSString*)json;

/**
 * Methods to handle push notifications
 */
-(void)receiveRemoteNotificationWithData:(NSDictionary *)userInfo applicationState:(UIApplicationState)appState completionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;
-(void)registerUserNotification;
-(void)registerForRemoteNotificationsWithToken:(NSData *)deviceToken;
-(void)failtRegisterForRemoteNotifications;

/**
 * Handle the open from url process within the app
 */
-(BOOL)processApplicaitonOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation configurationFile:(NSString*)configFile;

@end

