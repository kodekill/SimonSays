/**
 * Checks the user input and determines if its correct or not
 */
void answer(){
  for(int x = 0; x < roundScore; x++){
    int compareItem = queue.at(x);
    input = buttonPressCheck();

    //Loop to give user a chance to input his response
    while(input == 0){
      input = buttonPressCheck();
    }

    //Input was entered, time to check if it's right or not
    while(input != 0){
      
      //Input is good, go another round
      if(compareItem == input){
        //Serial.println("Good"); 
        checkFlag = false;
        input = 0;
        break;
      }
      //Input was wrong, start over
      if(compareItem != input){
        //Serial.println("Bad");
        checkFlag = false;
        input = 0;
        
        if(soundMode){
          failSound();
          break;
        }
        
        failMute();
        break;
      }
    }
  }
  //Serial.println("Answer was right");
  delay(250);
}


/**
 * Beep and blink the saved queue for mode 2
 */
void blinkQueue(){
  for(int y = 0; y < queue.size(); y++){
      if(soundMode){
        lightSound(queue.at(y), mySpeed);
        delay(100);       
      }

      if(!soundMode){
        lightMute(queue.at(y), mySpeed);
        delay(100);   
      }
  }
}


/**
 * This function beeps and blinks the user input as it is being entered.
 */
int buttonPressCheck(){
  int button1state = digitalRead(BUTTON_1);
  int button2state = digitalRead(BUTTON_2);
  int button3state = digitalRead(BUTTON_3);
  int button4state = digitalRead(BUTTON_4);

  if(button1state == true){
    input = 1;
  }
  if(button2state == true){
    input = 2;
  }
  if(button3state == true){
    input = 3;
  }  
  if(button4state == true){
    input = 4;
  }

  if(soundMode){
    lightSound(input, mySpeed);
    checkFlag = true;
    return input;
  }
  
  lightMute(input, mySpeed);
  checkFlag = true;
  return input;
}


/**
 * Print queue for Serial monitor
 */
void printQueue(){
  Serial.print("\nQueue = ");
  for(int y = 0; y < queue.size(); y++){
    Serial.print(queue.at(y));
    Serial.print(" ");
  }
}


void read_eeprom(){
  soundMode = EEPROM.read(addr1);
  Serial.print("Sound Mode = ");
  Serial.println(soundMode);
  
  gameMode = EEPROM.read(addr2);
  Serial.print("Game Mode = ");
  Serial.println(gameMode);

  //Make sure modes fall into acceptable state
  clampModes();
}


void startupInput(){
  
  int soundSetting = digitalRead(BUTTON_1); //Red
  int gameSetting = digitalRead(BUTTON_4); //Green

  //Red Button is Pressed     SOUND
  if(soundSetting == HIGH){
    read_eeprom(); 
    
    //Turn Sound Off
    if(soundMode){
      soundMode = false;

      EEPROM.write(addr1, soundMode);
      return;
    }

    //Turn Sound On
    if(!soundMode){
      soundMode = true;

      EEPROM.write(addr1, soundMode);
      return;
    }
  }
  

  //Green Button is Pressed    GAMEMODE
  if(gameSetting == HIGH){
    read_eeprom();
    
    //Play Game Mode 1
    if(gameMode == 2){
      gameMode = 1;
      
      EEPROM.write(addr2, gameMode);
      return;
    }

    //Play Game Mode 2
    if(gameMode == 1){
      gameMode = 2;
      
      EEPROM.write(addr2, gameMode);
      return;
    } 
  }
}


void runAnimation(){
  if(gameMode == 1){
    startMode1();
  }

  if(gameMode == 2){
    startMode2();
  }
}


/**
 * Ensures that input for gameMode stays in a legit value
 */
void clampModes(){
  if(gameMode < 1){
    gameMode = 1;
  }
    
  if(gameMode > 2){
    gameMode = 2;
  }
}
