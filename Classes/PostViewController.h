#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <MapKit/MapKit.h>
#import "BlogDataManager.h"
#import "LocationController.h"
#import "PostMediaViewController.h"
#import "PostLocationViewController.h"
#import "WordPressAppDelegate.h"
#import "Post.h"
#import "TransparentToolbar.h"
#import "WPProgressHUD.h"

@class EditPostViewController, PostPreviewViewController, WPSelectionTableViewController, PostSettingsViewController, PostsViewController, CommentsViewController;
@class WPNavigationLeftButtonView, WPPublishOnEditController, CInvisibleToolbar, FlippingViewController;

@interface PostViewController : UIViewController <UITabBarDelegate, UIActionSheetDelegate, UITabBarControllerDelegate> {
	WordPressAppDelegate *appDelegate;

	EditPostViewController *postDetailViewController;
    EditPostViewController *postDetailEditController;
    PostPreviewViewController *postPreviewController;
    PostSettingsViewController *postSettingsController;
    PostMediaViewController *mediaViewController;
    PostsViewController *postsListController;
    CommentsViewController *commentsViewController;
    
    UIViewController *selectedViewController;
    WPNavigationLeftButtonView *leftView;
	WPProgressHUD *spinner;

    BOOL hasChanges, hasSaved, isVisible, isPublishing, isShowingKeyboard;
    EditPostMode editMode;
	NSURLConnection *connection;
	NSURLRequest *urlRequest;
	NSURLResponse *urlResponse;
	NSMutableData *payload;
	
	// iPad additions
	IBOutlet UIToolbar *toolbar;
	IBOutlet UIView *contentView;
	UIPopoverController *popoverController;
	UIPopoverController *photoPickerPopover;
	
    IBOutlet UITabBarController *tabController;
	IBOutlet UIBarButtonItem *commentsButton;
	IBOutlet UIBarButtonItem *photosButton;
	IBOutlet UIBarButtonItem *settingsButton;
	IBOutlet UIToolbar *editToolbar;
	IBOutlet UIToolbar *previewToolbar;
	IBOutlet UIBarButtonItem *cancelEditButton;
}

@property (nonatomic, retain) WPNavigationLeftButtonView *leftView;
@property (nonatomic, retain) EditPostViewController *postDetailViewController;
@property (nonatomic, retain) IBOutlet EditPostViewController *postDetailEditController;
@property (nonatomic, retain) IBOutlet PostPreviewViewController *postPreviewController;
@property (nonatomic, retain) IBOutlet PostSettingsViewController *postSettingsController;
@property (nonatomic, retain) IBOutlet PostMediaViewController *mediaViewController;
@property (nonatomic, retain) IBOutlet CommentsViewController *commentsViewController;
@property (nonatomic, assign) PostsViewController *postsListController;
@property (nonatomic, assign) UIViewController *selectedViewController;
@property (nonatomic, assign) BOOL hasChanges, hasSaved, isVisible, isPublishing;
@property (nonatomic, assign) BOOL isShowingKeyboard;
@property (nonatomic, assign) EditPostMode editMode;
@property (readonly) UITabBarController *tabController;
@property (nonatomic, retain) IBOutlet UIToolbar *toolbar;
@property (nonatomic, retain) IBOutlet UIView *contentView;
@property (nonatomic, retain) IBOutlet UIBarButtonItem *commentsButton;
@property (nonatomic, retain) IBOutlet UIBarButtonItem *photosButton;
@property (nonatomic, retain) IBOutlet UIBarButtonItem *settingsButton;
@property (nonatomic, retain) IBOutlet UIToolbar *editToolbar;
@property (nonatomic, retain) IBOutlet UIBarButtonItem *cancelEditButton;
@property (nonatomic, assign) UIBarButtonItem *leftBarButtonItemForEditPost;
@property (nonatomic, retain) Post *post;
@property (nonatomic, retain) NSURLConnection *connection;
@property (nonatomic, retain) NSURLRequest *urlRequest;
@property (nonatomic, retain) NSURLResponse *urlResponse;
@property (nonatomic, retain) NSMutableData *payload;
@property (nonatomic, retain) WordPressAppDelegate *appDelegate;
@property (nonatomic, retain) WPProgressHUD *spinner;

- (IBAction)cancelView:(id)sender;
- (void)refreshUIForCompose;
- (void)refreshUIForCurrentPost;
- (void)updatePhotosBadge;
- (UINavigationItem *)navigationItemForEditPost;
- (IBAction)editAction:(id)sender;
- (void)publish:(id)sender;
- (IBAction)saveAsDraft;
- (void)saveAsDraft:(BOOL)andDiscard;
- (IBAction)locationAction:(id)sender;
- (void)dismissEditView;
- (void)verifyPublishSuccessful;
- (void)stop;
- (void)setMode:(EditPostMode)newMode;
- (void)refreshButtons;
- (void)showError;
@end
