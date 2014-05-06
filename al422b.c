
/*
 * operation with RCK fall
 */


#define SW 100

#define CLK_UP    {P1OUT |=  RCK;}
#define CLK_DOWN  {P1OUT &= ~RCK;}

void AL422_read_reset(){
	
	CLK_UP;
	__delay_cycles(SW);
    P1OUT &= ~RRST;
	
	__delay_cycles(SW);
    CLK_DOWN;
	__delay_cycles(SW);
	CLK_UP;
	__delay_cycles(SW);
	CLK_DOWN;
	__delay_cycles(SW);
	CLK_UP;
	__delay_cycles(SW);
	CLK_DOWN;
	__delay_cycles(SW);
	
    P1OUT |= RRST;
	__delay_cycles(SW);
}


uint8_t AL422_read_byte(){
	
	uint8_t val;
	
	CLK_UP;
	__delay_cycles(SW);
	val = P2IN;
	CLK_DOWN;
	__delay_cycles(SW);

    return val;
}
