#include "NumberArray.h"
#include <iostream>
#include <cstddef>

NumberArray::NumberArray(size_t size) 
{
  // allocate array and initialize all elements to zero
  data_m = new double[size] {};   
  size_m = size;
}

NumberArray::~NumberArray() 
{
  delete [] data_m;  
  std::cout << "Deallocated data array" << std::endl;
}

size_t NumberArray::size() const 
{
  return size_m;
}

void NumberArray::setNumber(size_t index, double value) 
{
  if (index > size_m || index < 0) 
  {
    return; 
  }

  data_m[index] = value;
}

double NumberArray::getNumber(size_t index) const 
{
  if (index < 0 || index > size_m) 
  {
    return INVALID;
  } 
  
  return data_m[index];
}

double NumberArray::getMin() const 
{
  double min { *data_m };

  for (size_t i { 1 }; i < size_m; ++i)
  {
    if (data_m[i] < min) 
    {
      min = data_m[i];
    }
  }

  return min;
}

double NumberArray::getMax() const 
{
  double max { *data_m };

  for (size_t i { 1 }; i < size_m; ++i)
  {
    if (data_m[i] > max)
    {
      max = data_m[i];
    }
  }

  return max;
}

double NumberArray::getAverage() const 
{
  double average {};  

  for (size_t i {}; i < size_m; ++i)
  {
    average += data_m[i];
  }

  return average /= size_m;  
}

void NumberArray::print() const 
{
  for (size_t i {}; i < size_m; ++i)
  {
    std::cout << data_m[i];
  }

  std::cout << std::endl;
}
