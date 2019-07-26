#ifndef SGN_H_
#define SGN_H_

#include <stdint.h>

// Returns the signum of the given number, that is, -1 if number is negative,
// 1 if number is positive, and 0 if number is exactly 0.
int64_t sgn(double number);

#endif /* SGN_H_ */
