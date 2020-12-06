#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "valdenir";
const char *password = "1q2w3e4r5t";


void setup()
{
  Serial.begin(115200);
  delay(4000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) //Check for the connection
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED) //Check WiFi connection status
  {
    HTTPClient http;

    http.begin("http://192.168.43.56:1880/moaci-test");
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST("{\"real_power\": 42.64911, \"apparent_power\": 214.9457}");

    if (httpResponseCode > 0)
    {
      String response = http.getString(); //Get the response to the request
      Serial.println(httpResponseCode);   //Print return code
      Serial.println(response);           //Print request answer
    }
    else
    {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else
  {
    Serial.println("Error in WiFi connection");
  }
  delay(500);
}
