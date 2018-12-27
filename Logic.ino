/**
 * Checks the user input and determines if its correct or not
 */
void answer(){
  for(int x = 0; x < roundScore; x++){
    int compareItem = queue.dequeue();
    input = buttonPressCheck();

    //Loop to give user a chance to input his response
    while(input == 0){
      input = buttonPressCheck();
    }

    //Input was entered, time to check if it's right or not
    while(input != 0){
      
      //Input is good, go another round
      if(compareItem == input){
        Serial.println("Good"); 
        checkFlag = false;
        input = 0;
        break;
      }
      //Input was wrong, start over
      if(compareItem != input){
        Serial.println("Bad");
        checkFlag = false;
        input = 0;
        failInput();
        break;
      }
    }
  }
  Serial.println("Answer was right");
  delay(250);
}


////I don't think this is being used for anything now
//void readQueue(){
//  myCount = queue.count();
//  Serial.print("My stack size = ");
//  Serial.println(myCount);
//
//  // Start Here // memcpy(copy, (QueueArray<int> *)queue, 5*sizeof(int));
//  for(int i = 0; i < myCount; i++){
//      int x = Rstack.pop();
//      Serial.print("Popping ");
//      Serial.print(x);
//      Serial.println(" off");
//      lightSound(x, mySpeed);
//  }
//}


int buttonPressCheck(){
  int button1state = digitalRead(BUTTON_1);
  int button2state = digitalRead(BUTTON_2);
  int button3state = digitalRead(BUTTON_3);
  int button4state = digitalRead(BUTTON_4);

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
  return input;
}


///**
// * This doesn't do anything right now
// */
//void successInput(){
//  float mySpeed = .25;
//
//  for(int i = 1; i <= 4; i++){
//    lightSound(i, mySpeed);
//  }
//  
//  for(int i = 3; i >= 2; i--){
//    lightSound(i, mySpeed);
//  }
//  
//  lightSound(1, mySpeed*2.5);
//}
//
