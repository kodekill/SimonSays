/**
 *Takes x (a button) as input and turns on it's accompanying LED and tone. 
 */
void lightSound(int x, float mySpeed){
  switch (x){
    case 1: //RED
      digitalWrite(LIGHT_1, HIGH);
      tone(PIEZO, PITCH_1);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 2: //BLUE
      digitalWrite(LIGHT_2, HIGH);
      tone(PIEZO, PITCH_2);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 3: //YELLOW
      digitalWrite(LIGHT_3, HIGH);
      tone(PIEZO, PITCH_3);
      delay(delayTime * mySpeed);
      lightSoundOff();
      break;

    case 4: //GREEN
      digitalWrite(LIGHT_4, HIGH);
      tone(PIEZO, PITCH_4);
      delay(delayTime * mySpeed);
      lightSoundOff();   
      break;
  } 
}


/**
 * Turn off all audio and visual
 */
void lightSoundOff(){
  offAll();
  noTone(PIEZO);
  delay(100);
}


/**
 * Turn all lights on
 */
void lightAll(){
  digitalWrite(LIGHT_1, HIGH);
  digitalWrite(LIGHT_2, HIGH);
  digitalWrite(LIGHT_3, HIGH);
  digitalWrite(LIGHT_4, HIGH);
}


/**
 * Turn all lights off
 */
void offAll(){
  digitalWrite(LIGHT_1, LOW);
  digitalWrite(LIGHT_2, LOW);
  digitalWrite(LIGHT_3, LOW);
  digitalWrite(LIGHT_4, LOW);
}


/**
 * Animation for Mode 1 startup
 */
void startLights(){
  //Turn on all lights one at a time
  for(int x = 0; x < 4; x++){
    digitalWrite(lightArray[x], HIGH);
    delay(110);
  }
  delay(200);

  //Turn all lights off
  offAll();
  delay(100);

  //Slowly turn on all lights at the same time
  for(int brightness = 0; brightness <= 200; brightness++){
    for(int x = 0; x < 4; x++){
      analogWrite(lightArray[x], brightness);
      delay(1);
    }
  }
  offAll();
}


/**
 * Animation for failed input, resets game
 */
void failInput(){
  Serial.println("You Failed, starting over");
  for(int i = 0; i < 2; i++){
    lightAll();
    tone(PIEZO, FAIL_SOUND); 
    delay(300);

    offAll();
    noTone(PIEZO);
    delay(150);
  }
  resetFunc();
}
