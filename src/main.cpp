#include "NumberArray.h"
#include <cassert>
#include <iostream>
#include <cstddef>

using namespace std;

const char *TEST_PASS = "Passed";

const char *DEF_CONSTRUCTOR_TEST = "Test (NumberArray default constructor): ";
const char *ARG_CONSTRUCTOR_TEST = "Test (NumberArray argumentative constructor): ";
const char *VALIDEX_TEST = "Test ({set,get}Number methods): ";

int main(void) {
  cout << DEF_CONSTRUCTOR_TEST;
  NumberArray tested {};

  assert(tested.size() == NumberArray::DEFAULT_SIZE);

  for (size_t i {}; i < NumberArray::DEFAULT_SIZE; ++i)
  {
    assert(tested.getNumber(i) == 0.0);
  }

  tested.print();
  cout << TEST_PASS << endl;

  cout << ARG_CONSTRUCTOR_TEST;
  const size_t size { 10 };
  NumberArray custom ( size );

  assert(custom.size() == size);

  for (size_t i {}; i < size; ++i)
  {
    assert(custom.getNumber(i) == 0.0);
  }
  cout << TEST_PASS << endl;

  cout << VALIDEX_TEST;
  double set { 27.123 }, check;

  tested.setNumber(0, set++);
  tested.setNumber(tested.size() / 2, set++);
  tested.setNumber(tested.size(), set);

  check = tested.getNumber(tested.size()); 
  assert(check == set--);
  check = tested.getNumber(tested.size() / 2);
  assert(check == set--);
  check = tested.getNumber(0);
  assert(check == set);

  double init_checksum {}, fin_checksum {};
  for (int i {}; i < tested.size(); ++i)
  {
    init_checksum += tested.getNumber(i);
  }

  tested.setNumber(-1, 42.42);
  tested.setNumber(tested.size(), 42.42);

  for (int i {}; i < tested.size(); ++i)
  {
    fin_checksum += tested.getNumber(i); 
  }

  assert(fin_checksum == init_checksum);

  // The INVALID value is an unlikely to be used small decimal value. 
  assert(tested.getNumber(-1) == NumberArray::INVALID); 
  assert(tested.getNumber(tested.size()) == NumberArray::INVALID);
  cout << TEST_PASS << endl;

  return 0;
}
