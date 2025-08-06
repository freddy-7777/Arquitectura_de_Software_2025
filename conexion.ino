#include <WiFi.h>
#include <WebServer.h>

// Configuración de red Wi-Fi
const char *ssid = "Wifi";           // Cambia por tu SSID                         red:  "BUAP_Trabajadores"
const char *password = "12345678";   // Cambia por tu contraseña Wi-Fi        password:  "BuaPW0rk.2017"

// Asignación de pines
#define PIN_PULS 4  // Lectura del pulsador
#define PIN_LED  2  // Salida LED

// Crear un servidor web en el puerto 80
WebServer server(80);

void setup() {
  // Inicialización de la comunicación serie
  Serial.begin(115200);

  // Configuración de pines
  pinMode(PIN_PULS, INPUT);  // Entrada del pulsador
  pinMode(PIN_LED, OUTPUT);  // Salida LED

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("¡Conectado!");
  Serial.println(WiFi.localIP()); 


  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  // Maneja las solicitudes entrantes
  server.handleClient();
}

