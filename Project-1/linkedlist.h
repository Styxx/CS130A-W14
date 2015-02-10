#include <iostream>
using namespace std;

class Node {
private:
      int key;
      int heapIndex;
      Node *next;
public:
      Node(int key, int heapIndex) {
            this->key = key;
	    this->heapIndex = heapIndex;
            this->next = NULL;
      }

      int getHeapIndex() {
	return heapIndex;
      }
      int setHeapIndex(int heapIndex) {
	this->heapIndex = heapIndex;
      }

      int getKey() {
            return key;
      }

      Node *getNext() {
            return next;
      }
 
      void setNext(Node *next) {
            this->next = next;
      }
};
