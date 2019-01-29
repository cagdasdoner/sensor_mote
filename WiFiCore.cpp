#include "WiFiCore.h"
#include "Hardware.h"
#include "Global.h"

uint16_t delayMilis = 1000;
uint8_t tryCnt = 0;
  
void WiFiBegin(const char* ssid, const char* pass)
{
  char deviceIP[LEN_IP_MAX] = {};
    
  WiFi.begin(ssid, pass);
  tryCnt = 40;
  Printf("Waiting for AP connection in %d seconds\n", tryCnt);
  while(WiFi.status() != WL_CONNECTED && tryCnt--)
  {
    Printf(".");
    delay(delayMilis);
  }

  if(tryCnt) 
  {
    WiFiGetIP(deviceIP);
    Printf("\nConnected to AP. IP : %s\n", deviceIP);
  }
  else
  {
    Printf("\nFailed Wi-Fi Connection. Go to sleep.\n");
    HWSleep();
  }
}

void WiFiGetIP(char* ipBuffer)
{
  memset(ipBuffer, 0, LEN_IP_MAX);
  IPAddress ip = WiFi.localIP();
  snprintf(ipBuffer, LEN_IP_MAX, "%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
}

void WiFiGetSSID(char* ssidBuffer)
{
  memset(ssidBuffer, 0, LEN_SSID_MAX);
  strncpy(ssidBuffer, WiFi.SSID().c_str(), LEN_SSID_MAX);
}

void WiFiGetPassphrase(char* passBuffer)
{
  memset(passBuffer, 0, LEN_PASSPHRASE_MAX);
  strncpy(passBuffer, WiFi.psk().c_str(), LEN_PASSPHRASE_MAX);
}
