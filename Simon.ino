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
StackList<int> Rstack; //read stack
StackList<int> copy;

int delayTime = 375;
int MAX_ARRAY = 50;
int myArray[50];
int roundScore = 1; //How many iterations made
int myCount = 0;    //Used for Stack Length
int input = 0; 
float mySpeed = 2;
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
  successInput();
}

void(* resetFunc) (void) = 0; //Reset

void loop() {
  //Serial.println("\n\nLoop");
  //addStack();
  
  //Serial.println(stack.peek());
  //readStack();

  //Serial.print("My input = ");
  //Serial.println(input);

  buttonPressCheck();
  while(checkFlag == true){
    answer();
  }

  roundScore++;
}





void answer(){
  int compareItem = stack.pop();
  input = buttonPressCheck();

  while(input != 0){
    if(compareItem == input){
      //Serial.println("You got it right"); 
      checkFlag = false;
      input = 0;
      break;
    }
    if(compareItem != input){
      //Serial.println("You got it wrong");
      checkFlag = false;
      input = 0;
      failInput();
    }
    break;
  }
}


int buttonPressCheck(){
  int button1state = digitalRead(BUTTON_1);
  int button2state = digitalRead(BUTTON_2);
  int button3state = digitalRead(BUTTON_3);
  int button4state = digitalRead(BUTTON_4);
  mySpeed = 1.2; 

  if(button1state == true){
    lightSound(1, mySpeed);
    input = 1;
    checkFlag = true;
  }
  if(button2state == true){
    lightSound(2, mySpeed);
    input = 2;
    checkFlag = true;
  }
  if(button3state == true){
    lightSound(3, mySpeed);
    input = 3;
    checkFlag = true;
  }  
  if(button4state == true){
    lightSound(4, mySpeed);
    input = 4;
    checkFlag = true;
  }
//  Serial.print("input = ");
//  Serial.println(input);
//  
//  Serial.print("checkFlag = ");
//  Serial.println(checkFlag);
  
  return input;
}
























void addStack(){
    int myRandom = random(1,5);
    stack.push(myRandom);
    Serial.print("Pushing ");
    Serial.print(myRandom);
    Serial.println(" to the stack");
    copy = stack;
    checkFlag = true;
}


void readStack(){
  Rstack = copy;
  myCount = Rstack.count();
  Serial.print("My stack size = ");
  Serial.println(myCount);
  
  for(int i = 0; i < myCount; i++){
      int x = Rstack.pop();
      Serial.print("Popping ");
      Serial.print(x);
      Serial.println(" off");
      lightSound(x, mySpeed);
  }
  Serial.println("stack is now empty");
  lightAll();
  lightSoundOff();
}


void failInput(){
  for(int i = 0; i < 2; i++){
    digitalWrite(LIGHT_1, HIGH);
    digitalWrite(LIGHT_2, HIGH);
    digitalWrite(LIGHT_3, HIGH);
    digitalWrite(LIGHT_4, HIGH);
    tone(PIEZO, 2000); 
    delay(300);

    digitalWrite(LIGHT_1, LOW);
    digitalWrite(LIGHT_2, LOW);
    digitalWrite(LIGHT_3, LOW);
    digitalWrite(LIGHT_4, LOW);
    noTone(PIEZO);
    delay(150);
  }
  resetFunc();
}


void successInput(){
  float mySpeed = .25;

  for(int i = 1; i <= 4; i++){
    lightSound(i, mySpeed);
  }
  for(int i = 3; i >= 2; i--){
    lightSound(i, mySpeed);
  }
  lightSound(1, mySpeed*2.5);
}


void lightSound(int x, float mySpeed){
  switch (x){
    case 1:
      digitalWrite(LIGHT_1, HIGH);
      tone(PIEZO, 3000);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 2:
      digitalWrite(LIGHT_2, HIGH);
      tone(PIEZO, 4000);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 3:
      digitalWrite(LIGHT_3, HIGH);
      tone(PIEZO, 5000);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 4:
      digitalWrite(LIGHT_4, HIGH);
      tone(PIEZO, 6000);
      delay(delayTime * mySpeed);
      lightSoundOff();   
      break;
  } 
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



