#define PIEZO 2

#define LIGHT_1 3    //Red
#define LIGHT_2 5    //Blue
#define LIGHT_3 6    //Yellow
#define LIGHT_4 9    //Green

#define BUTTON_1 4   //Red
#define BUTTON_2 7   //Blue
#define BUTTON_3 8   //Yellow
#define BUTTON_4 10  //Green

#define PITCH_1 500   //Red
#define PITCH_2 700   //Blue
#define PITCH_3 900   //Yellow
#define PITCH_4 1000  //Green
#define FAIL_SOUND 250

#include <QueueArray.h>
QueueArray <int> queue;
QueueArray <int> myCopy;
QueueArray <int> Rstack; //read stack

int delayTime = 375;
int MAX_ARRAY = 50;
int myArray[50];
int roundScore = 1; //How many iterations made
int myCount = 0;    //Used for Stack Length
int input = 0; 
float mySpeed = 2;
bool checkFlag = false;
void(* resetFunc) (void) = 0; //Reset function
int lightArray[] = {LIGHT_1, LIGHT_2, LIGHT_3, LIGHT_4};

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
  Serial.println("Starting....");
  randomSeed(analogRead(0));

//  startLights();
//  delay(750);
}


void loop(){
  //mode1();
  mode2();
}
