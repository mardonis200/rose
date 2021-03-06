// This is an example of a printer (fake) driver that fails to seperate
// the user's confiential input (their file) from the public request
// for new ink sent over the internet.
// If fails because there is not a default case for the ink color if,
// which means if the error message is -5, the user's confidential file
// name will be sent into the public rather than this ink request.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Make sure there is ink
int checkInk() {

  char ink[256];
  puts("ink? Y/N");
  gets(ink);
  
  if(strcmp(ink, "N") == 0) {
    return -1; //Error
  }
 
  return 0;
  
}

//Get user input file from network
char* getFileToPrint(char* file) {
  
#pragma leek classified
  file = gets(file);
  
  return file;
}

void printFile(char* file) {

  puts(file);
 
}

void makeInkRequest(char* color) {
  
#pragma leek public
  puts(color);
}

int main() {

  int error;
  char* file = malloc(256);

  file = getFileToPrint(file);

  
  error = checkInk(); 
 

  if(error) {
    if(error == -1) 
      file = "red";
    else if(error == -2) 
      file = "blue";
    else if(error == -3) 
      file = "yellow";
    else if(error == -4)
      file = "black";
  
    makeInkRequest(file);
  } else {
    printFile(file);
  }

  return 0;
}
