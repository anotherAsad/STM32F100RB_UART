// arm-none-eabi-gcc -S -mcpu=cortex-m3 -mthumb -O0 code.c -o main.S
#include <stdint.h>

#define RCC_BASE	0x40021000
#define AFIO_BASE	0x40010000
#define USART1_BASE	0x40013800
#define GPIOA_BASE	0x40010800
#define GPIOC_BASE	0x40011000
// derived addresses
#define RCC_APB2ENR	*((uint32_t*)0x40021018)
#define GPIOC_CRH	*((uint32_t*)0x40011004)
#define GPIOA_CRH	*((uint32_t*)0x40010804)
#define GPIOC_ODR	*((uint32_t*)0x4001100C)
#define RCC_APB1ENR	*((uint32_t*)0x4002101C)
#define AFIO_MAPR	*((uint32_t*)(AFIO_BASE+0x04))
#define USART1_BRR	*((uint32_t*)(USART1_BASE+0x08))
#define USART1_CR1	*((uint32_t*)(USART1_BASE+0x0C))		// Control Register 1
#define USART1_SR	*((uint32_t*)(USART1_BASE+0x00))		// Status register
#define USART1_DR	*((uint32_t*)(USART1_BASE+0x04))		// Data Register. Rx Data if Read. Tx Data if written.

#define USART_SR_RXNE 0x20		// Rx data register not empty. 5th bit (count from LSB=0).
#define USART_SR_TXE  0x80		// Tx data register is empty. 7th bit (count from LSB=0).

// USART1 Address mapping : 0x4001 3800 - 0x4001 3BFF
void main(){
	char result;
	// Turn on the blue light
	RCC_APB2ENR = 0x0010;		// Turn on clock for GPIOC.
	GPIOC_CRH = 0x001;
	GPIOC_ODR = 0x0100;
	
	// Prep the USART1
	RCC_APB2ENR = 0x4004;		// Turn on Clock for USART1 and GPIOA.
	// Config PA9 for Tx. PA10 for Rx.
	// B: MODE9=11::OutputMode_50MHz, CNF9=10::AlternateFunctionOutput_PushPull. USART1_Tx
	// 4: MODE9=00::InputMode, CNF10=01::FloatingInput.	USART1_Rx
	GPIOA_CRH = 0x04B0;
	// Config the baud rate. Seems fishy. Don't know how the integer is cast to a float
	USART1_BRR = 8000000/38400;		// chip_clk<8MHz>/baud_rate<0.0384MHz>
	USART1_CR1 = 0x200C;			// enable UART, TX and Rx
	// 
	while(1){
		// Receive
		while((USART1_SR & USART_SR_RXNE) == 0);
		result = USART1_DR & 0x1FF;
		// Send
		USART1_DR = 0x1FF & 'X';
		// wait for TX
		while((USART1_SR & USART_SR_TXE) == 0);
	}
}
