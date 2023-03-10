#include <WiFi.h>

const char* ssid = "AndroidAPe1b3";
const char* password = "rahp3251";

WiFiServer server(80);

String header;

String output26State = "off";
String output27State = "off";

const int output26 = 2;
const int output27 = 5;

void setup(){
  Serial.begin(115200);

  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) { // If a new client connects,
  Serial.println("New Client."); // print a message out in the serial port
  String currentLine = ""; // make a String to hold incoming data from the client
  while (client.connected()) { // loop while the client's connected
    if (client.available()) { // if there's bytes to read from the client,
      char c = client.read(); // read a byte, then
      Serial.write(c); // print it out the serial monitor
      header += c;
      if (c == '\n') { // if the byte is a newline character
      // if the current line is blank, you got two newline characters in a row.
      // that's the end of the client HTTP request, so send a response:
        if (currentLine.length() == 0) {
        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
        // and a content-type so the client knows what's coming, then a blank line:
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: close");
          client.println();}}}}}
          

          // turns the GPIOs on and off
    if (header.indexOf("GET /26/on") >= 0) {
      Serial.println("GPIO 26 on");
      output26State = "on";
      digitalWrite(output26, HIGH);
    } else if (header.indexOf("GET /26/off") >= 0) {
      Serial.println("GPIO 26 off");
      output26State = "off";
      digitalWrite(output26, LOW);
    } else if (header.indexOf("GET /27/on") >= 0) {
      Serial.println("GPIO 27 on");
      output27State = "on";
      digitalWrite(output27, HIGH);
    } else if (header.indexOf("GET /27/off") >= 0) {
      Serial.println("GPIO 27 off");
      output27State = "off";
      digitalWrite(output27, LOW);
    } 
    client.println("<!DOCTYPE HTML><html>");
    client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
    client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    client.println(".button2 {background-color: #555555;}</style></head>");
    // Web Page Heading
    client.println("<h1>ESP32 Web Server</h1>");
    client.println("<p>GPIO 26 - State " + output26State + "</p>");
    if (output26State=="off") {
      client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
    } else {
      client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
}
