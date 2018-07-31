# Visualizing Pond Depth Using The Things Network and InfluxDB

In this project, I sought to record ultrasonic distance data and send it through The Things Network using the Arduino IDE platform.

#### Hardware
- [Adafruit Feather 32u4 LoRa RFM9x](https://www.adafruit.com/product/3078)
- [MaxBotix MB7092](https://www.maxbotix.com/Ultrasonic_Sensors/MB7092.htm)
- [The Things Gateway](http://www.newark.com/the-things-network/ttn-gw-915/accessory-type-wireless-gateway/dp/05AC1807)

The Things Network (TTN) in the United States operates at the 915 MHz band for low-bandwidth, long distance radio communication. Because it is open, free to use, and low-bandwidth, messages sent to TTN are expected to be small in size (in the order of bytes). Best practice is to limit bandwidth to 400 bytes/hour. 

The LoRa chip on the Featherboard is designed to send small packets of data at intervals so it works well for this project but because TTN uses [LoRaWAN](https://www.lora-alliance.org/about-lorawan), the LoRaWAN stack had to be placed onto the chip. I used [this library](https://github.com/matthijskooijman/arduino-lmic) which enabled me to initally send the string, "Hello, World!" to TTN.