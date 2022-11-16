#include<WiFi.h>
#include<HTTPClient.h>

const char ssid[]="cc123"; //修改為你家的WiFi網路名稱
const char pwd[]="123456cc"; //修改為你家的WiFi密碼

String HOST_NAME="http://192.168.100.217"; //修改為你電腦的IP
String PATH_NAME="/espImport.php"; //修改為PHP的檔案路徑
String queryString;
String sentences;

String n[14]={"0","0","0","0","0","0","0","0","0","0","0","0","0","0"};

void send(){
  HTTPClient http;
  http.begin(HOST_NAME + PATH_NAME + queryString); //HTTP
  int httpCode = http.GET();
  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  }
void setup() {
  Serial.begin(115200);
  pinMode(19,INPUT);
  pinMode(18,INPUT);
  pinMode(17,INPUT);
  pinMode(16,INPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);
  pinMode(15,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(13,INPUT);
  pinMode(32,INPUT);
  pinMode(22,INPUT);
  pinMode(14,INPUT);
  pinMode(21,INPUT);
  pinMode(33,OUTPUT);
  
  
  WiFi.mode(WIFI_STA); //設置WiFi模式ss
  WiFi.begin(ssid,pwd);
  Serial.print("WiFi connecting");
}
void loop() { 
    //當WiFi連線時會回傳WL_CONNECTED，因此跳出迴圈時代表已成功連線
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("IP位址:");
  Serial.println(WiFi.localIP()); //讀取IP位址
  
  if (digitalRead(22) == false)
    {
      n[0]="0";
    }
    else
    n[0]="1";
  if (digitalRead(21) == false)
    {
      n[1]="0";
    }
    else
    n[1]="1";
  if (digitalRead(19) == false)
    {
      n[2]="0";
    }
    else
    n[2]="1";
  if (digitalRead(18) == false)
    {
      n[3]="0";
    }
    else
    n[3]="1";
  if (digitalRead(17) == false)
    {
      n[4]="0";
    }
    else
    n[4]="1";
  if (digitalRead(16) == false)
    { 
      n[5]="0";
    }
    else
    n[5]="1";
  if (digitalRead(4) == false)
    {
      n[6]="0";
    }
    else
    n[6]="1";
  if (digitalRead(2) == false)
    {
      n[7]="0";
    }
    else
    n[7]="1";
  if (digitalRead(15) == false)
    {
      n[8]="0";
    }
    else
    n[8]="1";
  if (digitalRead(32) == false)
    {
      n[9]="0";
    }
    else
    n[9]="1";
  if (digitalRead(25) == false)
    {
      n[10]="0";
    }
    else
    n[10]="1";
  if (digitalRead(26) == false)
    {
      n[11]="0";
    }
    else
    n[11]="1";
  if (digitalRead(14) == false)
    {
      n[12]="0";
    }
    else
    n[12]="1";
  if (digitalRead(13) == false)
    {
      n[13]="0";
    }
    else
    n[13]="1";
  
    
  for(int i=0;i<14;i++)
  {
    sentences=sentences+n[i]+",";
    if(n[i]=="1")
    {
      digitalWrite(33,HIGH);
      }
  }
  sentences+=n[13];
  queryString="?DataPack="+sentences;
  send();
  queryString="";
  sentences="";
  delay(2000);
}
