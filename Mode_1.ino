/**
 * Mode 1 creates a random pattern each time a correct sequence is entered
 * Each iteration grows by one
 */
void mode1(){
  //Create new sequence
  addStack1();

  //Check if input is right or wrong
  buttonPressCheck();

  //If correct pattern was entered, continue and grow by 1
  while(checkFlag == true){
    answer();
  }
  queue.clear();
  roundScore++;
}


/**
 * Creates an array with a random sequence
 * Each time its called, the sequence is completely new
 */
void addStack1(){
  for(int x = 0; x < roundScore; x++){
    int myRandom = random(1,5);
    if(soundMode){
      lightSound(myRandom, mySpeed);
      queue.push_back(myRandom);
      checkFlag = true;
    }

    if(!soundMode){
      lightMute(myRandom, mySpeed);
      queue.push_back(myRandom);
      checkFlag = true;
    }
  }

  //printQueue();
}
