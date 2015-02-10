#include <iostream>
#include "heap.h"
#include "hash.h"
using namespace std;

class Combo{
private:
  Heap hea;
  Hash has;

public:
  Combo() {
    Heap hea;
    Hash has;
  }
  
  void insert(int num) {
    if (has.look(num) != true) {
      int heapIndex = hea.insert(num);
      has.insert(num, heapIndex);
      cout << "insert " << num << endl;
    }
    else {
      cout << "error_already_present " << num << endl;
    }
  }

  void lookup(int num) {
    if (has.look(num) != -1) {
      cout << "not_find " << num << endl;
    }
    else {
      cout << "find " << num << endl;
    }
  }

  void deleteMin() {
    int ret = hea.deleteMin();
    has.remove(ret);
    cout << "deleteMin " << ret << endl;
  }

  void delet(int num) {
    int hash = has.getHeapIndex(num);
    has.remove(num);
    hea.remove(hash);
    cout << "delete " << num << endl;
  }

  void print() {
    cout << "print ";
    while (hea.getSize() != 1){
      int num = hea.deleteMin();
      cout << num << ",";
    }
  }

};
