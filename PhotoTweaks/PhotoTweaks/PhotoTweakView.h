//
//  PhotoView.h
//  PhotoTweaks
//
//  Created by Tu You on 14/12/2.
//  Copyright (c) 2014年 Tu You. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CropView;
@class PhotoScrollView;

@interface PhotoContentView : UIView

@property (strong, nonatomic) UIImageView *imageView;
@property (strong, nonatomic) UIImage *image;

@end

@protocol CropViewDelegate <NSObject>

- (void)cropEnded:(CropView *)cropView;
- (void)cropMoved:(CropView *)cropView;

@end

@interface CropView : UIView
@property (nonatomic, assign) BOOL allowEditing;
-(void)setupCropView;
@end

@interface PhotoTweakView : UIView

@property (strong, nonatomic) IBOutlet PhotoContentView *photoContentView;
@property (strong, nonatomic) IBOutlet CropView *cropView;
@property (unsafe_unretained, nonatomic) IBOutlet PhotoScrollView *scrollView;

@property (nonatomic, strong, setter=setImage:) UIImage *image;
@property (nonatomic, strong) IBOutlet UISlider *slider;
@property (nonatomic, strong) IBOutlet UIButton *resetBtn;

@property (assign, nonatomic) CGFloat angle;
@property (assign, nonatomic) CGPoint photoContentOffset;
@property (assign, nonatomic) BOOL allowCropEditing;

- (instancetype)initWithFrame:(CGRect)frame image:(UIImage *)image cropSize:(CGSize)cropSize;
- (CGPoint)photoTranslation;

- (IBAction)sliderValueChanged:(id)sender;
- (IBAction)sliderTouchEnded:(id)sender;
- (IBAction)resetBtnTapped:(id)sender;


@end
