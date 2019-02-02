#include <ESP8266WiFi.h>
WiFiClient client;

const int buttonPin = 16;   // D0  the number of the pushbutton pin
int buttonState = 0; // variable for reading the pushbutton status

String MakerIFTTT_Key ;
String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);

   WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("Hackathon","cse123456");  
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");
  }
Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  
  if(digitalRead(16)==HIGH)
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }

  if(digitalRead(LED_BUILTIN)==HIGH)
  {  
      if (client.connect("maker.ifttt.com",80)) {
    MakerIFTTT_Key ="c_p1EmEqMCSY-VY-C0dML8";
    MakerIFTTT_Event ="Sms";
    p = post_rqst;
    p = append_str(p, "POST /trigger/");
    p = append_str(p, MakerIFTTT_Event);
    p = append_str(p, "/with/key/");
    p = append_str(p, MakerIFTTT_Key);
    p = append_str(p, " HTTP/1.1\r\n");
    p = append_str(p, "Host: maker.ifttt.com\r\n");
    p = append_str(p, "Content-Type: application/json\r\n");
    p = append_str(p, "Content-Length: ");
    content_length_here = p;
    p = append_str(p, "NN\r\n");
    p = append_str(p, "\r\n");
    json_start = p;
    p = append_str(p, "{\"value1\":\"");
    p = append_str(p, "7411562441");
    p = append_str(p, "\",\"value2\":\"");
    p = append_str(p, "13.128889");
    p = append_str(p, "\",\"value3\":\"");
    p = append_str(p, "77.587892");
    p = append_str(p, "\"}");

    compi= strlen(json_start);
    content_length_here[0] = '0' + (compi/10);
    content_length_here[1] = '0' + (compi%10);
    client.print(post_rqst);
  }
  }
}

void loop()
{}
