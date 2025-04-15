#include <SoftwareSerial.h>

#include <DFRobotDFPlayerMini.h>

int human_bark_a = 1;
int dog_bark_a = 2;
int sexy_sax = 3;
int dog_bark_b=4;
int dog_bark_c=5;
int dog_bark_d=6;
int dog_bark_e=7;

int barkCount=5;
int barks[5]={2,4,5,6,7};
int currentBark=0;
DFRobotDFPlayerMini player;
SoftwareSerial digiSiri(16,17);



void bark(int id=0){
if(id!=0){
  player.play(id);
}
else{
  player.play(barks[currentBark%barkCount]);
  currentBark++;
}

}

void setup() {
digiSiri.begin(9600);
Serial.begin(300);

player.begin(digiSiri);
player.volume(25);
}

void loop() {
  bark();
  delay(10000);
  Serial.println(currentBark);
}
