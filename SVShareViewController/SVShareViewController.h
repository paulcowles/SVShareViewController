//
//  SVShareViewController.h
//
//  Created by Sam Vermette on 17.04.11.
//  Copyright 2010 Sam Vermette. All rights reserved.
//

#import <UIKit/UIKit.h>

enum SVShareType {
	SVShareTypeFacebook,
	SVShareTypeTwitter
};

typedef enum SVShareType SVShareType;

@protocol SVShareViewControllerDelegate;

@interface SVShareViewController : TTViewController <UIAlertViewDelegate, UITextViewDelegate> {
	IBOutlet UITextView *rTextView;
	IBOutlet UINavigationBar *navBar;
	IBOutlet UIToolbar *toolbar;
	IBOutlet UIImageView *logoView;
	IBOutlet UILabel *charLabel;
}

@property (nonatomic, assign) id<SVShareViewControllerDelegate> delegate;
@property (nonatomic, assign) NSString *userString;
@property (nonatomic, assign) NSString *defaultMessage;

- (SVShareViewController*)initWithShareType:(SVShareType)shareType;

- (IBAction)dismiss;
- (IBAction)logout;

@end


@protocol SVShareViewControllerDelegate
- (void)shareViewController:(SVShareViewController*)controller sendMessage:(NSString*)string forService:(SVShareType)shareType;
- (void)shareViewControllerDismissed:(SVShareViewController*)controller; 
@end
