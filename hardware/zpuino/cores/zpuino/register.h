#ifndef __REGISTER_H__
#define __REGISTER_H__

#if defined( __ZPUINO_S3E_EVAL__ )
#define CLK_FREQ 100000000ULL
#else
# if defined( __ZPUINO_PAPILIO_ONE__ )
#  define CLK_FREQ  96000000ULL
# else
#  error Unknown board.
# endif
#endif

#define SPIISBLOCKING 1


#define IOBASE 0x8000
#define IO_SLOT_OFFSET_BIT 5
#define BIT(x) (1<<x)

#define IO_SLOT(x) (IOBASE + (x<<IO_SLOT_OFFSET_BIT))

#define REGISTER(SLOT, y) *(volatile unsigned int*)(SLOT + (y<<2))

#define SPIBASE  IO_SLOT(0)
#define UARTBASE IO_SLOT(1)
#define GPIOBASE IO_SLOT(2)
#define TIMERSBASE IO_SLOT(3)
#define INTRBASE IO_SLOT(4)
#define SIGMADELTABASE IO_SLOT(5)
#define USERSPIBASE IO_SLOT(6)
#define CRC16BASE IO_SLOT(7)


#define UARTDATA REGISTER(UARTBASE,0)
#define UARTCTL  REGISTER(UARTBASE,1)

#define SPICTL  REGISTER(SPIBASE,0)
#define SPIDATA REGISTER(SPIBASE,1)

#define GPIODATA  REGISTER(GPIOBASE,0)
#define GPIOTRIS  REGISTER(GPIOBASE,1)

#define TMR0CTL  REGISTER(TIMERSBASE,0)
#define TMR0CNT  REGISTER(TIMERSBASE,1)
#define TMR0CMP  REGISTER(TIMERSBASE,2)
#define TIMERTSC REGISTER(TIMERSBASE,3)
#define TMR0OCR  REGISTER(TIMERSBASE,3) /* Same as TSC */
#define TMR1CTL  REGISTER(TIMERSBASE,4)
#define TMR1CNT  REGISTER(TIMERSBASE,5)
#define TMR1CMP  REGISTER(TIMERSBASE,6)
#define TMR1OCR  REGISTER(TIMERSBASE,7)

#define INTRCTL  REGISTER(INTRBASE,0)

#define SIGMADELTACTL   REGISTER(SIGMADELTABASE,0)
#define SIGMADELTADATA  REGISTER(SIGMADELTABASE,1)

#define USPICTL  REGISTER(USERSPIBASE,0)
#define USPIDATA REGISTER(USERSPIBASE,1)

#define CRC16ACC  REGISTER(CRC16BASE,0)
#define CRC16POLY REGISTER(CRC16BASE,1)
#define CRC16APP  REGISTER(CRC16BASE,2)

/* Timer CTL bits */

#define TCTLENA 0 /* Timer Enable */
#define TCTLCCM 1 /* Clear on Compare Match */
#define TCTLDIR 2 /* Direction */
#define TCTLIEN 3 /* Interrupt enable */
#define TCTLCP0 4 /* Clock prescaler bit 0 */
#define TCTLCP1 5 /* Clock prescaler bit 1 */
#define TCTLCP2 6 /* Clock prescaler bit 2 */
#define TCTLIF  7 /* Interrupt flag */
#define TCTLOCE 8 /* Output compare enable */

/* SPI bits */
#define SPIREADY 0 /* SPI ready */
#define SPICP0   1 /* Clock prescaler bit 0 */
#define SPICP1   2 /* Clock prescaler bit 1 */
#define SPICPOL  3 /* Clock polarity */
#define SPISRE   4 /* Sample on Rising Edge */
#define SPIEN    5 /* SPI Enabled (gpio acquire) */

/* Sigma-Delta bits */
#define SDENA    0 /* Sigma-delta enable */

/* Baud rate computation */

#define BAUDRATEGEN(x) ((CLK_FREQ/(x))/4)-1


/* Special GPIO pins */

#define PIN_FLASHCS 0
#define PIN_TIMER0_OC 1
#define PIN_TIMER1_OC 2
#define PIN_SIGMADELTA_OUT 3

#define PIN_USPI_MISO 5
#define PIN_USPI_SCK  6
#define PIN_USPI_CS   7 /* Not special */
#define PIN_USPI_MOSI 8

#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

#endif