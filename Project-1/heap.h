#include <iostream>
#include <vector>
using namespace std;

class Heap{
  // Variables
 private:
  vector<int> array;
  //vector<int>::iterator iter;
	
  // Methods
 public:

  Heap(){
    vector<int> array(10);		//Empty vector of ints w/ size 10
    //vector<int>::iterator intr;
  }

  int getSize(){
    return array.size();
  }

  int insert(int i) {
    array.push_back(1);
    int index = percolateUp(array.back());
    return index;
  }


  // Returns the minimum value
  int deleteMin(){
    int ret = array[1];
    array[1] = array.back();
    array.pop_back();
    percolateDown(array[1]);
    return ret;
  }

  int percolateUp(int i){ 
    int temp;
    int place = i;
    while (array[place] < array[place/2]) {
      temp = array[place/2];
      array[place/2] = array[place];
      array[place] = temp;
      place = place/2;
    }
    return place;
    
  }

  
  void percolateDown(int i) {
    int temp;
    int place = i;
    while ((array[place] > array[2*place]) || (array[place] > array[2*place+1])) {
      if(array[2*place] < array[2*place+1]){	//2i is smaller
	temp = array[2*place];
        array[2*place] = array[place];
	array[place] = temp;
	place = 2*place;
      }
      else {					//2i+1 is smaller
	temp = array[2*place+1];
	array[2*place+1] = array[place];
	array[place] = temp;
	place = 2*place+1;
      }
    }
  }

  void remove(int index) {
    array[index] = array.back();
    array.pop_back();
    percolateDown(array[index]);
  }

};

