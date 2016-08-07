char cmd[7];
byte cmdIndex=0;
byte MAX_CMD_LENGTH=6;
String data;

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38
#define X_SLEEP 50

void move_motor(){
 digitalWrite(X_DIR_PIN,LOW);
 digitalWrite(X_STEP_PIN,LOW);
 delayMicroseconds(X_SLEEP);
 digitalWrite(X_STEP_PIN,HIGH);  
}

void setup() {
 Serial.begin(250000);
 pinMode(X_STEP_PIN,OUTPUT);
 pinMode(X_DIR_PIN,OUTPUT);
 pinMode(X_ENABLE_PIN,OUTPUT);
 digitalWrite(X_ENABLE_PIN,LOW); 
}

void loop() {
 if(Serial.available()) {   
  char byteIn=Serial.read();
  cmd[cmdIndex]=byteIn;   
  if(byteIn==';'){
   cmd[cmdIndex]='\0';
   cmdIndex=0;
   for(int i=0;i<3200;i++){move_motor();}
   if(strcmp(cmd,"0121")==0)
    Serial.print(1);
   else Serial.print(2);

  }else{
   if(cmdIndex++>=MAX_CMD_LENGTH) cmdIndex=0;
  }
 }
}

