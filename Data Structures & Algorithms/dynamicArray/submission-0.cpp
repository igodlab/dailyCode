#include <cassert>

class DynamicArray {

  private:
    int* arr;
    int capacity;
    int size;

  public: 
    DynamicArray(int capacity) {
      arr = (int*) malloc(capacity * sizeof(int));
      this->capacity = capacity;
      size = 0;
    }
     int get(int i) {
       // assert(i < size);
       return arr[i];
     }
     void set(int i, int n){
       assert(i < size);
       arr[i] = n;
     }
     void resize() {
       capacity *= 2;
       arr = (int*) realloc(arr, capacity * sizeof(int));
     }
     void pushback(int n) {
       if (size == capacity) {
         resize();
       }
       arr[size] = n;
       ++size;
     }
     int popback() {
       --size;
       return arr[size];
     }
     int getSize() {
       return size;
     }
     int getCapacity() {
       return capacity;
     }
};