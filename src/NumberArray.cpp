#include "NumberArray.h"
#include <iostream>

NumberArray::NumberArray(int size) {
  // allocate array and initialize all elements to zero
  data_m = new double[MAX_SIZE] {};   
}

NumberArray::~NumberArray() {
  delete [] data_m;  
  std::cout << "Deallocated data array" << std::endl;
}

void NumberArray::setNumber(int index, double value) {
  if (index > size_m || index < 0) {
    return; 
  }

  data_m[index] = value;
}

double NumberArray::getNumber(int index) const {

}

double NumberArray::getMin() const {

}

double NumberArray::getMax() const {

}

double NumberArray::getAverage() const {

}

void NumberArray::print() const {

}
