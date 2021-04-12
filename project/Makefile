# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o led.o switches.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o assembly.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf *~ *#

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

assembly.o: stateMachines.h
