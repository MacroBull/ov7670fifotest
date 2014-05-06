
#include <msp430.h>
#include "dev.h"
#include "misc.h"
#include "i2c.h"
#include "uart.h"
#include "qput.h"

/*input*/
#define VSYNC   BIT0

/*output*/
#define RRST   BIT3
#define RCK    BIT4
#define WE     BIT5


#include "al422b.c"
#include "ov7670x.c"

uint16_t w,h;
char rbuff[7], cnt;

int rv(uint16_t iv, char c){
	rbuff[cnt] = c -'0';
	cnt++;
	
	
	if (cnt==7){
		return -CPUOFF;
	}
	else {
		
		qputc(_USCI_UART0, c);
		return 0;
	}
	
}

void main(){
	
	WDT_disable;

	#define FCPU 16000000
	BC16MSET;
	
	_USCI_UART0->XLED_PORT_OUT = (addr)P3OUT_;
	_USCI_I2C0->XLED_PORT_OUT = (addr)P3OUT_;
	
    P1DIR &= ~VSYNC;
	P1DIR |= WE + RRST + RCK;
	P2SEL = P2SEL2 = 0;
    P2DIR = 0;

    P1OUT |= RRST;
	P1OUT &= ~WE;
    P1OUT &= ~RCK;
	
	uart_register(_USCI_UART0, 1);
	USCI_UART_init(_USCI_UART0, FCPU, 115200);
	USCI_UART_ISR_setter(_USCI_UART0, rv);
	qputs(_USCI_UART0, "Init I2C..\n");
	
	//USCI_I2C_XLED_enable(_USCI_I2C0);
	USCI_I2C_slave_addr_setter(_USCI_I2C0, 0x21); 
	USCI_I2C_init(_USCI_I2C0, FCPU, 400000, 1);
	
	qputs(_USCI_UART0, "Init done...\n");
	OV7670_check_version();
	
	//init_rgb565_qvga_25fps_new();
	ov7670_init();
	//OV_init();
	
	
	qputs(_USCI_UART0, "GG!\n");
	
	int i,j,k;
	//uint32_t l;
	
	
	while (1){
		OV7670_write_frame();
		qputs(_USCI_UART0, "Captured\n");
		AL422_read_reset();
		qputs(_USCI_UART0, "READY\n");
		cnt = 0;
		__bis_SR_register(CPUOFF);
		w = rbuff[0]*100+rbuff[1]*10+rbuff[2];
		h = rbuff[4]*100+rbuff[5]*10+rbuff[6];
		
		for (i = 0;i<h;i++){
			for (j = 0;j<w*2;j++){
				qputc(_USCI_UART0, AL422_read_byte());
			}
		}
		//qputs(_USCI_UART0, "\n");
		//__delay_cycles(8000000);
		
	}
	
}
