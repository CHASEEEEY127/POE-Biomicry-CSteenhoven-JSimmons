//now added to github
int waitTime = 2;
int ticksPerSecond =100;
int waitTicks=waitTime*ticksPerSecond;
int waitTimer=0;

int threshHold= 30;
int happyPin = 23;


void setup() {
  Serial.begin(115200);
  pinMode(happyPin,OUTPUT);
  pinMode(4,INPUT);
}

void loop() {

  if(touchRead(4)>threshHold){
    waitTimer=0;
  }
  else{
      waitTimer+=1;
    }

  if(waitTimer>=waitTicks){
    digitalWrite(happyPin,LOW);
  }

  else{
    digitalWrite(happyPin,HIGH);
  }
}