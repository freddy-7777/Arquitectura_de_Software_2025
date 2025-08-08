#include <WiFi.h>
#include <WebServer.h>

// Configuración de red Wi-Fi
const char *ssid = "Wifi";           // Cambia por tu SSID                         red:  "BUAP_Trabajadores"
const char *password = "12345678";   // Cambia por tu contraseña Wi-Fi        password:  "BuaPW0rk.2017"

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


  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor HTTP iniciado");
  
    //Fase 1 Verde Encendido
  digitalWrite(PIN_LED_VERDE, HIGH);  // Enciende el LED VERDE 5 segundos
  delay(5000);
  digitalWrite(PIN_LED_VERDE, LOW);  // Apaga el LED VERDE

  //Fase 2 Verde Parpadeo
  digitalWrite(PIN_LED_VERDE, HIGH);  // Enciende el LED VERDE 500 milisegundos
  delay(500);
  digitalWrite(PIN_LED_VERDE, LOW);  // Apaga el LED VERDE 500 milisegundos
  delay(500);

  digitalWrite(PIN_LED_VERDE, HIGH);  // Enciende el LED VERDE 500 milisegundos
  delay(500);
  digitalWrite(PIN_LED_VERDE, LOW);  // Apaga el LED VERDE 500 milisegundos
  delay(500);

  digitalWrite(PIN_LED_VERDE, HIGH);  // Enciende el LED VERDE 500 milisegundos
  delay(500);
  digitalWrite(PIN_LED_VERDE, LOW);  // Apaga el LED VERDE 500 milisegundos
  delay(500);

  //Fase 3 Amarillo
  digitalWrite(PIN_LED_AMARILLO, HIGH);  // Enciende el LED AMARILLO 1.5 segundos
  delay(1500);
  digitalWrite(PIN_LED_AMARILLO, LOW);  // Apaga el LED AMARILLO

  //Fase 4 Rojo Encendido
  digitalWrite(PIN_LED_ROJO, HIGH);  // Enciende el LED ROJO 9.5 segundos
  delay(9500);
  digitalWrite(PIN_LED_ROJO, LOW);  // Apaga el LED ROJO
}

void loop() {
  // Maneja las solicitudes entrantes
  server.handleClient();
}

