#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define LDR_PIN 34
#define LIGHT_RELAY 18
#define FAN_RELAY 19

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

const char* ssid = "WIFI_ADIN";
const char* password = "WIFI_SIFREN";

String username = "admin";
String userpassword = "1234";
bool isLoggedIn = false;

int karanlikEsik = 2200;
int aydinlikEsik = 1800;

float sicaklikAc = 28.0;
float sicaklikKapat = 24.0;

bool isikAcik = false;
bool fanAcik = false;

String getHTML(float temp, float hum, int ldr)
{
    String html = "<html><body>";
    html += "<h1>Akilli Sinif Kontrol</h1>";

    if (!isLoggedIn)
    {
        html += "<form action='/login' method='POST'>";
        html += "Kullanici: <input name='user'><br>";
        html += "Sifre: <input name='pass' type='password'><br>";
        html += "<input type='submit' value='Giris'>";
        html += "</form>";
    }
    else
    {
        html += "<p>Sicaklik: " + String(temp) + "</p>";
        html += "<p>Nem: " + String(hum) + "</p>";
        html += "<p>Isik: " + String(ldr) + "</p>";
        html += "<a href='/logout'>Cikis</a>";
    }

    html += "</body></html>";
    return html;
}

void handleRoot()
{
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    int ldr = analogRead(LDR_PIN);

    if (temp > sicaklikAc) {
        digitalWrite(FAN_RELAY, HIGH);
    }
    else if (temp < sicaklikKapat) {
        digitalWrite(FAN_RELAY, LOW);
    }

    if (ldr > karanlikEsik) {
        digitalWrite(LIGHT_RELAY, HIGH);
    }
    else if (ldr < aydinlikEsik) {
        digitalWrite(LIGHT_RELAY, LOW);
    }

    server.send(200, "text/html", getHTML(temp, hum, ldr));
}

void handleLogin()
{
    if (server.hasArg("user") && server.hasArg("pass"))
    {
        if (server.arg("user") == username && server.arg("pass") == userpassword)
        {
            isLoggedIn = true;
        }
    }
    server.sendHeader("Location", "/");
    server.send(303);
}

void handleLogout()
{
    isLoggedIn = false;
    server.sendHeader("Location", "/");
    server.send(303);
}

void setup()
{
    Serial.begin(115200);
    dht.begin();

    pinMode(LIGHT_RELAY, OUTPUT);
    pinMode(FAN_RELAY, OUTPUT);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
    }

    server.on("/", handleRoot);
    server.on("/login", HTTP_POST, handleLogin);
    server.on("/logout", handleLogout);

    server.begin();
}

void loop()
{
    server.handleClient();
}
