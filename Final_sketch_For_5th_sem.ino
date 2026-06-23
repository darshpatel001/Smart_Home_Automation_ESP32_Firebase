#define DEBUG_SW 1 // Make it 1 to see all debug messages in Serial Monitor


#include "DHT.h"
#define DHTPIN 15 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP32.h>

DHT dht(DHTPIN, DHTTYPE);


//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;


// Firebase Credentials
#define FIREBASE_HOST "esp32test-b6d86-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "dJkzp7h0GGQArt1jspCL6WtxtVImqK2zUaFkbX87"

float humidity  = dht.readHumidity(); 
float temperature = dht.readTemperature();

// WiFi Credentials
#define WIFI_SSID "D"
#define WIFI_PASSWORD "1293203"

// Function Declaration
inline void  with_internet();
inline void  without_internet();
inline void temp_with_internet();

// Pins of Switches
#define S5 23
#define S6 19
#define S7 18
#define S8 5

// Pins of Relay (Appliances Control)
#define R5 13
#define R6 12
#define R7 14
#define R8 27

// Necessary Variables
int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(S5, INPUT_PULLUP);
  pinMode(S6, INPUT_PULLUP);
  pinMode(S7, INPUT_PULLUP);
  pinMode(S8, INPUT_PULLUP);

  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  
  dht.begin();
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity  = dht.readHumidity(); 
  float temperature = dht.readTemperature();
  
  if (WiFi.status() != WL_CONNECTED)
  {
    if (DEBUG_SW) Serial.println("Not Connected");
    without_internet();
  }

  else
  {
    if (DEBUG_SW) Serial.println(" Connected");
    Data_from_firebase();
    with_internet();
  }
}

inline void Data_from_firebase()
{
  if (Firebase.getString(firebaseData, "/Appliances"))
  {
    
    if (Firebase.getString(firebaseData, "/Appliances/appliance1"))
    {
      if (DEBUG_SW) Serial.print("Relay1 - ");
      if (DEBUG_SW) Serial.println(firebaseData.stringData());

      if (firebaseData.stringData() == "1")
      {
        digitalWrite(R5, HIGH);
      }
      else
      {
        digitalWrite(R5, LOW);
      }
    }


    if (Firebase.getString(firebaseData, "/Appliances/appliance2")) {

      if (DEBUG_SW)  Serial.print("Relay2 - ");
      if (DEBUG_SW)  Serial.println(firebaseData.stringData());
      if (firebaseData.stringData() == "1")
      {
        digitalWrite(R6, HIGH);
      }
      else
      {
        digitalWrite(R6, LOW);
      }

    }

    if (Firebase.getString(firebaseData, "/Appliances/appliance3"))
    {
      if (DEBUG_SW) Serial.print("Relay3 - ");
      if (DEBUG_SW) Serial.println(firebaseData.stringData());

      if (firebaseData.stringData() == "1")
      {
        digitalWrite(R7, HIGH);
      }
      else
      {
        digitalWrite(R7, LOW);
      }

    }

    if (Firebase.getString(firebaseData, "/Appliances/appliance4"))
    {
      if (DEBUG_SW)  Serial.print("Relay4 - ");
      if (DEBUG_SW)  Serial.println(firebaseData.stringData());

      if (firebaseData.stringData() == "1")
      {
        digitalWrite(R8, HIGH);
      }
      else
      {
        digitalWrite(R8, LOW);
      }

    }
  }
}



inline void with_internet()
{
  // FOR SWITCH
  if (digitalRead(S5) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 0 )
    {
      digitalWrite(R5, HIGH);
      if (DEBUG_SW) Serial.println("Relay1- ON");
      String Value1 = "1";
      json.set("/appliance1", Value1);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag1_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch1 -ON");

  }
  if (digitalRead(S5) == HIGH )
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(R5, LOW);
      if (DEBUG_SW) Serial.println("Relay1 OFF");
      String Value1 = "0";
      json.set("/appliance1", Value1);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag1_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch1 OFF");
  }


  if (digitalRead(S6) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 0 )
    {
      digitalWrite(R6, HIGH);
      if (DEBUG_SW)  Serial.println("Relay2- ON");
      String Value2 = "1";
      json.set("/appliance2", Value2);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag2_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch2 -ON");

  }
  if (digitalRead(S6) == HIGH )
  {
    if (switch_ON_Flag2_previous_I == 1)
    {
      digitalWrite(R6, LOW);
      if (DEBUG_SW) Serial.println("Relay2 OFF");
      String Value2 = "0";
      json.set("/appliance2", Value2);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag2_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch2 OFF");
  }

  if (digitalRead(S7) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 0 )
    {
      digitalWrite(R7, HIGH);
      if (DEBUG_SW) Serial.println("Relay3- ON");
      String Value3 = "1";
      json.set("/appliance3", Value3);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag3_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch3 -ON");

  }
  if (digitalRead(S7) == HIGH )
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(R7, LOW);
      if (DEBUG_SW) Serial.println("Relay3 OFF");
      String Value3 = "0";
      json.set("/appliance3", Value3);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag3_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch3 OFF");
  }

  if (digitalRead(S8) == HIGH)
  {
    if (switch_ON_Flag4_previous_I == 0 )
    {
      digitalWrite(R8, HIGH);
      if (DEBUG_SW) Serial.println("Relay4- ON");
      String Value4 = "1";
      json.set("/appliance4", Value4);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag4_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch4 ON");

  }
  if (digitalRead(S8) == LOW )
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(R8, LOW);
      if (DEBUG_SW) Serial.println("Relay4 OFF");
      String Value4 = "0";
      json.set("/appliance4", Value4);
      Firebase.updateNode(firebaseData, "/Appliances", json);
      switch_ON_Flag4_previous_I = 0;
    }
    if (DEBUG_SW) Serial.println("Switch4 OFF");
  }

}
inline void temp_with_internet(){
  if(humidity and temperature){
    json.set("/Humidity",humidity);
    json.set("/Temperature",temperature);
    Firebase.updateNode(firebaseData, "/Appliances", json);
  }
}


inline void without_internet()
{
  // FOR SWITCH
  digitalWrite(R5, !digitalRead(S5));
  digitalWrite(R6, !digitalRead(S6));
  digitalWrite(R7, !digitalRead(S7));
  digitalWrite(R8, !digitalRead(S8));
}
