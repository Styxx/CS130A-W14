#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;


int main() {
  string line;
  int arg1, arg2, arg3;
  char* chunk;
  
  // Retrieve the first line
  getline(cin, line);
  chunk = strtok(&line[0], " ");
  arg1 = atoi(chunk);
  chunk = strtok(NULL,"\n");
  arg2 = atoi(chunk);
  
  // arg1 is now # of verticies
  // arg2 is now # of edges
  
  
  
  //Read the rest of the file.
  while (!cin.eof()) {
    arg1 = arg2 = arg3 = -1;
    getline(cin,line);            //Next line
    
    chunk = strtok(&line[0]," ");   // Get first number (first vertex)
    arg1 = atoi(chunk);
    chunk = strtok(NULL," ");       // Get second number (second vertex)
    arg2 = atoi(chunk);
    chunk = strtok(NULL,"\n");      // Get final number (weight of edge)
    arg3 = atoi(chunk);
    
    
    //Create new connection
    
    

  }
  
  // Tree is created. Now what?
  
}
