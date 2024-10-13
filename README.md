# IoT MQTT Based Heart Rate Monitor using ESP8266 & Arduino

In this project, you will create an **IoT-based Heart Rate Monitor** that combines multiple components to track both heart rate (BPM) and body temperature. 
The device will display these values on an OLED screen while also transmitting the data to an MQTT dashboard for remote monitoring.

In this project, you are building an **IoT-based Heart Rate Monitor** that integrates several components to monitor both heart rate (BPM) and body temperature. The system will display the values on an OLED screen and send data to an MQTT dashboard. Here's an overview of how each component works together:

### Components:
1. **Arduino UNO**:
   - The Arduino Uno power supply can be done with the help of a USB cable or an external power
     supply.
   - The external power supplies mainly include AC to DC adapter otherwise a battery.
   - The adapter can be connected to the Arduino Uno by plugging into the power jack of the Arduino
     board.
     
3. **NodeMCU ESP8266**:
   - A Wi-Fi-enabled microcontroller used for data transmission and integration with IoT platforms.
   - Connects to a Wi-Fi network to send heart rate and temperature data to a cloud service (MQTT dashboard or Ubidots).

2. **Easy Pulse Sensor**:
   - Measures the heart rate by detecting the blood flow rate from the fingertip.
   - Outputs the heartbeats per minute (BPM).

3. **Temperature Sensor (DS18B20)**:
   - Measures body temperature.
   - It's a digital temperature sensor with high accuracy.

4. **OLED Display**:
   - Displays real-time data for heart rate and temperature.
   - The values will be visible to the user instantly.

5. **MQTT Dashboard**:
   - A cloud platform used to visualize data remotely.
   - MQTT (Message Queuing Telemetry Transport) protocol is a lightweight messaging protocol ideal for IoT devices.
   - Data such as heart rate and temperature will be sent to this dashboard for remote monitoring.

6. **Ubidots**:
   - A cloud IoT platform for data storage, analytics, and visualization.
   - You can upload the heart rate and temperature data to Ubidots using HTTP/MQTT protocol, allowing real-time tracking and historical data analysis.

### Project Flow:
1. **Hardware Setup**:
   - The **Easy Pulse Sensor** is connected to the NodeMCU for heart rate monitoring.
   - The **DS18B20 Temperature Sensor** is also connected to the NodeMCU for temperature readings.
   - An **OLED Display** is used to show real-time values of heart rate and temperature.
   
2. **Wi-Fi Connection**:
   - NodeMCU connects to the local Wi-Fi network, allowing the data to be sent to the MQTT dashboard and Ubidots server.

3. **Data Collection**:
   - Pulse sensor data is processed to extract the heart rate (BPM).
   - The DS18B20 sensor measures the temperature.

4. **Data Display**:
   - Real-time heart rate and temperature values are displayed on the OLED screen for local monitoring.

5. **Cloud Integration**:
   - The data is transmitted to an MQTT dashboard for remote monitoring.
   - Ubidots stores the data for real-time visualization and future analysis.

### Practical Applications:
- This IoT-based heart rate and temperature monitoring system can be used in remote healthcare applications, where patients' vitals can be tracked in real-time by healthcare providers.

### Code Structure:
- The code will likely involve libraries for:
  - Handling the **OLED Display** (e.g., `Adafruit_SSD1306`).
  - **Wi-Fi** connectivity (e.g., `ESP8266WiFi`).
  - Reading from **Easy Pulse Sensor** and **DS18B20**.
  - Sending data using the **MQTT protocol** (e.g., `PubSubClient`).

### Potential Add-ons:
- **Battery-Powered**: You can add a battery to make the system portable.
- **Alerts**: Set thresholds for heart rate or temperature, and send alerts if values exceed a critical range.
- **More Sensors**: Add additional sensors like blood pressure or SpO2 for enhanced health monitoring.

This project integrates hardware components, cloud platforms, and real-time data monitoring for a comprehensive health-tracking solution. Would you like to see the code for this setup?

### Result

- The IoT based health monitoring system using DS18B20, HRM2511E, Arduino Uno and NodeMCU ESP8266 would allow the user to monitor their health parameters remotely.
- The DS18B20 temperature sensor would measure the body temperature of the user, while the HRM2511E heart rate monitor would measure the user's heart rate.
- The data collected by these sensors would be transmitted wirelessly to the NodeMCU ESP8266 module, which would then transmit the data to a remote server for analysis.
- The system would be able to provide real-time monitoring of the user's health parameters, allowing for early detection of any anomalies or health issues.
- The system could also be configured to send alerts to the user or their healthcare provider if any readings fall outside of normal ranges.
- Overall, the IoT based health monitoring system would provide a convenient and effective way for users to monitor their health remotely, helping to improve their overall health and wellbeing.

### Conclusions:

A is facility with instruments and equipment to make observations of conditions in order to provide information to make process of manufacturing with good quality.

### Scope for future work

1. Integration with AI and Machine Learning: The integration of AI and machine learning algorithms can enable the system to analyze the health data collected and provide personalized health recommendations to patients.
2. Wearable devices: The use of wearable devices such as smartwatches and fitness bands can improve the accuracy and ease of monitoring health parameters.
3. Cloud-based data storage: Storing the health data collected in the cloud can enable healthcare providers to access it from anywhere, improving patient care and management.
4. Telemedicine: The integration of telemedicine services with the IoT based health monitoring system can enable remote consultations with healthcare providers, improving access to healthcare services.
5. Data analytics: The analysis of health data collected over time can provide insights into the health trends and patterns, enabling healthcare providers to develop better treatment plans.


