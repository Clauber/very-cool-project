#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Arduino_JSON.h>
#include <secrets.h>
#include "led.h"
#include "lcd.h"


// Wifi setup
const char *ssid = SSID;
const char *password = WIFI_PASSWORD;

// Webserver
ESP8266WebServer webserver(80);

#define item "MY_COOL_PROJECT"

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

// Variable to store the HTTP request
String header;

void getStateHandler();
void postStateHandler();

void setup()
{
  Serial.begin(9600);
  lcdStart();
  ledBegin();
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to wifi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Trying to connect...");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  lcdConnected(WiFi.localIP().toString());
  webserver.on("/state", HTTP_GET, getStateHandler);
  webserver.on("/state", HTTP_POST, postStateHandler);
  webserver.begin();
}

void loop()
{
  webserver.handleClient(); // Handling of incoming requests
}

void getStateHandler()
{
  JSONVar response;
  response["status"] = "on";
  response["item"] = item;
  response["state"] = getLEDState();
  Serial.println(response);
  webserver.send(200, "application/json", JSON.stringify(response));
}
void postStateHandler()
{ // Handler for the body path

  if (webserver.hasArg("plain") == false)
  { // Check if body received
    JSONVar response;
    response["missing"] = "body";
    webserver.send(400, "application/json", JSON.stringify(response));
    return;
  }

  String message = webserver.arg("plain");
  JSONVar request = JSON.parse(message);
  if (JSON.typeof(request) == "undefined")
  {
    Serial.println("Parsing input failed!");
    return;
  }
  JSONVar response;
  if (request.hasOwnProperty("color"))
  {
    onStateChange((const char *)request["color"]);
    getStateHandler();
  }
  else
  {
    response["missing"] = "color property";
    webserver.send(400, "application/json", JSON.stringify(response));
    return;
  }

  webserver.send(200, "text/plain", message);
  Serial.println(message);
}
