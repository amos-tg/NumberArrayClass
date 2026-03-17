#include "NumberArray.h"
#include <cassert>
#include <iostream>
#include <cstddef>
#include <random>

using namespace std;

const char *TEST_PASS = "Passed";

const char *DEFAULT_CONSTRUCTOR_TEST = "Test (NumberArray constructor): "; 
const char *PARAM_CONSTRUCTOR_TEST = 
  "Test (NumberArray Parameterized constructor): ";
const char *SET_GET_NUMBER_TESTS = "Test (NumberArray {set,get}Number methods): "; 
const char *STATISTICAL_TESTS = 
  "Test (NumberArray {min,max,average}Number methods): ";
const char *PRINT_TEST = "Test (NumberArray print method): ";

// The test functions follow the testing documents specifications in order,
// both internally, and in terms of their calling sequence in main().

/// tests the default constructor of the NumberArray class
void defaultConstructorTest(void);

/// tests the parameterized constructor of the NumberArray class
void paramConstructorTest(void);

/// tests the set and get Number methods of the NumberArray class
void setGetNumberTests(void);

/// tests the {min,max,average}Number methods of the NumberArray class
void statisticalTests(void);

/// tests the print method of the NumberArray class
void printTests(void);

int main(void)
{
  // cout << '\n'; seperates the tests dealloc messages
                                  
  defaultConstructorTest();  
  cout << '\n';
  paramConstructorTest();
  cout << '\n';
  setGetNumberTests();
  cout << '\n';
  statisticalTests();
  cout << '\n';
  printTests();

  return 0;
}

void defaultConstructorTest(void) 
{
  cout << DEFAULT_CONSTRUCTOR_TEST;
  NumberArray test {};
  assert(test.size() == NumberArray::DEFAULT_SIZE);

  for (int i {}; i < test.size(); ++i)
    assert(test.getNumber(i) == 0.0);

  cout << '\n';
  test.print();
  cout << TEST_PASS << endl;
} 

void paramConstructorTest(void)
{
  cout << PARAM_CONSTRUCTOR_TEST;
  const size_t SET_SIZE { 10 };
  NumberArray test { SET_SIZE };
  assert(test.size() == SET_SIZE);

  for (int i {}; i < test.size(); ++i)
    assert(test.getNumber(i) == 0.0);

  cout << TEST_PASS << endl;
}

void setGetNumberTests(void) 
{
  cout << SET_GET_NUMBER_TESTS;
  const size_t SET_SIZE { 30 };
  NumberArray tested { SET_SIZE };
  
  // valid index tests
  tested.setNumber(SET_SIZE - 1, 10.0);          
  tested.setNumber(SET_SIZE / 2, 10.0);
  tested.setNumber(0, 10.0);

  assert(tested.getNumber(SET_SIZE - 1) == 10.0);
  assert(tested.getNumber(SET_SIZE / 2) == 10.0);
  assert(tested.getNumber(0) == 10.0);
  
  // OOB index tests
  tested.setNumber(-1, 19.0); 
  tested.setNumber(tested.size(), 19.0);

  assert(tested.getNumber(-1) == NumberArray::INVALID); 
  assert(tested.getNumber(tested.size()) == NumberArray::INVALID);

  cout << '\n' << "Invalid Number Default return = " << NumberArray::INVALID;
  cout << '\n' << TEST_PASS << endl;
}

void statisticalTests(void)
{
  cout << STATISTICAL_TESTS;
  NumberArray tested { 10 };
  double max, min, average;

  // using preset values
  for (int i {}, set { 1 }; i < tested.size(); ++i, ++set)
  {
    tested.setNumber(i, set);
  }
  
  assert(tested.getMax() == 10.0);
  assert(tested.getMin() == 1.0);
  assert(tested.getAverage() == 5.5);

  // using random values, pseudo-random gen seeded with random gen, only random
  // on certain platforms.
  random_device rand;  
  mt19937 prand { rand() };
  uniform_real_distribution<> gen(0.0, 30.0);
  for (int i {}; i < tested.size(); ++i)
  {
    tested.setNumber(i, gen(prand));
  }

  max = tested.getMax();
  min = tested.getMin();
  average = tested.getAverage();

  assert(min <= average && average <= max);

  cout << '\n' 
    << "Minimum: " << min << '\n'
    << "Maximum: " << max << '\n'
    << "Average: " << average << '\n';

  cout << TEST_PASS << endl;
}

void printTests(void) 
{
  cout << PRINT_TEST;
  NumberArray test {};
  cout << '\n';
  test.print();

  for (int i {}, set { 1 }; i < test.size(); ++i, ++set)
  {
    test.setNumber(i, set);
  }
  test.print();

  cout << TEST_PASS << endl;
}
