#include "WiFi.h"
#include "esp_wifi.h"
//#include <esp_wifi_types.h>
//#include <esp_system.h>

//
// SEND CUSTOM RAW PACKETS FUNCTION
//int8_t ieee80211_freedom_output(uint32_t *ifx, uint8_t *buffer, uint16_t len);
//extern void* g_wifi_menuconfig;
//uint32_t zeros[64] = { 0x00000000 };
//
//int8_t free80211_send(uint8_t *buffer, uint16_t len) {
//	int8_t rval = 0;
//
//	*(uint32_t *)((uint32_t)&g_wifi_menuconfig - 0x253) = 1;
//	rval = ieee80211_freedom_output(zeros, buffer, len);
//	if (rval == -4) asm("ill");
//	return rval;
//}
//
//
void find_network() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  int n = WiFi.scanNetworks();
  char ssid[];
  char bssid[32];

  for (int i = 0; n < i; i++)
  {
    ssid[i-1] = WiFi.SSID(i);
    bssid[i-1] = WiFi.BSSID(i);
  }
  Serial.println(ssid);
  Serial.println(bssid);



}






void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  find_network();

}
