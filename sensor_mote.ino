#include <ESP8266WiFi.h>
#include <Arduino.h>

#include "WiFiCore.h"
#include "Hardware.h"
#include "HTTPConnector.h"
#include "Global.h"
#include "Credentials.h"

void purpose()
{
  char tempStr[LEN_TEMP_MAX];
      
  HWGetTempString(0, tempStr);
  if(strlen(tempStr))
  {
    /* Send to Thingspeak. */
    if(!HTTPPostCloud(tempStr))
    {
      Printf("Error!  : Publishment has not succeeded!\n");
    }
  }
  else
  {
    Printf("Error!  : Could not retrieve sensor data!\n");
  }
  HWSleep();
}

void setup() 
{
  HWInit();
  WiFiBegin(STA_SSID, STA_PASS);
  purpose();
}

void loop() 
{
  HWLoop();
  yield();
}
