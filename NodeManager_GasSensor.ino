
/*
NodeManager is intended to take care on your behalf of all those common tasks a MySensors node has to accomplish, speeding up the development cycle of your projects.
NodeManager includes the following main components:
- Sleep manager: allows managing automatically the complexity behind battery-powered sensors spending most of their time sleeping
- Power manager: allows powering on your sensors only while the node is awake
- Battery manager: provides common functionalities to read and report the battery level
- Remote configuration: allows configuring remotely the node without the need to have physical access to it
- Built-in personalities: for the most common sensors, provide embedded code so to allow their configuration with a single line
Documentation available on: https://github.com/mysensors/NodeManager
*/


// load user settings
#include "config.h"
// include supporting libraries
#ifdef MY_GATEWAY_ESP8266
  #include <ESP8266WiFi.h>
#endif
// load MySensors library
#include <MySensors.h>
// load NodeManager library
#include "NodeManager.h"

// create a NodeManager instance
NodeManager nodeManager;

// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);

  /*
   * Register below your sensors
  */
  Serial.println(F("BEFORE"));
  printFM();
  nodeManager.setSleepMinutes(2);
  nodeManager.setReportIntervalMinutes(2);
//  nodeManager.setSleepSeconds(10);
//  nodeManager.setReportIntervalSeconds(10);

  SensorMQ* mqSensor = 0;
  Serial.print(F("BEFORE registerSensor 0: ")); printFM();
  int mq2 = nodeManager.registerSensor(SENSOR_MQ, A0, 1);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq2));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-2");

  Serial.print(F("BEFORE registerSensor 1: ")); printFM();
  int mq3 = nodeManager.registerSensor(SENSOR_MQ, A1, 2);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq3));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-3");

  Serial.print(F("BEFORE registerSensor 2: ")); printFM();
  int mq4 = nodeManager.registerSensor(SENSOR_MQ, A2, 3);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq4));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-4");

  Serial.print(F("BEFORE registerSensor 3: ")); printFM();
  int mq5 = nodeManager.registerSensor(SENSOR_MQ, A3, 4);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq5));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-5");

  Serial.print(F("BEFORE registerSensor 4: ")); printFM();
  int mq7 = nodeManager.registerSensor(SENSOR_MQ, A4, 5);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq7));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-7");
  
  Serial.print(F("BEFORE registerSensor 5: ")); printFM();
  int mq8 = nodeManager.registerSensor(SENSOR_MQ, A5, 6);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq8));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-8");
  
  Serial.print(F("BEFORE registerSensor 6: ")); printFM();
  int mq9 = nodeManager.registerSensor(SENSOR_MQ, A6, 7);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq9));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-9");
  
  Serial.print(F("BEFORE registerSensor 7: ")); printFM();
  int mq135 = nodeManager.registerSensor(SENSOR_MQ, A7, 8);
  mqSensor = ((SensorMQ*)nodeManager.getSensor(mq135));
  mqSensor->setCalibrationSampleTimes(10);
  mqSensor->setCalibrationSampleInterval(250);
  mqSensor->setDescription("MQ-135");
  

  Serial.print(F("BEFORE reg.Sens. MHZ19: ")); printFM();
  int co2 = nodeManager.registerSensor(SENSOR_MHZ19, 6, 9);
  SensorMHZ19* co2Sensor = ((SensorMHZ19*)nodeManager.getSensor(co2));
  co2Sensor->setRxTx(6, 7);
  co2Sensor->setDescription("MH-Z19 CO2 Sensor");

  Serial.print(F("AFTER registering Sensors: ")); printFM();
  /*
   * Register above your sensors
  */
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();
}

// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}

// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}


template<int s> struct Wow;
//Wow<sizeof(Sensor)> unused_warning;
//Wow<sizeof(SensorMQ)> unused_warning;
//Wow<sizeof(NodeManager)> unused_warning;
