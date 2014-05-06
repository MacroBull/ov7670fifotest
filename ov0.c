
#include <msp430.h>
#include "dev.h"
#include "ov7670.h"
#include "misc.h"
#include "i2c.h"
#include "uart.h"
#include "qput.h"


#define VSYNC   BIT0 // P1.0
#define RRST    BIT3 // P1.3 (note: on launchpad P1.3 has a debouncing cap)
#define RCK    BIT4 // P1.4
#define WE     BIT5 // P1.5

//#include "ov7670.c"
#include "al422b.c"


void puti(int i){
	qputc(_USCI_UART0, i >> 8);
	qputc(_USCI_UART0, i & 0xff);
}

void init_rgb565_qvga_25fps_new(){
	
	char tmp0, tmp1;
	tmp0 = USCI_I2C_reg8_read8(_USCI_I2C0, OV_PID);
	tmp1 = USCI_I2C_reg8_read8(_USCI_I2C0, OV_VER);
	
	qputs(_USCI_UART0, "PID_VER=");
	qputh(_USCI_UART0, tmp0);
	qputh(_USCI_UART0, tmp1);
	qputs(_USCI_UART0, ";\n");
	
	
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x12, 0x80);
	__delay_cycles(400000);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x11, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x92, 0x7f);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x93, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x9d, 0x9e);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x3b, 0x0a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x13, 0xf2);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x10, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x00, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x01, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x02, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x13, 0xd7);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x12, 0x14);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x04, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x18, 0x4b);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x17, 0x23);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x32, 0xbf);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x19, 0x02);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x1a, 0x7a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x03, 0x00);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x0e, 0x84);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x0f, 0x62);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x15, 0x02);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x16, 0x02);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x1b, 0x01);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x1e, 0x01);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x29, 0x3c);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x33, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x34, 0x07);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x35, 0x84);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x36, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x38, 0x13);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x39, 0x43);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x3a, 0x00);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x3c, 0x6c);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x3d, 0x90);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x3f, 0x29);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x40, 0xd1);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x41, 0x20);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x6b, 0x0a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0xa1, 0xc8);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x69, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x43, 0xf0);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x44, 0x10);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x45, 0x78);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x46, 0xa8);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x47, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x48, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x59, 0xba);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5a, 0x9a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5b, 0x22);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5c, 0xb9);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5d, 0x9b);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5e, 0x10);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x5f, 0xe0);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x60, 0x85);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x61, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x9f, 0x9d);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0xa0, 0xa0);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x4f, 0xae);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x50, 0x26);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x51, 0x08);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x52, 0x1a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x53, 0xa9);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x54, 0x0f);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x55, 0x05);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x56, 0x46);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x57, 0xcb);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x58, 0x77);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x8b, 0xcc);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x8c, 0xcc);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x8d, 0xcf);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x6c, 0x40);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x6d, 0x30);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x6e, 0x4b);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x6f, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x70, 0x70);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x71, 0x70);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x72, 0x70);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x73, 0x70);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x74, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x75, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x76, 0x50);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x77, 0x48);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x78, 0x3a);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x79, 0x2e);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7a, 0x28);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7b, 0x22);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7c, 0x04);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7d, 0x07);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7e, 0x10);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x7f, 0x28);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x80, 0x36);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x81, 0x44);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x82, 0x52);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x83, 0x60);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x84, 0x6c);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x85, 0x78);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x86, 0x8c);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x87, 0x9e);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x88, 0xbb);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x89, 0xd2);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x8a, 0xe6);
	//
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x14, 0x2e);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x24, 0xb8);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x25, 0xa8);
}

void OV_init(){
	
	char tmp0, tmp1;
	tmp0 = USCI_I2C_reg8_read8(_USCI_I2C0, OV_PID);
	tmp1 = USCI_I2C_reg8_read8(_USCI_I2C0, OV_VER);
	
	qputs(_USCI_UART0, "PID_VER=");
	qputh(_USCI_UART0, tmp0);
	qputh(_USCI_UART0, tmp1);
	qputs(_USCI_UART0, ";\n");
	
	USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM7, 0x80);
	
	qputs(_USCI_UART0, "Reseted\n");
	
	USCI_I2C_reg8_write8(_USCI_I2C0, OV_CLKRC, 0x80);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM11, 0x0A);
	
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_TSLB, 0x04); // ???
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_TSLB, 0x04);
	
	qputs(_USCI_UART0, "Clock set\n");
	
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM7, 0x04); /* output format: rgb */
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_RGB444, 0x00); /* disable RGB444 */ // ???
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM15, 0xD0); /* set RGB565 + full range */
	qputs(_USCI_UART0, "RGB565 set\n");
	
	
    /* not even sure what all these do, gonna check the oscilloscope and go
     * from there... */
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_HSTART, 0x16);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_HSTOP, 0x04);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_HREF, 0x24);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_VSTART, 0x02);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_VSTOP, 0x7a);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_VREF, 0x0a);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM10, 0x02);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM3, 0x04);
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_MVFP, 0x3f);
	qputs(_USCI_UART0, "Frame set\n");
    /* 160x120, i think */
    //USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM14, 0x1a); // divide by 4
    //USCI_I2C_reg8_write8(_USCI_I2C0, 0x72, 0x22); // downsample by 4
    //USCI_I2C_reg8_write8(_USCI_I2C0, 0x73, 0xf2); // divide by 4

    /* 320x240: */
    USCI_I2C_reg8_write8(_USCI_I2C0, OV_COM14, 0x19);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x72, 0x11);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x73, 0xf1);
	qputs(_USCI_UART0, "Scale set\n");
    // test pattern
    //USCI_I2C_reg8_write8(_USCI_I2C0, 0x70, 0xf0);
    //USCI_I2C_reg8_write8(_USCI_I2C0, 0x71, 0xf0);

    // COLOR SETTING
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x4f, 0x80);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x50, 0x80);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x51, 0x00);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x52, 0x22);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x53, 0x5e);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x54, 0x80);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x56, 0x40);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x58, 0x9e);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x59, 0x88);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x5a, 0x88);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x5b, 0x44);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x5c, 0x67);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x5d, 0x49);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x5e, 0x0e);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x69, 0x00);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6a, 0x40);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6b, 0x0a);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6c, 0x0a);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6d, 0x55);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6e, 0x11);
    USCI_I2C_reg8_write8(_USCI_I2C0, 0x6f, 0x9f);

    USCI_I2C_reg8_write8(_USCI_I2C0, 0xb0, 0x84);
	qputs(_USCI_UART0, "Color set\n");

	
	qputs(_USCI_UART0, "Init done!\n");
}


void ov7670_capture(){
	
    /* Capture frame */
    while ((P1IN & VSYNC));     // wait for an old frame to end
    while (!(P1IN & VSYNC));    // wait for a new frame to start
    P1OUT |= WE;               // enable writing to fifo
	//P1OUT &= ~WE;
    while ((P1IN & VSYNC));     // wait for the current frame to end
    P1OUT &= ~WE;              // disable writing to fifo
	//P1OUT |= WE;
    __delay_cycles(1600000);
    P1OUT |= RRST;
}



void main(){
	
	WDT_disable;

	#define FCPU 16000000
	BC16MSET;
	
	//P1DIR |= WE + RRST + RCK;
	P1DIR |= WE + RRST + RCK;
    P1DIR &= ~VSYNC;
	P2SEL = P2SEL2 = 0;
    P2DIR = 0;

    P1OUT |= RRST;
    P1OUT &= ~RCK;
	
	USCI_UART_init(_USCI_UART0, FCPU, 115200);
	qputs(_USCI_UART0, "Init...\n");
	
	//USCI_I2C_XLED_enable(_USCI_I2C0);
	USCI_I2C_slave_addr_setter(_USCI_I2C0, 0x21); 
	USCI_I2C_init(_USCI_I2C0, FCPU, 400000, 1);
	
	//init_rgb565_qvga_25fps_new();
	OV_init();
	
	int i,j,k;
	uint32_t l;
	
	while (1){
		qputs(_USCI_UART0, "Capture!\n");
		ov7670_capture();
		qputs(_USCI_UART0, "Captured, read;\n");
		AL422_read_reset();
		for (i = 0;i<120;i++){
		for (l = 0;l<320;l++){
			qputc(_USCI_UART0,AL422_read_byte());
		}
		}
		//qputs(_USCI_UART0, "\n");
		__delay_cycles(8000000);
		
	}
}
