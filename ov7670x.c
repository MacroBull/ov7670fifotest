//#include "ov7670.h"
#include "ov7670reg.h"

void OV7670_write_frame(){
	
    /* Capture frame */
    while ((P1IN & VSYNC));     // wait for an old frame to end
    while (!(P1IN & VSYNC));    // wait for a new frame to start
    P1OUT |= WE;               // enable writing to fifo
	
	//P1OUT &= ~WE;
    while ((P1IN & VSYNC));     // wait for the current frame to end
	
	__delay_cycles(100);
    P1OUT &= ~WE;              // disable writing to fifo
	//P1OUT |= WE;
    
}

void OV7670_check_version(){
	
	char tmp0, tmp1;
	tmp0 = USCI_I2C_reg8_read8(_USCI_I2C0, 0x0a);
	tmp1 = USCI_I2C_reg8_read8(_USCI_I2C0, 0x0b);
	
	qputs(_USCI_UART0, "PID_VER=");
	qputh(_USCI_UART0, tmp0);
	qputh(_USCI_UART0, tmp1);
	qputs(_USCI_UART0, ";\n");
	
	

}

void ov7670_init()
{
	
	
	//USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM7, 0x80); /* reset to default values */
	
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_CLKRC, 0x80);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM11, 0x0A);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_TSLB, 0x04);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_TSLB, 0x04);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM7, 0x04); /* output format: rgb */
	
	
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_RGB444, 0x00); /* disable RGB444 */
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM15, 0xD0); /* set RGB565 */
	
	/* not even sure what all these do, gonna check the oscilloscope and go
	 * from there... */
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_HSTART, 0x16);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_HSTOP, 0x04);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_HREF, 0x24);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_VSTART, 0x02);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_VSTOP, 0x7a);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_VREF, 0x0a);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM10, 0x02);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM3, 0x04);
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_MVFP, 0x3f);
	
	/* 160x120, i think */
	//USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM14, 0x1a); // divide by 4
	//USCI_I2C_reg8_write8(_USCI_I2C0, 0x72, 0x22); // downsample by 4
	//USCI_I2C_reg8_write8(_USCI_I2C0, 0x73, 0xf2); // divide by 4
	
	/* 320x240: */
	USCI_I2C_reg8_write8(_USCI_I2C0, REG_COM14, 0x19);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x72, 0x11);
	USCI_I2C_reg8_write8(_USCI_I2C0, 0x73, 0xf1);
	
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
	
}
