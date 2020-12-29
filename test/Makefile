#Makefile for building HelloWorld LED program
#Processor Atmega 324PA
#PORTC Layer select
#PORTA Data Bus
#PORTB = Address Bus

PRG_NAME = main
MCU = atmega324pa

all: $(PRG_NAME).c
	avr-gcc -g -Os -mmcu=$(MCU) -c $(PRG_NAME).c
	avr-gcc -g -mmcu=$(MCU) -o $(PRG_NAME).elf $(PRG_NAME).o
	avr-objcopy -j .text -j .data -O ihex $(PRG_NAME).elf $(PRG_NAME).hex


clean:
	rm -f $(PRG_NAME).elf $(PRG_NAME).hex $(PRG_NAME).o

program:
	avrdude -c usbtiny -p m324pa -B 1 -U flash:w:$(PRG_NAME).hex