#define LIGHT_1 2    //Red
#define LIGHT_2 3    //Yellow
#define LIGHT_3 4    //White
#define LIGHT_4 5    //Red

#define BUTTON_1 8   //Red
#define BUTTON_2 9   //Yellow
#define BUTTON_3 10  //White
#define BUTTON_4 11  //Red

#define PIEZO 12
int delayTime = 750; 

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
}

void loop() {
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
