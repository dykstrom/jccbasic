#include "sgn.h"

int64_t sgn(double number) {
  if (number > 0.0) {
    return 1;
  } else if (number < 0.0) {
    return -1;
  } else {
    return 0;
  }
}
