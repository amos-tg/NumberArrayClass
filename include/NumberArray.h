#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

#include <limits>
#include <cstddef>

class NumberArray {
  size_t size_m;
  double *data_m;
public:
  /// An extrememly unlikely to be used value; it might be better to use a 
  /// flag, but this will work just as well %99.99... of the time.
  static constexpr double INVALID = std::numeric_limits<double>::denorm_min();

  /// Default array size when the constructor is not passed a specific size.
  static const size_t DEFAULT_SIZE = 128;

  NumberArray(size_t size = DEFAULT_SIZE);

  ~NumberArray();

  size_t size() const; 

  void setNumber(size_t index, double value);

  double getNumber(size_t index) const;

  double getMin() const;
  double getMax() const;
  double getAverage() const;

  void print() const;
};

#endif
