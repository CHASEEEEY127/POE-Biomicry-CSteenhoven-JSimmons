//now added to github

int ticksPerSecond =250;

int waitTime = 2;
int waitTicks=waitTime*ticksPerSecond;
int waitTimer=0;

int ballWaitTime=5;
int ballWaitTimer=-1;
int ballWaitTicks=ballWaitTime*ticksPerSecond;
int ballFlashFrequency=50;
bool ballMod=false;
bool canBall=true;

int threshHold= 35;
int happyPin = 23;

int ballTouchPin=4;
int ballPin=22;

bool detectPins(int thresh){
  if(touchRead(15)<thresh||touchRead(13)<thresh||touchRead(12)<thresh||touchRead(14)<thresh||touchRead(33)<thresh||touchRead(32)<thresh||touchRead(27)<thresh)
  {return true;}
  else{
    return false;
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(happyPin,OUTPUT);
  pinMode(ballTouchPin,INPUT);
  pinMode(ballPin,OUTPUT);
  pinMode(15,INPUT);
  pinMode(13,INPUT);
  pinMode(15,INPUT);
  pinMode(12,INPUT);
  pinMode(14,INPUT);
  pinMode(33,INPUT);
  pinMode(32,INPUT);
  pinMode(27,INPUT);


}

void loop() {
  //Serial.println(waitTimer);
  Serial.println(touchRead(4));
  if(detectPins(threshHold)){
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

  Serial.print("canball: ");
  Serial.println(canBall);
  Serial.print("ballMod: ");
  Serial.println(ballMod);
  Serial.print("ballTime:");
  Serial.println(ballWaitTimer);

  if(!ballMod){
    if(touchRead(ballTouchPin)<threshHold){
    if(canBall){
      ballMod=true;
      canBall=false;
      }
    }
      digitalWrite(ballPin,LOW);
  }
  if(touchRead(ballTouchPin)>threshHold){
    canBall=true;
  }
  
  if(ballMod){
    ballWaitTimer++;
    if(ballWaitTimer%ballFlashFrequency<ballFlashFrequency/2){
      digitalWrite(ballPin,HIGH);
    }
    else{digitalWrite(ballPin,LOW);}
  }

  if(ballWaitTimer>ballWaitTicks){
      ballMod=false;
      ballWaitTimer=-1;
    }
  
  
  
}