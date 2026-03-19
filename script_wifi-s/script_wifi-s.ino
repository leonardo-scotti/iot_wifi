#include <WiFi.h>

const char* ssid    = "Scotti";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  Serial.print("Conectando a: ");
  Serial.println(ssid);

  // Inicia conexão como station
  WiFi.begin(ssid, password);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 20) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }
  Serial.println(tentativas);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✔️ Conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("RSSI (sinal): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
  } else {
    Serial.println("\n✖️ Falha na conexão!");
  }
}

void loop() {
  // Verifica a conexão a cada 10 segundos
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconectando...");
    WiFi.reconnect();
  }

  delay(1000);
}
