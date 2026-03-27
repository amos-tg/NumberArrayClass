#include "NumberArray.h"
#include <iostream>
#include <cstddef>

NumberArray::NumberArray(size_t size) 
{
  // allocate array and initialize all elements to zero
  data_m = new double[size] {};   
  size_m = size;
}


NumberArray::NumberArray(const NumberArray& other)
  // set size and alloc zeroed array
  : size_m(other.size_m), data_m(new double[other.size_m] {})
{
  // deep copy the data
  for (int i {}; i < size_m; ++i)
    data_m[i] = other.data_m[i];
}

NumberArray& NumberArray::operator=(const NumberArray& other) 
{
  // self assignment check
  if (this == &other) 
    return *this;

  size_m = other.size_m;

  // if not null dealloc data_m then re-alloc zeroed array
  if (data_m) delete [] data_m;
  data_m = new double[other.size_m] {};

  // deep copy the data.
  for (int i {}; i < size_m; ++i)
    data_m[i] = other.data_m[i];  

  return *this;
}

NumberArray::~NumberArray() 
{
  // de-alloc the array
  delete [] data_m;  
  std::cout << "Deallocated data array" << std::endl;
}

size_t NumberArray::size() const 
{
  return size_m;
}

void NumberArray::setNumber(size_t index, double value) 
{
  // index validity check
  if (index >= size_m || index < 0) 
  {
    return; 
  }

  data_m[index] = value;
}

double NumberArray::getNumber(size_t index) const 
{
  // index validity check
  if (index >= size_m || index < 0) 
  {
    return INVALID;
  } 
  
  return data_m[index];
}

double NumberArray::getMin() const 
{
  // init min to the first element in the array
  double min { data_m[0] };

  // check for the smallest element in the array
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
  // init max to first element in array
  double max { data_m[0] };

  // check for largest element in array
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
  // might not be big enough for large arrays
  long double average {};  

  // sum the array into the average var
  for (size_t i {}; i < size_m; ++i)
  {
    average += data_m[i];
  }

  // divide by num elements to get average
  return average /= size_m;  
}

void NumberArray::print() const 
{
  // print all the array elements
  for (size_t i {}; i < size_m; ++i)
  {
    std::cout << data_m[i] << ' ';
  }

  // flush and print a newline
  std::cout << std::endl;
}
