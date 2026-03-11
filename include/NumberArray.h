#include <limits>

class NumberArray {
  static constexpr double INVALID = std::numeric_limits<double>::denorm_min();
  static const int MAX_SIZE = 65536;

  int size_m;
  double *data_m;
public:
  NumberArray(int size = MAX_SIZE);

  ~NumberArray();

  void setNumber(int index, double value);

  double getNumber(int index) const;

  double getMin() const;
  double getMax() const;
  double getAverage() const;

  void print() const;
};
