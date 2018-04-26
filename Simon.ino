#include <StackList.h>

#define LIGHT_1 2    //Red
#define LIGHT_2 3    //Yellow
#define LIGHT_3 4    //White    //Green
#define LIGHT_4 5    //Red      //Blue

#define BUTTON_1 8   //Red
#define BUTTON_2 9   //Yellow
#define BUTTON_3 10  //White    //Green
#define BUTTON_4 11  //Red      //Blue

#define PIEZO 12

StackList<int> stack;

int delayTime = 750;
int MAX_ARRAY = 50;
int myArray[50];
int roundScore = 1;
bool checkFlag = false;


void setup() {
  pinMode(LIGHT_1, OUTPUT);
  pinMode(LIGHT_2, OUTPUT);
  pinMode(LIGHT_3, OUTPUT);
  pinMode(LIGHT_4, OUTPUT);

  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  pinMode(BUTTON_4, INPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  stack.push(1);
  stack.push(2);
  stack.push(3);
}


void loop() {
  //addStack();
  //readStack();
  answer();

  roundScore++;
}

int addStack(){
  for(int j = 0; j < roundScore; j++){
    int myRandom = random(1, 5);
    stack.push(myRandom);
  }
}


void readStack(){
  while(!stack.isEmpty()){
      int x = stack.pop();
      lightSound(x);
  }
  Serial.println("stack is now empty");
  lightAll();
  lightSoundOff();
}


void lightSound(int x){
  switch (x){
    case 1:
      digitalWrite(LIGHT_1, HIGH);
      tone(PIEZO, 3000);
      delay(delayTime);
      lightSoundOff();
      break;

    case 2:
      digitalWrite(LIGHT_2, HIGH);
      tone(PIEZO, 4000);
      delay(delayTime);
      lightSoundOff();
      break;

    case 3:
      digitalWrite(LIGHT_3, HIGH);
      tone(PIEZO, 5000);
      delay(delayTime);
      lightSoundOff();
      break;

    case 4:
      digitalWrite(LIGHT_4, HIGH);
      tone(PIEZO, 6000);
      delay(delayTime);
      lightSoundOff();   
      break;
  } 
}


void answer(){
  

  
}


void lightSoundOff(){
  digitalWrite(LIGHT_1, LOW);
  digitalWrite(LIGHT_2, LOW);
  digitalWrite(LIGHT_3, LOW);
  digitalWrite(LIGHT_4, LOW);

  noTone(PIEZO);
  delay(100);
}


void lightAll(){
  digitalWrite(LIGHT_1, HIGH);
  digitalWrite(LIGHT_2, HIGH);
  digitalWrite(LIGHT_3, HIGH);
  digitalWrite(LIGHT_4, HIGH);
  delay(1000);
}















void test() {
  digitalWrite(LIGHT_1, HIGH);
  digitalWrite(LIGHT_2, HIGH);
  digitalWrite(LIGHT_3, HIGH);
  digitalWrite(LIGHT_4, HIGH);

  int button1state = digitalRead(BUTTON_1);
  int button2state = digitalRead(BUTTON_2);
  int button3state = digitalRead(BUTTON_3);
  int button4state = digitalRead(BUTTON_4);

  if(button1state == HIGH){
    Serial.println("Button1 ON");
    digitalWrite(LIGHT_1, LOW);
    tone(PIEZO, 8000);
    delay(delayTime);
    noTone(PIEZO);
  }

  
  if(button2state == HIGH){
    Serial.println("Button2 ON");
    digitalWrite(LIGHT_2, LOW);
    tone(PIEZO, 9000);
    delay(delayTime);
    noTone(PIEZO);
  }

  
  if(button3state == HIGH){
    Serial.println("Button3 ON");
    digitalWrite(LIGHT_3, LOW);
    tone(PIEZO, 10000);
    delay(delayTime);
    noTone(PIEZO);
  }

  
  if(button4state == HIGH){
    Serial.println("Button4 ON");
    digitalWrite(LIGHT_4, LOW);
    tone(PIEZO, 11000);
    delay(delayTime);
    noTone(PIEZO);
  }
  
}



