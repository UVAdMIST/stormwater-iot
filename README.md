# Storm Water IoT

### Visualizing Pond Depth Using The Things Network and InfluxDB

For this project, I programmed a featherboard microcontroller using the Arduino IDE to read analog ultrasonic data from a MaxBotix MB7092 sensor. In addition, the project relies on an internet of things approach using long distance radio communication with LoRaWAN and The Things Network and data storage and visualization with InfluxDB. The application was for a pond in Norfolk, Virginia to get an understanding of how a rainfall event would affect the pond over time. Ideally, using the pond as a means of stormwater retention would alleviate the burden on Norfolk's stormwater management system. 

! [](images\flowchart.jpg)

#### Hardware Used
- [Adafruit Feather 32u4 LoRa RFM9x](https://www.adafruit.com/product/3078)
- [MaxBotix MB7092](https://www.maxbotix.com/Ultrasonic_Sensors/MB7092.htm) 
- [The Things Gateway](http://www.newark.com/the-things-network/ttn-gw-915/accessory-type-wireless-gateway/dp/05AC1807)

#### Software Used
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Node-Red](https://nodered.org/)
- [InfluxDB](https://portal.influxdata.com/downloads)




#### Helpful Tutorials
- [Running the TICK Stack on Windows](https://www.influxdata.com/blog/running-the-tick-stack-on-windows/) - if you're running Windows, this guide will be crucial to getting InfluxDB and its components running correctly on your machine.
- [Tutorial: Build an open source smart city with LoRaWAN](https://medium.com/kkbankol-events/tutorial-build-a-open-source-smart-city-based-on-lora-7ca76b9a098) - this tutorial gives a beginning to end guide on creating your own gateway, as opposed to buying one, correct wiring diagrams for the featherboard I used, and coding examples and flows. 

The Things Network (TTN) in the United States operates at the 915 MHz band for low-bandwidth, long distance radio communication. Because it is open, free to use, and low-bandwidth, messages sent to TTN are expected to be small in size (in the order of bytes). Best practice is to limit bandwidth to 400 bytes/hour. 

The LoRa chip on the Featherboard is designed to send small packets of data at intervals so it works well for this project but because TTN uses [LoRaWAN](https://www.lora-alliance.org/about-lorawan), the LoRaWAN stack had to be placed onto the chip. I used [this library](https://github.com/matthijskooijman/arduino-lmic) which enabled me to initally send the string, "Hello, World!" to TTN.


#### Issues
- When 