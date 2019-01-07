/**
 * Mode 2 appends a new item to the list at each iteration 
 * Each iteration grows by one
 */
void mode2(){
  //Create new sequence
  addStack2();

  //Check if input is right or wrong
  buttonPressCheck();

  //If correct pattern was entered, continue and grow by 1
  while(checkFlag == true){
    answer();
  }
  
  roundScore++;
}


/**
 * Creates an array with a random sequence
 * Each time it appends a new number to the existing list
 */
void addStack2(){
  int myRandom = random(1,5);
  queue.push_back(myRandom);
  blinkQueue();
  checkFlag = true;
  
  //printQueue();
}
