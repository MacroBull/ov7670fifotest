/*
 * registers from: 
 * fuyuno sakura at http://mbed.org/users/mio/
 * Martin Smith at http://mbed.org/users/ms523/
 */

#ifndef __OV7670_H 
#define __OV7670_H

#define OV_GAIN        0x00    /* Gain lower 8 bits (rest in vref) */
#define OV_BLUE        0x01    /* blue gain */
#define OV_RED         0x02    /* red gain */
#define OV_VREF        0x03    /* Pieces of GAIN, VSTART, VSTOP */
#define OV_COM1        0x04    /* Control 1 */
#define OV_BAVE        0x05    /* U/B Average level */
#define OV_GbAVE       0x06    /* Y/Gb Average level */
#define OV_AECHH       0x07    /* AEC MS 5 bits */
#define OV_RAVE        0x08    /* V/R Average level */
#define OV_COM2        0x09    /* Control 2 */
#define OV_PID         0x0a    /* Product ID MSB */
#define OV_VER         0x0b    /* Product ID LSB */
#define OV_COM3        0x0c    /* Control 3 */
#define OV_COM4        0x0d    /* Control 4 */
#define OV_COM5        0x0e    /* All "reserved" */
#define OV_COM6        0x0f    /* Control 6 */

#define OV_AECH        0x10    /* More bits of AEC value */
#define OV_CLKRC       0x11    /* Clocl control */
#define OV_COM7        0x12    /* Control 7 */
#define OV_COM8        0x13    /* Control 8 */
#define OV_COM9        0x14    /* Control 9  - gain ceiling */
#define OV_COM10       0x15    /* Control 10 */
#define OV_HSTART      0x17    /* Horiz start high bits */
#define OV_HSTOP       0x18    /* Horiz stop high bits */
#define OV_VSTART      0x19    /* Vert start high bits */
#define OV_VSTOP       0x1a    /* Vert stop high bits */
#define OV_PSHFT       0x1b    /* Pixel delay after HREF */
#define OV_MIDH        0x1c    /* Manuf. ID high */
#define OV_MIDL        0x1d    /* Manuf. ID low */
#define OV_MVFP        0x1e    /* Mirror / vflip */

#define OV_ADDCTR0     0x20    /* ADC Control */
#define OV_AEW         0x24    /* AGC upper limit */
#define OV_AEB         0x25    /* AGC lower limit */
#define OV_VPT         0x26    /* AGC/AEC fast mode op region */
#define OV_BBIAS       0x27    /* B Channel Signal Output Bias (effective only when COM6[3] = 1) */
#define OV_GBBIAS      0x28    /* Gb Channel Signal Output Bias (effective only when COM6[3] = 1) */
#define OV_EXHCH       0x2a    /* Dummy Pixel Insert MSB */
#define OV_EXHCL       0x2b    /* Dummy Pixel Insert LSB */
#define OV_RBIAS       0x2c    /* R Channel Signal Output Bias (effective only when COM6[3] = 1) */
#define OV_ADVFL       0x2d    /* LSB of insert dummy lines in vertical direction */
#define OV_ADVFH       0x2e    /* MSB of insert dummy lines in vertical direction */
#define OV_YAVE        0x2e    /* Y/G Channel Average Value */

#define OV_HSYST       0x30    /* HSYNC rising edge delay */
#define OV_HSYEN       0x31    /* HSYNC falling edge delay */
#define OV_HREF        0x32    /* HREF pieces */
#define OV_ADC         0x37    /* ADC Control */
#define OV_TSLB        0x3a    /* lots of stuff */
#define OV_COM11       0x3b    /* Control 11 */
#define OV_COM12       0x3c    /* Control 12 */
#define CLK_SCALE      0x3f    /* Mask for internal clock scale */
#define OV_COM13       0x3d    /* Control 13 */
#define OV_COM14       0x3e    /* Control 14 */
#define OV_EDGE        0x3f    /* Edge enhancement factor */

#define OV_COM15       0x40    /* Control 15 */
#define OV_COM16       0x41    /* Control 16 */
#define OV_COM17       0x42    /* Control 17 */
#define OV_MTX1       0x4f    /* Matrix Coefficient 1*/


#define OV_BRIGHT      0x55    /* Brightness */
#define OV_CONTRAS     0x56    /* Contrast control */
#define OV_MTXS        0x58    /* Matrix Coefficient Sign for coefficient 5 to 0 */
#define OV_GFIX        0x69    /* Fix gain control */




#define COM1_CCIR656    0x40    /* CCIR656 enable */
#define COM2_SSLEEP     0x10    /* Soft sleep mode */
#define COM3_SWAP       0x40    /* Byte swap */
#define COM3_SCALEEN    0x08    /* Enable scaling */
#define COM3_DCWEN      0x04    /* Enable downsamp/crop/window */
#define CLK_EXT         0x40    /* Use external clock directly */
#define COM7_RESET      0x80    /* Register reset */
#define COM7_FMT_MASK   0x38
#define COM7_FMT_VGA    0x00
#define COM7_FMT_CIF    0x20    /* CIF format */
#define COM7_FMT_QVGA   0x10    /* QVGA format */
#define COM7_FMT_QCIF   0x08    /* QCIF format */
#define COM7_RGB        0x04    /* bits 0 and 2 - RGB format */
#define COM7_YUV        0x00    /* YUV */
#define COM7_BAYER      0x01    /* Bayer format */
#define COM7_PBAYER     0x05    /* "Processed bayer" */
#define COM8_FASTAEC    0x80    /* Enable fast AGC/AEC */
#define COM8_AECSTEP    0x40    /* Unlimited AEC step size */
#define COM8_BFILT      0x20    /* Band filter enable */
#define COM8_AGC        0x04    /* Auto gain enable */
#define COM8_AWB        0x02    /* White balance enable */
#define COM8_AEC        0x01    /* Auto exposure enable */
#define COM10_HSYNC     0x40    /* HSYNC instead of HREF */
#define COM10_PCLK_HB   0x20    /* Suppress PCLK on horiz blank */
#define COM10_HREF_REV  0x08    /* Reverse HREF */
#define COM10_VS_LEAD   0x04    /* VSYNC on clock leading edge */
#define COM10_VS_NEG    0x02    /* VSYNC negative */
#define COM10_HS_NEG    0x01    /* HSYNC negative */
#define MVFP_MIRROR     0x20    /* Mirror image */
#define MVFP_FLIP       0x10    /* Vertical flip */
#define TSLB_YLAST      0x04    /* UYVY or VYUY - see com13 */
#define COM11_NIGHT     0x80    /* NIght mode enable */
#define COM11_NMFR      0x60    /* Two bit NM frame rate */
#define COM11_HZAUTO    0x10    /* Auto detect 50/60 Hz */
#define COM11_50HZ      0x08    /* Manual 50Hz select */
#define COM11_EXP       0x02
#define COM12_HREF      0x80    /* HREF always */
#define COM13_GAMMA     0x80    /* Gamma enable */
#define COM13_UVSAT     0x40    /* UV saturation auto adjustment */
#define COM13_UVSWAP    0x01    /* V before U - w/TSLB */
#define COM14_DCWEN     0x10    /* DCW/PCLK-scale enable */
#define COM15_R10F0     0x00    /* Data range 10 to F0 */
#define COM15_R01FE     0x80    /*            01 to FE */
#define COM15_R00FF     0xc0    /*            00 to FF */
#define COM15_RGB565    0x10    /* RGB565 output */
#define COM15_RGB555    0x30    /* RGB555 output */
#define COM16_AWBGAIN   0x08    /* AWB gain enable */
#define COM17_AECWIN    0xc0    /* AEC window - must match COM4 */
#define COM17_CBAR      0x08    /* DSP Color bar */
#define CMATRIX_LEN 6
#define R76_BLKPCOR     0x80    /* Black pixel correction enable */
#define R76_WHTPCOR     0x40    /* White pixel correction enable */
#define R444_ENABLE     0x02    /* Turn on RGB444, overrides 5x5 */
#define R444_RGBX       0x01    /* Empty nibble at end */


#define OV_REG76       0x76    /* OV's name */
#define OV_RGB444      0x8c    /* RGB 444 control */
#define OV_HAECC1      0x9f    /* Hist AEC/AGC control 1 */
#define OV_HAECC2      0xa0    /* Hist AEC/AGC control 2 */
#define OV_BD50MAX     0xa5    /* 50hz banding step limit */
#define OV_HAECC3      0xa6    /* Hist AEC/AGC control 3 */
#define OV_HAECC4      0xa7    /* Hist AEC/AGC control 4 */
#define OV_HAECC5      0xa8    /* Hist AEC/AGC control 5 */
#define OV_HAECC6      0xa9    /* Hist AEC/AGC control 6 */
#define OV_HAECC7      0xaa    /* Hist AEC/AGC control 7 */
#define OV_BD60MAX     0xab    /* 60hz banding step limit */

#endif

