#ifndef JCCBASIC_VERSION_H_
#define JCCBASIC_VERSION_H_

#include <stdint.h>

// Returns the current version of the JCC Basic standard library as a 64-bit
// integer. The last three digits of this integer represent the patch level.
// The three digits to the left of the patch level represent the minor version,
// and all the digits to the left of the minor version represent the major
// version. As an example, the version 1.12.7 would be returned as 1012007.
int64_t jccbasic_version();

#endif /* JCCBASIC_VERSION_H_ */
