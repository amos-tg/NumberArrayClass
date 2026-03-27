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
const char *EDGE_CASE_TEST = "Test (NumberArray edge case tests): ";
const char *COPY_CONSTRUCTOR_TEST = "Test (NumberArray copy constructor tests): ";
const char *ASSIGNMENT_OPERATOR_TEST = "Test (NumberArray assignment operator tests): ";
const char *DESTRUCT_LIFETIME_TEST = "Test (NumberArray destructor lifetime tests): ";

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

/// tests the edge case uses of the NumberArray class
void edgeCaseTests(void);

/// tests the copy constructor of the NumberArray class
void copyConstructorTests(void);

/// tests the assignment operator of the NumberArray class
void assignmenOpTests(void);

/// tests that lifetimes are properly handled by the destructor.
void destructLifetimeTests(void);

int main(void)
{
  defaultConstructorTest();  
  cout << '\n';
  paramConstructorTest();
  cout << '\n';
  setGetNumberTests();
  cout << '\n';
  statisticalTests();
  cout << '\n';
  printTests();
  cout << '\n';
  edgeCaseTests();
  cout << '\n';
  copyConstructorTests();
  cout << '\n';
  assignmenOpTests();
  cout << '\n';
  destructLifetimeTests();

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

void edgeCaseTests(void)
{
  cout << EDGE_CASE_TEST;
  NumberArray test { 1 };
  assert(test.getNumber(0) == 0.0);
  test.setNumber(0, 10.0);
  assert(test.getNumber(0) == 10.0);
  test.setNumber(0, -11.123);
  assert(test.getNumber(0) == -11.123);
  assert(test.getMax() == -11.123);
  assert(test.getMin() == -11.123);
  assert(test.getAverage() == -11.123);
  cout << '\n';
  test.print();
  cout << TEST_PASS << endl;
}

void copyConstructorTests(void)
{
  cout << COPY_CONSTRUCTOR_TEST;
  
  // create a new object
  size_t size { 20 };
  NumberArray orig { 20 };

  // put some values in original object
  for (int i {}; i < size; ++i)
    orig.setNumber(i, i);

  // copy original object with copy constructor
  NumberArray copied { orig };
  assert(orig.size() == copied.size());

  // verify values were copied
  for (int i {}; i < size; ++i)
    assert(copied.getNumber(i) == orig.getNumber(i));

  //  modify orig. and confirm copy doesn't change
  orig.setNumber(size / 2, 25.555555);
  assert(copied.getNumber(size / 2) != 25.555555);

  // modify copy and confirm orig. doesn't change
  copied.setNumber(size / 3, 21.21);
  assert(orig.getNumber(size / 3) != 21.21);

  cout << TEST_PASS << endl;
}

void assignmenOpTests(void)
{
  cout << ASSIGNMENT_OPERATOR_TEST;
  
  // create two objs of the same size 
  size_t size { 25 };
  NumberArray assigned { size };
  NumberArray source { size };

  // give some values to obj1
  for (int i {}; i < size; ++i)
    source.setNumber(i, 11.11);

  // assign one to other
  assigned = source; 

  // verify correct copy
  for (int i {}; i < size; ++i)
    assert(assigned.getNumber(i) == source.getNumber(i));

  // modify source object & confirm assigned object doesn't change
  source.setNumber(size / 2, 22.9181); 
  assert(assigned.getNumber(size / 2) != 22.9181);

  // modify assigned object & confirm source object doesn't change
  assigned.setNumber(size / 2, 423.12848); 
  assert(source.getNumber(size / 2) != 423.12848);

  // size difference test
  size_t size_1 { 20 }, size_2 { 40 };
  NumberArray obj1 { size_1 }, obj2 { size_2 };

  obj2.setNumber(0, 10.0);
  obj2.setNumber(size_2 - 1, 10.0);

  // assign larger to smaller
  obj1 = obj2;

  // check that the size changed and that values are copied correctly
  assert(obj1.size() == size_2);
  assert(obj1.getNumber(size_2 - 1) == 10.0);
  assert(obj1.getNumber(0) == 10.0);

  // self assignment test
  obj1 = obj1;
  
  // data remains unchanged 
  assert(obj1.size() == size_2);
  assert(obj1.getNumber(size_2 - 1) == 10.0);
  assert(obj1.getNumber(0) == 10.0);

  cout << TEST_PASS << endl;
}

void destructLifetimeTests(void)
{
  cout << DESTRUCT_LIFETIME_TEST << endl;
  // create objects inside a block scope
  {
    NumberArray obj1, obj2;

    // tests assignment chaining as well
    obj1 = obj2 = NumberArray{};
  }

  // should be three messages outputted
  
  cout << TEST_PASS << endl;
}
