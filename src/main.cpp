// ~~ File header comment describing what the program does:
// 1. Populate an array with integer values.
// 2. Call ReverseArray to dynamically create a reversed copy of the array.
// 3. Display the original array.
// 4. Display the reversed array.
// 5. Deallocate the dynamically allocated array using delete[].

#define ARRAY_SIZE 30

#include <iostream>

using namespace std;

/// - const int arr[] : the original array which is copied in reverse
///
/// - int size : the size of the original array = (const int arr[]), passed.
///
/// preconditions:
///   - sizeof(arr[]) == int size, otherwise undefined behavior
///
/// postconditions:
///   - Might throw an exception if allocation fails but I don't think i'm
///     meant to handle that until we cover exceptions in class.
///
///   - The returned array is a reversed copy of the original passed array.
///
/// Dynamically allocates an array, copies the contents of the original array in
/// reverse order, and returns a pointer to the new array.
int *ReverseArray(const int arr[], int size);

/// - const int arr[] : the array which is displayed
///
/// - int size : the size of the original array = (const int arr[]), passed.
///
/// preconditions:
///   - sizeof(arr[]) == int size, otherwise undefined behavior
///
/// postconditions:
///   - terminal output is displayed which shows the content of the array passed 
///
/// displays the contents of an array 
void print(const int arr[], int size);

int main(void) {
  // populate an array with numbers
  int arr[ARRAY_SIZE];
  for (int i {}; i < ARRAY_SIZE; ++i) {
    arr[i] = i;
  } 

  // create a heap allocated reversed copy of the array
  int *rev_arr = ReverseArray(arr, ARRAY_SIZE);

  // display the original array
  cout << "Original Array:" << endl;
  print(arr, ARRAY_SIZE);

  // display the reversed array
  cout << "Reversed Array:" << endl;
  print(rev_arr, ARRAY_SIZE);

  // deallocate the heap allocated array
  delete [] rev_arr;

  return 0;
}

int *ReverseArray(const int arr[], int size) {
  // not going to handle the exception this might throw or use nothrow to get
  // nullptr because we haven't gone over exceptions yet. 
  int *rev_arr = new int[size];

  // reverse iterate over the array and load the values into the returned
  // rev_arr variable. 
  for (int i {}, ii { size - 1 }; i < size; ++i, --ii) {
    rev_arr[i] = arr[ii];
  }

  return rev_arr;
}

void print(const int arr[], int size) {
  for (int i {}; i < size; ++i) {
    cout << arr[i] << '\t';
  }

  cout << '\n' << endl;
}
