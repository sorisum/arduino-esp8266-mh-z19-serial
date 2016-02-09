
WiFiClient client;
int status = WL_IDLE_STATUS;     // the Wifi radio's status

void wifiCheckReconnect(char* ssid, char* pass)
{
  long previousMillis = 0;        // will store last time LED was updated
  long interval = 10000;           // interval at which to blink (milliseconds)
  unsigned long currentMillis = millis();
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) {
    wdt_reset();
    if(currentMillis - previousMillis < interval) 
      continue;
    previousMillis = currentMillis;   
    //dns.processNextRequest();  
    Serial.print("Wifi not connected. Attempting to connect to SSID ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:    
    status = WiFi.begin(ssid, pass);
  }
}

void printWifiData() {
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("  IP Address: ");
  Serial.println(ip);
 
  // print your MAC address:
  byte mac[6];  
  WiFi.macAddress(mac);
  Serial.print("  MAC address: ");
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("  SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  /*byte bssid[6];
  WiFi.BSSID(bssid);    
  Serial.print("BSSID: ");
  Serial.print(bssid[5],HEX);
  Serial.print(":");
  Serial.print(bssid[4],HEX);
  Serial.print(":");
  Serial.print(bssid[3],HEX);
  Serial.print(":");
  Serial.print(bssid[2],HEX);
  Serial.print(":");
  Serial.print(bssid[1],HEX);
  Serial.print(":");
  Serial.println(bssid[0],HEX);*/

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("  signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
 /*byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption,HEX);
  Serial.println();*/
}
