# Motorcycle-Remote-Control V 1.0 pre-alpha
*This project is intended to allow for remote control of a Yamaha V-Star 650 (XVS650).*

## Motivation
  I wanted to create a cheap way of controlling the basic functions of my Yamaha V-Star. Some might say it is pointless or lazy, but over the course of this project I intend to increase my coding with C capabilites as well as get some real world experience in getting microcontrollers to interact with machines. I feel that this project will be challenging and fun, and intent on documenting it as much as I'm able to share the joy of accomplishing something that one sets out to do. It will also add some neat flair to my bike and enhance the "cool factor", in my humble opinion. It may also offer some functionality as I dont always want to wait 5-10 minutes for my bike to reach operating temperatures, especially in the winter. I would like to remove/destroy as little of the bike as possible, in the event that I want to remove it. 

## Goals
Some of the many things I would like to accomplish in breif: 
* Create a remote for the transmitter capable of controlling the horn, power on and ignition, power off, adjusting the choke to match weather and engine conditions, and also actuate the steering lock for safe-er remote start.
* Wire the Arduino to be in the off state when the bike is turned on through the manual ignition key switch and on when the bike has been physically switched off. When the bike is in use, I don't want the bike to be dependant on the arduino for use as I don't feel this is very safe. Eventually, I may allow for this if all runs well. The physical ignition will probably always be a way for it to function though.
* Write dependable code for the transmitting and receiving ends of the Arduino. Code will be written in C using various libraries listed below. 
* Read ambient temperature using the DHT11 and use the servo to pull or push the choke knob in accordance with the temperature. 

* In addition to the above, I will also be attaching LED lights to the bike. I don't feel this is neccessary to include though, as no microcontroller use is involved.

### Hardware intended for use

* [Arduino nano V3.0](https://store.arduino.cc/usa/arduino-nano)
* [315Mhz RF Transmitter and Receiver Module](http://www.hiletgo.com/ProductDetail/2157209.html)
* [IRFZ44N N-Channel Field-Effect Power Transitor](https://www.infineon.com/dgdl/irfz44n.pdf?fileId=5546d462533600a40153563b3575220b)
* [Servo motor SG90](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)
* [DHT11 (humidity and temperature sensor)](https://cdn-learn.adafruit.com/downloads/pdf/dht.pdf)
* [Mini momentary tactile push buttons](https://www.hdk.co.jp/pdf/eng/e291702.pdf)
* Various gauge wire

***Some links listed are not the actual manufacturer used, but are equivalent and could be used interchangeably. All can be searched on [Amazon](https://amazon.com) or any other shopping website with fairly accurate responses.***

### Resources used

##### Libraries

* [VirtualWire](https://www.pjrc.com/teensy/td_libs_VirtualWire.html)
* [Servo](https://www.arduino.cc/en/reference/servo)

##### External resources

* [Markdown Cheat Sheet](http://nestacms.com/docs/creating-content/markdown-cheat-sheet)
* [C data type storage sizes](https://intellipaat.com/tutorial/c-tutorial/c-data-types)
* [Arduino RF Tutorial (MX-05V / MX-FS-03V)](https://www.youtube.com/watch?v=cplAjvAAEDw&list=LLQJywBYkZNHAE-BNjEt2v4g)

### Possible concerns/fixes
* Attaching the servo to accurately adjust the choke : 
* Powering on when the bike is "off" and shutting down when the bike is "on" :
* Storage space, as the Arduino nano only has 30720 bytes with no expansion available : 
* Transmitting and receiving power. I've read a few places that these modules aren't very good for long distance communication :
