// setup output pins
// read signals from pins
// if signal changes, send it to senver
// each 20 sec send 'connect' to server

// examples
// https://github.com/arduino/Arduino/
// https://github.com/sivieri/tweetino

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x59, 0x67 };  
const char serverName[] = "signals.makridenkov.ru";
const String TOKEN = <your secret key from http://signals.makridenkov.ru/configs>;
// example -- const String TOKEN = "sdfdfikumimoxwereffffwi"



long previousMillis = 0;

// all avaliable pins int sensorPins[] = { 0, 1,    2, 3, 5, 6, 7, 8, 9 };
int sensorPins[] = { 3, 5, 6, 7, 8 }; 	// here used only 5 pins
const int sensorPinsSize = 5;		  	// set how many pins you use
int sensor_previous[sensorPinsSize];

EthernetClient client;

void debug(String mes){
	// Serial.print(mes);
}

void debugln(String mes){
	// Serial.println(mes);
}

void wait_disconnect(){

	while (client.connected()) {
		// read HTTP response
		if (client.available()) {
			client.stop();
			// char c = client.read();
			// debug(&c);
		}
	}

	// debugln("");
	// debugln("Disconnect");
	// client.stop();
}

void send(String data) {
	if (client.connect(serverName, 80)) {
		debug("Make a HTTP request '" + data + "' ... ");

		client.println("GET /add/" + TOKEN + "/" + data + " HTTP/1.0");
		client.println("HOST: signals.makridenkov.ru");
		client.println();

		debugln("ok");

	} 
	else {
		debugln("Connection failed");
	}

	wait_disconnect();
}

void send_sensor(int sensor, int state){
	send("sensor" + String(sensor) + "/" + String(state));
}

void send_connect(){
	send("connect");
}

void setup() {
	// Serial.begin(9600);  
	
	// Sensors
	int i;
	for (i = 0; i < sensorPinsSize; i = i + 1) {
		pinMode(sensorPins[i], INPUT);
		debugln("Setup sensor" + String(sensorPins[i]) + " to INPUT"); 
	}

	debug("Setup LAN ... ");

	delay(2000); // give the Ethernet shield a time to initialize:

	if (Ethernet.begin(mac) == 0){	// DHCP
		debugln("DHCP failed");
		while(true){}
	}
	
	delay(2000); // give the Ethernet shield a time to initialize:

	debugln("ok");
}

void loop(){
	// read sensors
	int i;
	for (i = 0; i < sensorPinsSize; i = i + 1) {
		int sensor_now = digitalRead(sensorPins[i]);
		// if sensor changed send to server
		if (sensor_previous[i] != sensor_now){
			sensor_previous[i] = sensor_now;
			send_sensor(sensorPins[i], sensor_now);
		}
	}

	// send connect each 20 sec
	unsigned long currentMillis = millis();
	if(currentMillis - previousMillis > 20000) {
		previousMillis = currentMillis;
		send_connect();
	}
}


