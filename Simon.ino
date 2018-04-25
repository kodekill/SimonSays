#define LIGHT_1 2    //Red
#define LIGHT_2 3    //Yellow
#define LIGHT_3 4    //White
#define LIGHT_4 5    //Red

#define BUTTON_1 8   //Red
#define BUTTON_2 9   //Yellow
#define BUTTON_3 10  //White
#define BUTTON_4 11  //Red

#define PIEZO 12


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
    tone(PIEZO, 8000);
  }

  
  if(button2state == HIGH){
    Serial.println("Button2 ON");
  }

  
  if(button3state == HIGH){
    Serial.println("Button3 ON");
  }

  
  if(button4state == HIGH){
    Serial.println("Button4 ON");
  }


  if((button1state && button2state && button3state && button4state) == LOW){
    noTone(PIEZO);
  }

}
