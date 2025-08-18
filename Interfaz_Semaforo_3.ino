#include <WiFi.h>
#include <WebServer.h>

// Configuración de red Wi-Fi
const char *ssid = "BUAP_Trabajadores";   //"BUAP_Trabajadores";//"Wifi";           // Cambia por tu SSID                         red:  "BUAP_Trabajadores"
const char *password = "BuaPW0rk.2017";  //"BuaPW0rk.2017"; //"12345678";   // Cambia por tu contraseña Wi-Fi        password:  "BuaPW0rk.2017"

// Asignación de pines
#define PIN_LED_VERDE     21  // Salida LED VERDE
#define PIN_LED_AMARILLO  22  // Salida LED AMARILLO
#define PIN_LED_ROJO      23  // Salida LED ROJO

// Crear un servidor web en el puerto 80
WebServer server(80);

void setup() {
  // Inicialización de la comunicación serie
  Serial.begin(115200);

  // Configuración de pines
  pinMode(PIN_LED_VERDE, OUTPUT);  // Salida LED VERDE
  pinMode(PIN_LED_AMARILLO, OUTPUT);  // Salida LED AMARILLO
  pinMode(PIN_LED_ROJO, OUTPUT);  // Salida LED ROJO
    
  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("¡Conectado!");
  Serial.println(WiFi.localIP()); 

  
  // Rutas para controlar el LED VERDE
  server.on("/led/verde/on", HTTP_GET, []() {
    digitalWrite(PIN_LED_VERDE, HIGH);  // Enciende el LED
    server.send(200, "text/plain", "LED Verde Encendido");
  });

    server.on("/led/verde/off", HTTP_GET, []() {
    digitalWrite(PIN_LED_VERDE, LOW);  // Apaga el LED
    server.send(200, "text/plain", "LED Verde Apagado");
  });

  
  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  // Maneja las solicitudes entrantes
  server.handleClient();
}

