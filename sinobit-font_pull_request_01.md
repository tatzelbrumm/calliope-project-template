In a tour de force, I extracted most of the characters in the [Table of General Standard Chinese Characters [TGSCC] ](http://hanzidb.org/character-list/general-standard) from @SolidZORO's [zbit bitmap font](https://github.com/tatzelbrumm/zpix-pixel-font/tree/tatzelbranch/transmogrify). 

Assuming that Chinese children learn characters roughly in the sequence of the [Table of General Standard Chinese Characters](http://hanzidb.org/TGSCC-Unicode.txt), 
I used some [Mathematica](https://github.com/tatzelbrumm/zpix-pixel-font/blob/tatzelbranch/transmogrify/BDF_font_translation.nb) [magic](https://github.com/tatzelbrumm/zpix-pixel-font/blob/tatzelbranch/transmogrify/BDF_font_translation.pdf) to arrange the characters in the sequence given by the TGSCC and provided a 3-byte unicode table. 

Each character is [encoded as 12-byte array for the top 8 pixels of each column, followed by a 6-byte array that contains the remaining 4 pixels](https://github.com/tatzelbrumm/calliope-project-template/blob/sinobit-font/source/font.cpp) of the 12 HT1632 display columns.  
This encoding does not waste extra bits, and yet should keep the bit shifting overhead to a minimum. 

I have replaced some missing or out-of-place glyphs with placeholders. 
It should be possible to fix them manually. 

For debugging purposes, I send the charcter index and the unicode from the [TGSCC table](http://hanzidb.org/TGSCC-Unicode.txt) and the 12*12 bitmap via the 115.2kBaud USB port.

This pull request also contains almost all of my fine-grained history of driving the HT1632 display and keeping as much as possible of the micro:bit OS and its associated interrupts off the board, to get full control over the peripheral registers and, as a side effect, to save lots of memory.
A minimalist serial interface allows me to run my program with the -nosd targets 
**and** fit all 8105 [TGSCC](http://hanzidb.org/character-list/general-standard) entries as 12*12 glyphs _plus_ a 3-byte unicode table onto the sino:bit. 

Some more subtle tweaks of the downloaded yotta library files might not have quite been caught by version control.  

Eventually, we want to bulid an mbed or yotta target that replaces the micro:bit / calliope display drivers. 

A [detailed disassembly and memory map](https://github.com/tatzelbrumm/calliope-project-template/blob/sinobit-font/sinobit-project-template.disassembly) shows the resource usage of my program. 
```
arm-none-eabi-size build/sinobit-classic-gcc-nosd/source/sinobit-project-template
   text	   data	    bss	    dec	    hex	filename
 174392	    116	    160	 174668	  2aa4c	build/sinobit-classic-gcc-nosd/source/sinobit-project-template
```

For actual applications, it is probably best to load only a subset of the contiguous TGSCC character set onto the sino:bit and add some of the more complicated extra characters as needed. 
