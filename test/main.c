
/**
 * Simple Cube Test that fills each layer for test
 * Connections:
 * PORTA = Data
 * PORTB[2:0] = Address
 * PORTB[3] = Enable
 * PORTC = Layer select
 */

// This must be defined before delay is included
#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define LAYER_SELECT PORTC
#define ADDRESS_BUS PORTB
#define ADDRESS_MASK 0x07
#define ADDRESS_MASK_INV 0xF8
#define DATA_BUS PORTA
#define OE_MASK 0x08
#define OE_ENABLE() PORTB &= ~OE_MASK
#define OE_DISABLE() PORTB |= OE_MASK

// Global Variables
volatile uint8_t current_layer;

/**
 * Create a longer delay using sequential _delay_ms() calls
 * @param num_delay Number of 10ms delays
 */
void my_delay_ms(uint16_t num_delay)
{
    uint16_t i = 0;
    for (; i < num_delay; ++i)
    {
        _delay_ms(10);
    }

}

// Delay loop.
// This is not calibrated to milliseconds,
// but we had allready made to many effects using this
// calibration when we figured it might be a good idea
// to calibrate it.
void delay_ms(uint16_t x)
{
  uint8_t y, z;
  for ( ; x > 0 ; x--){
    for ( y = 0 ; y < 90 ; y++){
      for ( z = 0 ; z < 6 ; z++){
        asm volatile ("nop");
      }
    }
  }
}

void timer_init()
{
    // Timer 2
    // Frame buffer interrupt
    // 14745600/256/6 = 9600 interrupts per second
    // 9600/8 = 1200 frames per second

    OCR0A = 5;  // interrupt at counter = 10
    TCCR0B |= (1 << CS02); // Prescaler = 256.
    TCCR0A |= (1 << WGM01); // CTC mode. Reset counter when OCR2 is reached.
    TCNT0 = 0x00;   // initial counter value = 0;
    TIMSK0 |= (1 << OCIE0A); // Enable CTC interrupt
}

void io_init()
{
    DDRA = 0xFF;    // PORT A latch data (output)
    DDRB |= 0x0F;   // Lower nibble of B address bus (output)
    DDRC = 0xFF;    // Port C is layer select (output)
    DDRD |= 0x1C;   // PORT D[4:2] are outputs, LEDs

    ADDRESS_BUS = 0x00;   // Flip flops enabled, address = 0

    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);
}

int main(void)
{
    io_init();

    /***************************************************************************
     * Delay profiling
     * the purpose of the following code is to measure the delay_ms function
     * used in the original LED cube by measuring its duration for some various
     * inputs. The measurement is done by toggling a GPIO at the beginning and
     * end of the function.
     *
     * This is done so that we can understand the delay in terms of microseconds
     * so that the cube can be easily ported to other microcontrollers
     */
    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(1);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);


    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(2);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);


    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(3);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);



    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(11);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);


    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(100);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);


    // Profile delay function, set IO to 1
    PORTD |= 0x04;
    delay_ms(1000);
    // Profile delay function, set IO to 0
    PORTD &= ~(0x04);

    _delay_ms(1);

    timer_init();
    current_layer = 0;
    sei();

    while(1)
    {

        // Update layer, protect for atomic access
        cli();
        current_layer++;
        if (current_layer == 8)
        {
            current_layer = 0;
        }
        sei();

        my_delay_ms(1000);
    }
}

ISR(TIMER0_COMPA_vect)
{
    uint8_t i;
    LAYER_SELECT = 0x00;    // Turn off all layers
    OE_DISABLE();
    for (i = 0; i < 8; i++)
    {
        DATA_BUS = 0xFF;
        ADDRESS_BUS  = (ADDRESS_BUS & ADDRESS_MASK_INV) | (ADDRESS_MASK & (i+1));
    }
    OE_ENABLE();
    LAYER_SELECT = (0x01 << current_layer);
}