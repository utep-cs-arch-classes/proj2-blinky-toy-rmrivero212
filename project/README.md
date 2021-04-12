## Description
This interrupt-driven program uses both switches and a timer to flash the leds
and play specific notes from the buzzer.

## How to Use
Simply navigate to the project directory and type **make** into the command
line to build all the files necessary for compilation. After that is done then
type **make load** to see the msp430 flash a consistent red led.

## What You Can Do
A red led will consistently blink almost like metronome. There are 4 buttons
on the expansion board that each have the ability to play a musical note.
* Switch 1(Most left switch) will play the note **d**
* Switch 2 will play the note **c**
* Switches 3 and 4 must be pressed simultaneously in order to produce the note
**e**

Every flash and dim of the light represents the end of a note. So if you press
a note right when the red led flashes it will play out longer. The more late
you are to press the button, the shorter the note.

If you sound it out correctly you can play "One More Time" by Daft Punk

Enjoy!

  








