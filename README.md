# Storm Water IoT

Visualizing Pond Depth Using The Things Network and InfluxDB
----

For this project, I programmed a featherboard microcontroller using the Arduino IDE to read analog ultrasonic data from a MaxBotix MB7092 sensor. In addition, the project relies on an internet of things approach using long distance radio communication with LoRaWAN and The Things Network and data storage and visualization with InfluxDB. The application was for a pond in Norfolk, Virginia to get an understanding of how a rainfall event would affect the pond over time. Ideally, using the pond as a means of stormwater retention would alleviate the burden on Norfolk's stormwater management system. 

![alt-tag](https://github.com/sta7bw/stormwater-iot/blob/master/images/flowchart.JPG)

Hardware Used
----
- [Adafruit Feather 32u4 LoRa RFM9x](https://www.adafruit.com/product/3078)
- [MaxBotix MB7092](https://www.maxbotix.com/Ultrasonic_Sensors/MB7092.htm) 
- [The Things Gateway](http://www.newark.com/the-things-network/ttn-gw-915/accessory-type-wireless-gateway/dp/05AC1807)

Software Used
----
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Node-Red](https://nodered.org/) - a flow based programming platform that easily lets the user connect different sources of information
- [InfluxDB](https://portal.influxdata.com/downloads)
- [LMIC Library](https://github.com/matthijskooijman/arduino-lmic)

Project Details
----
The Things Network (TTN) in the United States operates at the 915 MHz band for low-bandwidth, long distance radio communication. Because it is open, free to use, and low-bandwidth, messages sent to TTN are expected to be small in size (in the order of bytes). Best practice is to limit bandwidth to 400 bytes/hour. 

The LoRa chip on the Featherboard is designed to send small packets of data at intervals so it works well for this project but because TTN uses [LoRaWAN](https://www.lora-alliance.org/about-lorawan), the LoRaWAN stack had to be placed onto the chip. I used the [LMIC Library](https://github.com/matthijskooijman/arduino-lmic) which enabled me to initally send the string, "Hello, World!" to TTN using the example ttn_abp. 

I compiled code that read the ultrasonic data from the sensor and printed the value to the serial monitor. I used the code developed there to replace the string "Hello, World!" in the LMIC example and instead send the ultrasonic data encoded as 2 bytes in hexadecimal format. In order to decode the hexadecimal to decimal format, I used a payload format in TTN console that reversed the code. 

From there, I created a [node flow](https://github.com/sta7bw/stormwater-iot/blob/master/images/node_flow.JPG) using node-red that grabs the data from TTN and sends it to InfluxDB. Then, following the tutorial listed below, I was able to visualize that data using Chronograf, software owned by InfluxDB. 

Helpful Tutorials
----
- [Running the TICK Stack on Windows](https://www.influxdata.com/blog/running-the-tick-stack-on-windows/) - if you're running Windows, this guide will be crucial to getting InfluxDB and its components running correctly on your machine.
- [Tutorial: Build an open source smart city with LoRaWAN](https://medium.com/kkbankol-events/tutorial-build-a-open-source-smart-city-based-on-lora-7ca76b9a098) - this tutorial gives a beginning to end guide on creating your own gateway, as opposed to buying one, correct wiring diagrams for the featherboard I used, and coding examples and flows. 
- [The Things Network](https://www.thethingsnetwork.org/docs/) - everything you need to know about using TTN as well as how it operates is in this guide. In addition, the [TTN Youtube](https://www.youtube.com/channel/UCv85CXnZUXEKnlZpQapTAwQ) has extensive tutorials to understand the process and get your devices running.

Issues
----
- When re-uploading code to the Adafruit 32u4, you might need to reset the frame counters on the device overview secton of TTN console in order for the device to be seen again. 
- If you run into an issue with your Adafruit or other Arduino IDE compatible board where your computer fails to recognize the USB, the bootloading process should fix the issue. To do this, follow this [tutorial](https://learn.adafruit.com/adafruit-feather-32u4-radio-with-lora-radio-module/faq).