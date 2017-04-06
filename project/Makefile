all: musicBox.elf

COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU}
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)

CC	= msp430-elf-gcc
AS	= msp430-elf-as
AR	= msp430-elf-ar

musicBox.elf: ${COMMON_OBJECTS} stateMachine.o handler.o leds.o switches.o main.o buzzer.o libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

load: musicBox.elf
	mspdebug rf2500 "prog musicBox.elf"

clean:
	rm -f libTimer.a *.o *.elf
