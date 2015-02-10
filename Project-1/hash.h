#include <iostream>
#include "linkedlist.h"
using namespace std;

class Hash {
  Node **table;

 public:
  Hash() {
    table = new Node*[101];
    for (int i = 0; i < 101; i++) {
      table[i] = NULL;
    }
  }

  //Returns the heapIndex of the value
  //Otherwise, returns -1.
  int getHeapIndex(int key) {
    int hash = (key % 101);

    //If no values in that section of the hash
    if (table[hash] == NULL){
      return -1;
    }
    else {
      Node *entry = table[hash];
      while ((entry != NULL) && (entry->getKey() != key)){
	entry = entry->getNext();
      }
      if (entry == NULL){
	return -1;
      }
      else{
	return entry->getHeapIndex();
      }
    }
  }

  //Checks to see whether the key is in the table
  bool look(int key) {
    int hash = (key % 101);

    //If no values in that section of the hash
    if (table[hash] == NULL){
      return false;
    }
    else {
      Node *entry = table[hash];
      while ((entry != NULL) && (entry->getKey() != key)){
	entry = entry->getNext();
      }
      if (entry == NULL){
	return false;
      }
      else{
	return true;
      }
    }

  }

  //Inserts the value into the hash table with
  //the according heapIndex
  void insert(int key, int heapIndex) {
    int hash = (key % 101);
    
    //If no values in that section of the hash, insert.
    if (table[hash] == NULL) {
      table[hash] = new Node(key,heapIndex);
    }
    //Else, find end of list and attach to end of list.
    else {
      Node *entry = table[hash];
      while (entry->getNext() != NULL) {
	entry = entry->getNext();
      }
      if (entry->getKey() == key) {
	entry->setHeapIndex(heapIndex);
      }
      else {
	entry->setNext(new Node(key,heapIndex));
      }
    }
  }

  //Removes the value from the hash table
  void remove(int key) {
    int hash = (key % 101);
    
    //If there are values in that section
    if (table[hash] != NULL) {
      Node *prevEntry = NULL;
      Node *entry = table[hash];

      //Find the key
      while ((entry->getNext() != NULL) && (entry->getKey() != key)) {
	  prevEntry = entry;
	  entry = entry->getNext();
	}
      //If key found
      if (entry->getKey() == key) {
	// If first in hash
	if (prevEntry == NULL) {
	  Node *nextEntry = entry->getNext();
	  delete entry;
	  table[hash] = nextEntry;
	}
	//Otherwise, rewire
	else {
	  Node *next = entry->getNext();
	  delete entry;
	  prevEntry->setNext(next);
	}
      }
    }
  }
 
};

	
