
#include <WiFi.h>
#include <WebServer.h>
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

// Display configuration
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

// ESP32 GPIO connections
#define DATA_PIN 23
#define CLK_PIN  18
#define CS_PIN   5

#define LED_BUILTIN 2

// Wi-Fi credentials
// Enter your own credentials when running the project.
// Never publish real passwords on GitHub.
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Display and web server objects
MD_Parola display = MD_Parola(
  HARDWARE_TYPE,
  DATA_PIN,
  CLK_PIN,
  CS_PIN,
  MAX_DEVICES
);

WebServer server(80);

// Default display message
String message = "AUTOFORGE Solutions";

// Scrolling configuration
#define SCROLL_SPEED 100

// Display message
void startDisplayMessage() {
  display.displayClear();
  display.displayScroll(
    message.c_str(),
    PA_LEFT,
    PA_SCROLL_LEFT,
    SCROLL_SPEED
  );
}

// Main web interface
void handleRoot() {

  String html =
    "<!DOCTYPE html>"
    "<html>"
    "<head>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<title>ESP32 LED Display</title>"
    "<style>"
    "body{font-family:Verdana;text-align:center;"
    "background:#111;color:#0f0;padding:30px;}"
    "input{padding:12px;border-radius:5px;border:none;"
    "max-width:90%;}"
    "input[type=submit]{background:#0f0;color:#111;"
    "font-weight:bold;cursor:pointer;}"
    "</style>"
    "</head>"
    "<body>"
    "<h1 style='color:white'>AUTOFORGE SOLUTION LTD</h1>"
    "<h2>SEND A MESSAGE TO THE LED DISPLAY</h2>"
    "<form action='/set' method='get'>"
    "<input name='msg' placeholder='Type your message' required>"
    "<br><br>"
    "<input type='submit' value='Send Message'>"
    "</form>"
    "</body>"
    "</html>";

  server.send(200, "text/html", html);
}

// Receive and process messages
void handleSet() {

  if (server.hasArg("msg")) {

    message = server.arg("msg");
    message.trim();

    if (message.length() > 0) {
      startDisplayMessage();

      Serial.print("New display message: ");
      Serial.println(message);

      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

  server.send(
    200,
    "text/html",
    "Message received successfully. <a href='/'>Go Back</a>"
  );
}

// ESP32 initialization
void setup() {

  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected!");

  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize LED matrix
  display.begin();
  display.setIntensity(0);
  display.displayClear();

  startDisplayMessage();

  // Configure web server routes
  server.on("/", handleRoot);
  server.on("/set", handleSet);

  // Start web server
  server.begin();

  Serial.println("Web server started.");
}

// Main program loop
void loop() {

  server.handleClient();

  // Animate scrolling display
  if (display.displayAnimate()) {
    startDisplayMessage();
  }
}
