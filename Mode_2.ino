void mode2(){
  addStack2();
//  readQueue();
//  buttonPressCheck();
//
//  while(checkFlag == true){
//    answer();
//  }
//  roundScore++;
//  printStack();
}


void addStack2(){
  int myRandom = random(1,5);
  int arraySize = (sizeof(myArray)/sizeof(int));

  Serial.println(arraySize);
  
//  for(i = 0; i < sizeof(myArray)/sizeof(int)); i++){
//    
//  }
//  
//  
//  queue.push(myRandom);
//  checkFlag = true;
}

void printStack(){

//  copy(queue, myCopy, queue.count());
   
  for(int x = 0; x < myCopy.count(); x++){
    Serial.print(myCopy.pop());
    Serial.print(" ");
  }

  Serial.println(" ");
  delay(1000);
}

void printQueueCount(){
  Serial.print("queue count = ");
  Serial.println(queue.count());
}

void copy(int* src, int* dst, int len) {
    memcpy(dst, src, sizeof(src[0])*len);
}
