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
  Serial.println(F("BEFORE"));
  printFM();
  Serial.begin(MY_BAUD_RATE);  
  /*
   * Register below your sensors
  */
  nodeManager.setSleep(SLEEP, 2, MINUTES); 
  Serial.print(F("BEFORE registerSensor0: ")); printFM();
  nodeManager.registerSensor(SENSOR_MQ, A0, 0);
  Serial.print(F("BEFORE registerSensor1: ")); printFM();
  nodeManager.registerSensor(SENSOR_MQ, A1, 1);
  Serial.print(F("BEFORE registerSensor2: ")); printFM();
  nodeManager.registerSensor(SENSOR_MQ, A2, 2);
  Serial.print(F("BEFORE registerSensor3: ")); printFM();
  nodeManager.registerSensor(SENSOR_MQ, A3, 3);
  Serial.print(F("BEFORE reg.Sens. MHZ19: ")); printFM();
  
  int co2 = nodeManager.registerSensor(SENSOR_MHZ19, 6, 4);
  SensorMHZ19* co2Sensor = ((SensorMHZ19*)nodeManager.getSensor(co2));
  co2Sensor->setRxTx(6, 7);
  Serial.print(F("AFTER reg. sensors:     "));printFM();
  
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


