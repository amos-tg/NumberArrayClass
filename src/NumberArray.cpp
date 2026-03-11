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
  if (index < 0 || index > size_m) 
  {
    return INVALID;
  } 
  
  return data_m[index];
}

double NumberArray::getMin() const {
  double min { *data_m };

  for (int i { 1 }; i < size_m; ++i)
  {
    if (data_m[i] < min) 
    {
      min = data_m[i];
    }
  }

  return min;
}

double NumberArray::getMax() const {

}

double NumberArray::getAverage() const {

}

void NumberArray::print() const {

}
