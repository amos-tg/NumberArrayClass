#include "NumberArray.h"
#include <cassert>
#include <iostream>

using namespace std;

const char *TEST_PASS = "Passed";

const char *NA_CONSTRUCTOR_TEST = "Test (NumberArray constructor): ";

int main(void) {
  cout << NA_CONSTRUCTOR_TEST;
  const int VAL = 10;
  NumberArray tested ( VAL );

  cout << TEST_PASS << endl;

  return 0;
}
