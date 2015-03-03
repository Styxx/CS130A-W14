#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "combo.cpp"

int main() {
  Combo combo;
  string line;
  int arg1, arg2;
  int counter = 0;

  
  while (!cin.eof()) {
    arg1 = arg2 = -1;
    getline(cin,line);
    
    if (line.find(",") == string::npos) {
      arg1 = atoi(&line[0]);
    }
    else {
      char *chunk;
      chunk = strtok(&line[0], ",");
      arg1 = atoi(chunk);
      chunk = strtok(NULL, "\n");
      arg2 = atoi(chunk);		       
    }

    if(counter == 0){
      cout << "read hash size " << arg1 << endl;
    }
    
    //arg1 contains first int
    //arg2 contains second int
    //cout << arg1 << " " << arg2 << endl;
    
    

    counter++;
  }
}
