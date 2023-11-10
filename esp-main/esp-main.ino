# include <WiFi.h>


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


void loop() {



}
