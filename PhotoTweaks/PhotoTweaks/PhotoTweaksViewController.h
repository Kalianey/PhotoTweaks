//
//  PhotoTweaksViewController.h
//  PhotoTweaks
//
//  Created by Tu You on 14/12/5.
//  Copyright (c) 2014年 Tu You. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PhotoTweakView;

@protocol PhotoTweaksViewControllerDelegate;

/**
 The photo tweaks controller.
 */
@interface PhotoTweaksViewController : UIViewController


/**
 IBOUTLETS
 
 */
@property (unsafe_unretained, nonatomic) IBOutlet UIButton *cancelBtn;
@property (weak, nonatomic) IBOutlet UIButton *cropBtn;
@property (weak, nonatomic) IBOutlet PhotoTweakView *photoView;
@property (nonatomic, assign) CGSize cropSize;

- (IBAction)cancelBtnTapped;
- (IBAction)saveBtnTapped;


/**
 Image to process.
 */
@property (nonatomic, strong) UIImage *image;

/**
 Flag indicating whether the image cropped will be saved to photo library automatically. Defaults to YES.
 */
@property (nonatomic, assign) BOOL autoSaveToLibray;

/**
 The optional photo tweaks controller delegate.
 */
@property (nonatomic, weak) id<PhotoTweaksViewControllerDelegate> delegate;

/**
    save action button's default title color
 */
@property (nonatomic, strong) UIColor *saveButtonTitleColor;

/**
    save action button's highlight title color
 */
@property (nonatomic, strong) UIColor *saveButtonHighlightTitleColor;

/**
 cancel action button's default title color
 */
@property (nonatomic, strong) UIColor *cancelButtonTitleColor;

/**
 cancel action button's highlight title color
 */
@property (nonatomic, strong) UIColor *cancelButtonHighlightTitleColor;

/**
 Option to turn on/off crop size adjustment.
 */
@property (nonatomic, assign) BOOL allowCropEditing;

/**
 Creates a photo tweaks view controller with the image to process.
 @param cropsize defines the default frame of the crop frames.
 */
- (instancetype)initWithImage:(UIImage *)image withCropSize:(CGSize )cropSize;

@end






/**
 The photo tweaks controller delegate
 */
@protocol PhotoTweaksViewControllerDelegate <NSObject>

/**
 Called on image cropped.
 */
- (void)photoTweaksController:(PhotoTweaksViewController *)controller didFinishWithCroppedImage:(UIImage *)croppedImage;
/**
 Called on cropping image canceled
 */
- (void)photoTweaksControllerDidCancel:(PhotoTweaksViewController *)controller;

@end
