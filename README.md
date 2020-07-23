# NonContactThermometer
The project is my attempt to create a simple and convenient non-contact thermometer with mostly standard and some non-standard parts.
The details I am providing is not for beginners level though. But someone familiar with tools will be able to get this easily. 

Components used :

Arduino Pro Mini *  
0.91 Inch 128x32 OLED LCD Display **  
MLX90614 Infrared Temperature Sensors ( Long Distance ) 
WS2812B Individually Addressable LED  
A push button (used to pause the readings)  
10K resistor  
DC socket***  
USB micro socket***  

I assembled everything on a perforated PCB. It can be assembled by wiring them up directly too. A more elegant solution will be to etch out a PCB. Depends on individual's comfort level.  
 \* I used an older version with Atmega168P. The newer version will have better graphic options using the same display. Instead of Pro Mini, Nano or Uno will be better if someone is only starting into this.  
 ** Any other display can be used too. But the codes will need modification accordingly. I prefer this sleek looking display here. Consumes very little power too, so when I make it portable, that will come in handy.  
 *** I used an external 5V power supply to power this equipment. To have flexibility, I put both options so that I can use it on the go as well using a mobile power bank. It can be further improvised and/or customized to individual's requirements.  
