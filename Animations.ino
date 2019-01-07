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
      delay(100);
      break;

    case 2: //BLUE
      digitalWrite(LIGHT_2, HIGH);
      tone(PIEZO, PITCH_2);
      delay(delayTime * mySpeed);
      lightSoundOff();
      delay(100);
      break;

    case 3: //YELLOW
      digitalWrite(LIGHT_3, HIGH);
      tone(PIEZO, PITCH_3);
      delay(delayTime * mySpeed);
      lightSoundOff();
      delay(100);
      break;

    case 4: //GREEN
      digitalWrite(LIGHT_4, HIGH);
      tone(PIEZO, PITCH_4);
      delay(delayTime * mySpeed);
      lightSoundOff();   
      delay(100);
      break;
  } 
}


/**
 *Takes x (a button) as input and turns on it's accompanying LED.(NO SOUND) 
 */
void lightMute(int x, float mySpeed){
  switch (x){
    case 1: //RED
      digitalWrite(LIGHT_1, HIGH);
      delay(delayTime * mySpeed);
      offAll();
      delay(100);
      break;

    case 2: //BLUE
      digitalWrite(LIGHT_2, HIGH);
      delay(delayTime * mySpeed);
      offAll();
      delay(100);
      break;

    case 3: //YELLOW
      digitalWrite(LIGHT_3, HIGH);
      delay(delayTime * mySpeed);
      offAll();
      delay(100);
      break;

    case 4: //GREEN
      digitalWrite(LIGHT_4, HIGH);
      delay(delayTime * mySpeed);
      offAll();
      delay(100);
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
void startMode1(){
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
  delay(750);
}


/**
 * Animation for Mode 2 startup
 */
void startMode2(){
  //Turn on all lights one at a time, Twice
  for(int y = 0; y < 2; y++){
    for(int x = 0; x < 4; x++){
      digitalWrite(lightArray[x], HIGH);
      delay(45);
    }
    delay(150);
    offAll();
  }

  //Turn all lights on
  lightAll();
  delay(150);

  //Slowly turn off all lights at the same time
  for(int brightness = 250; brightness >= 0; brightness--){
    for(int x = 0; x < 4; x++){
      analogWrite(lightArray[x], brightness);
    }
    delay(2);
  }
  
  offAll();
  delay(750);
}


/**
 * Animation for failed input, resets game
 */
void failSound(){
  //Serial.println("You Failed, starting over");
  for(int i = 0; i < 2; i++){
    lightAll();
    tone(PIEZO, FAIL_SOUND); 
    delay(300);

    offAll();
    noTone(PIEZO);
    delay(150);
  }

  delay(200);
  resetFunc();
}


/**
 * Animation for failed input, resets game (NO SOUND)
 */
void failMute(){
  //Serial.println("You Failed, starting over");
  for(int i = 0; i < 2; i++){
    lightAll();
    delay(300);

    offAll();
    delay(150);
  }

  delay(200);
  resetFunc();
}
