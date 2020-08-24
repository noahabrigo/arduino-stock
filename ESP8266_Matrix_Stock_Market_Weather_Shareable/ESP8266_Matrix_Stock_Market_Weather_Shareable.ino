//This project uses finnhub and openweathermap. in order to use this project, you must go
//to the respective websites and get access keys. find any spot in the code that says YOUR_FINNHUB_KEY or YOUR_OPENWEATHER_ID 
//found near the bottom of this document. Fill in the access keys in the code and
// edit the location of the weather and customize your stock preferences.
// MAKE SURE TO CHANGE THE WIFI SSID AND PASSWORD AS WELL!

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include "letters.cpp"
#include <NTPClient.h>
#include <PxMatrix.h>
#include <Ticker.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiUdp.h>

#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

String data;
struct Stock{
  String symbol;
  String change;
  String price;
  uint8_t len;
};
Stock stocks[7] = {
  {"DJI","","",0},
  {"NASDAQ","","",0},
  {"NYSE","","",0},
  {"S&P","","",0},
  {"GM","","",0},
  {"AMZN","","",0},
  {"GOOGL","","",0},
};
struct Weather{
  String cond;
};
Weather forecast;

Ticker display_ticker;
Ticker scroll;

PxMATRIX display(64,16,P_LAT, P_OE,P_A,P_B,P_C);
uint8_t display_draw_time=20;
void display_updater()
{
  display.display(display_draw_time);
}
void display_update_enable(bool is_enable){
  display_ticker.attach(0.002, display_updater); 
}

ESP8266WiFiMulti WiFiMulti;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
bool startup = true;
String hours;
String minutes;
String seconds;
uint8_t day;
bool weekday(){ return day > 0 && day < 6; }
bool shutoff(){
  float dTime = (float)timeClient.getHours() + (float)timeClient.getMinutes()/60;
  return (dTime >= 17 && dTime < 24) || (dTime >= 0 && dTime < 9.5);
}
bool marketHours(){
  float dTime = (float)timeClient.getHours() + (float)timeClient.getMinutes()/60;
  return (dTime >= 9.5 && dTime <= 16.25);
}


const uint8_t fingerprint[20] = {0xEA,0xD5,0x0B,0x47,0x7C,0xD9,0xAC,0xCA,0x37,0x59,0x85,0xBD,0xE8,0x66,0x31,0x07,0x2D,0xF5,0x65,0x4C};
const uint8_t fingerprintwx[20] = {0x07,0xE3,0x28,0x64,0x91,0x8F,0x42,0x38,0xA0,0x54,0x2A,0x2C,0xCD,0xC1,0x7C,0x98,0x79,0x8C,0xA1,0xD8};

int16_t incx[3] = {64,64,64};
void scrollx(){
    if(incx[0] == - stocks[0].len - stocks[1].len - stocks[2].len - stocks[3].len - stocks[4].len - stocks[5].len - stocks[6].len){
      incx[0] = 64;
    }else{
      incx[0]--;
    }

    if(incx[1] == -forecast.cond.length()*6){
      incx[1] = 32;
    }else{
      incx[1]--;
    }

    if(incx[2] == -forecast.cond.length()*6){
      incx[2] = 64;
    }else{
      incx[2]--;
    }
}

uint8_t find_letter (char letter){
  if(letter == 'A' || letter == 'a'){
    return 1;
  }else if(letter == 'B' || letter == 'b'){
    return 2;
  }else if(letter == 'C' || letter == 'c'){
    return 3;
  }else if (letter == 'D' || letter == 'd'){
    return 4;
  }else if (letter == 'E' || letter == 'e'){
    return 5;
  }else if (letter == 'F' || letter == 'f'){
    return 6;
  }else if (letter == 'G' || letter == 'g'){
    return 7;
  }else if (letter == 'H' || letter == 'h'){
    return 8;
  }else if (letter == 'I' || letter == 'i'){
    return 9;
  }else if (letter == 'J' || letter == 'j'){
    return 10;
  }else if (letter == 'K' || letter == 'k'){
    return 11;
  }else if (letter == 'L' || letter == 'l'){
    return 12;
  }else if (letter == 'M' || letter == 'm'){
    return 13;
  }else if (letter == 'N' || letter == 'n'){
    return 14;
  }else if (letter == 'O' || letter == 'o'){
    return 15;
  }else if (letter == 'P' || letter == 'p'){
    return 16;
  }else if (letter == 'Q' || letter == 'q'){
    return 17;
  }else if (letter == 'R' || letter == 'r'){
    return 18;
  }else if (letter == 'S' || letter == 's'){
    return 19;
  }else if (letter == 'T' || letter == 't'){
    return 20;
  }else if (letter == 'U' || letter == 'u'){
    return 21;
  }else if (letter == 'V' || letter == 'v'){
    return 22;
  }else if (letter == 'W' || letter == 'w'){
    return 23;
  }else if (letter == 'X' || letter == 'x'){
    return 24;
  }else if (letter == 'Y' || letter == 'y'){
    return 25;
  }else if (letter == 'Z' || letter == 'z'){
    return 26;
  }else if (letter == '0'){
    return 27;
  }else if (letter == '1'){
    return 28;
  }else if (letter == '2'){
    return 29;
  }else if (letter == '3'){
    return 30;
  }else if (letter == '4'){
    return 31;
  }else if (letter == '5'){
    return 32;
  }else if (letter == '6'){
    return 33;
  }else if (letter == '7'){
    return 34;
  }else if (letter == '8'){
    return 35;
  }else if (letter == '9'){
    return 36;
  }else if (letter == '+'){
    return 37;
  }else if (letter == '-'){
    return 38;
  }else if (letter == '.'){
    return 39;
  }else if (letter == '&'){
    return 40;
  }else if (letter == ':'){
    return 41;
  }else if(letter == '`'){
    return 42;
  }else{
    return 43;
  }
}

void draw_letter(char letter, const uint16_t & color, int16_t offsetx, int16_t offsety, int8_t xrangeL, int8_t xrangeR, int8_t ydomainL, int8_t ydomainR){
  uint16_t y = 0;
  uint16_t x = 0;
  uint8_t letterOffset = find_letter(letter);
  for(int i = 35*(letterOffset-1); i < 35*letterOffset; i++){
    if(font[i] && (x+offsetx <=xrangeR && x+offsetx >= xrangeL) && (y+offsety <= ydomainR && y+offsety >= ydomainL)){
      display.drawPixel(x+offsetx,y+offsety,color); 
    }
    if(x == 4){
      x = 0;
      y++;
    }else{
      x++;
    }
    
  }
}

void wrt(String text, const uint16_t & color,int16_t offsetx, int16_t offsety, int8_t xrangeL, int8_t xrangeR, int8_t ydomainL, int8_t ydomainR){
  for(int i = 0; i < text.length(); i++){
    draw_letter(text[i], color, i*6+offsetx, offsety, xrangeL, xrangeR, ydomainL, ydomainR);
  }
}

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("YOUR_SSID", "YOUR_PASSWORD");

  while ( (WiFiMulti.run() != WL_CONNECTED) ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();

  display.begin(8);
  display.setFastUpdate(true);
  display.setPanelsWidth(2);
  display.setBrightness(127);
  display.clearDisplay();
  display_update_enable(true);
  scroll.attach(0.05, scrollx);
}

void loop() {

  if(timeClient.getSeconds() == 0 || startup){
    if((timeClient.getMinutes() % 5) == 0 || startup){
      
      timeClient.update();
      updateData(); 
    }
    if(timeClient.getHours() > 12){
    hours = (String)(timeClient.getHours()-12);
    }else if(timeClient.getHours() == 0){
      hours = "12";
    }
    else{
      hours = (String)timeClient.getHours(); 
    }
    if(timeClient.getMinutes() < 10){
      minutes = "0";
      minutes += (String)timeClient.getMinutes();
    }else{
      minutes = (String)timeClient.getMinutes();
    }
    seconds = (String)timeClient.getSeconds();
    day = timeClient.getDay();
    startup = false;
  }
  
  display.clearDisplay();
  
  if(!shutoff() && weekday()){
    showStock(stocks[0],incx[0],9,0,64,9,16);
    showStock(stocks[1],incx[0] + stocks[0].len,9,0,64,9,16);
    showStock(stocks[2],incx[0] + stocks[0].len + stocks[1].len,9,0,64,9,16);
    showStock(stocks[3],incx[0] + stocks[0].len + stocks[1].len + stocks[2].len,9,0,64,9,16);
    showStock(stocks[4],incx[0] + stocks[0].len + stocks[1].len + stocks[2].len + stocks[3].len,9,0,64,9,16);
    showStock(stocks[5],incx[0] + stocks[0].len + stocks[1].len + stocks[2].len + stocks[3].len + stocks[4].len,9,0,64,9,16);
    showStock(stocks[6],incx[0] + stocks[0].len + stocks[1].len + stocks[2].len + stocks[3].len + stocks[4].len + stocks[5].len,9,0,64,9,16);
  }

  if(!shutoff()){
    wrt(hours, display.color565(255, 255, 255), 0, 0, 0, 32, 0, 8);
    draw_letter(':', display.color565(255, 255, 255), hours.length()*6, 0, 0, 32, 0, 8);
    wrt(minutes, display.color565(255, 255, 255), hours.length()*6 + 6, 0, 0, 32, 0, 8);
    
    wrt(forecast.cond, display.color565(255, 255, 255), incx[1]+32, 0, 32, 64, 0, 8);
  }else{
    wrt(hours, display.color565(255, 255, 255), 17, 0, 0, 64, 0, 8);
    draw_letter(':', display.color565(255, 255, 255), 17+hours.length()*6, 0, 0, 64, 0, 8);
    wrt(minutes, display.color565(255, 255, 255), 17+hours.length()*6 + 6, 0, 0, 64, 0, 8);

    wrt(forecast.cond, display.color565(255, 255, 255), incx[2], 9, 0, 64, 9, 16);
  }
}

void showStock(const Stock & stock, uint16_t offsetx, uint16_t offsety, uint8_t xrangeL, uint8_t xrangeR, uint8_t ydomainL, uint8_t ydomainR){
  wrt(stock.symbol, display.color565(0, 0, 255), offsetx, offsety, xrangeL, xrangeR, ydomainL, ydomainR);
  if(stock.change[0] == '-'){
    wrt(stock.change, display.color565(255, 0, 0), offsetx + stock.symbol.length()*letter_width + spacing, offsety, xrangeL, xrangeR, ydomainL, ydomainR); 
  }else{
    wrt(stock.change, display.color565(0, 255, 0), offsetx + stock.symbol.length()*letter_width + spacing, offsety,xrangeL, xrangeR, ydomainL, ydomainR);
  }
  wrt(stock.price, display.color565(255, 255, 255), offsetx + stock.symbol.length()*letter_width + stock.change.length()*letter_width + spacing*2, offsety,xrangeL, xrangeR, ydomainL, ydomainR);
}


bool getData(String & data, String link, const uint8_t fingerprint[20]){
    if ((WiFiMulti.run() == WL_CONNECTED)) {

    if(fingerprint != NULL){

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    HTTPClient https;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, link)) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          data = https.getString();
          return true;
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
        return false;
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
      return false;
    }
    
    }else{
      WiFiClient client;

      HTTPClient http;

      Serial.print("[HTTP] begin...\n");
      if (http.begin(client, link)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          data = http.getString();
          return true;
            }
          } else {
            return false;
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
          }
    
          http.end();
        } else {
          Serial.printf("[HTTP} Unable to connect\n");
          return false;
        }
    }
    
  }
}

void finnhubParse(Stock & stock, const String & data){
  const size_t capacity = JSON_OBJECT_SIZE(6) + 20;
  DynamicJsonDocument doc(capacity);

  const char* json = data.c_str();

  deserializeJson(doc, json);

  float c = doc["c"]; // 24138.59
  float h = doc["h"]; // 24512.24
  float l = doc["l"]; // 24031.2
  float o = doc["o"]; // 24357.17
  float pc = doc["pc"]; // 24133.78
  long t = doc["t"]; // 1588092199
  
  String schange;
  float change = c - pc;
  if(change < 0){
    schange = "";
  }else{
    schange = "+";
  }

  schange += change;

  stock.change = schange;
  stock.price = (String)c;

  stock.len = stock.symbol.length()*letter_width + stock.change.length()*letter_width + stock.price.length()*letter_width + 2*spacing + end_space;
}

void weatherParse(Weather & weather, const String & data){
  const size_t capacity = JSON_ARRAY_SIZE(1) + 2*JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(14) + 300;
DynamicJsonDocument doc(capacity);

  const char* json = data.c_str();

  deserializeJson(doc, json);

  //float coord_lon = doc["coord"]["lon"]; // -83.83
  //float coord_lat = doc["coord"]["lat"]; // 42.96
  
  JsonObject weather_0 = doc["weather"][0];
  //int weather_0_id = weather_0["id"]; // 500
  const char* weather_0_main = weather_0["main"]; // "Rain"
  const char* weather_0_description = weather_0["description"]; // "light rain"
  //const char* weather_0_icon = weather_0["icon"]; // "10d"
  
  const char* base = doc["base"]; // "stations"
  
  JsonObject main = doc["main"];
  float main_temp = main["temp"]; // 287.87
  float main_feels_like = main["feels_like"]; // 282.73
  float main_temp_min = main["temp_min"]; // 287.04
  float main_temp_max = main["temp_max"]; // 289.15
  int main_pressure = main["pressure"]; // 999
  int main_humidity = main["humidity"]; // 77
  
  /*int visibility = doc["visibility"]; // 16093
  
  JsonObject wind = doc["wind"];
  float wind_speed = wind["speed"]; // 7.7
  int wind_deg = wind["deg"]; // 140
  float wind_gust = wind["gust"]; // 11.8
  
  float rain_1h = doc["rain"]["1h"]; // 0.76
  
  int clouds_all = doc["clouds"]["all"]; // 90
  
  long dt = doc["dt"]; // 1588183524
  
  JsonObject sys = doc["sys"];
  int sys_type = sys["type"]; // 1
  int sys_id = sys["id"]; // 4123
  const char* sys_country = sys["country"]; // "US"
  long sys_sunrise = sys["sunrise"]; // 1588156269
  long sys_sunset = sys["sunset"]; // 1588206828*/
  
  int timezone = doc["timezone"]; // -14400
  long id = doc["id"]; // 5011701
  const char* name = doc["name"]; // "Swartz Creek"
  int cod = doc["cod"]; // 200

  float conversion = (9.00/5.00)*(main_temp - 273.15) + 32.00;
  int farenheit = conversion;

  weather.cond = (String)farenheit;
  weather.cond += "`F";
  weather.cond += " ";
  weather.cond += (String)weather_0_description;

  timeClient.setTimeOffset(timezone);
  
}

void updateData(){
  display.clearDisplay();
  display_ticker.detach();
  scroll.detach();
  if((marketHours() && weekday()) || startup){
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=^DJI&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[0], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=^IXIC&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[1], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=^NYA&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[2], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=^GSPC&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[3], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=GM&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[4], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=AMZN&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[5], data);
    while(!getData(data, "https://finnhub.io/api/v1/quote?symbol=GOOGL&token=YOUR_FINNHUB_KEY_HERE", fingerprint)){}
    finnhubParse(stocks[6], data);
  }
  if((timeClient.getMinutes() % 15) == 0 || startup){
    while(!getData(data, "http://api.openweathermap.org/data/2.5/weather?q=YOUR_LOCATION&appid=YOUR_OPENWEATHER_ID", NULL)){}
    weatherParse(forecast, data);
  }
  delay(1000);
  incx[0] = 64;
  incx[1] = 32;
  incx[2] = 64;
  display_ticker.attach(0.002, display_updater);
  scroll.attach(0.05, scrollx);
}
