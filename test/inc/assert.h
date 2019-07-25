#ifndef ASSERT_H_
#define ASSERT_H_

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// These functions should be macros...

void assert_equals(int64_t expected, int64_t actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %" PRId64 ", but was: %" PRId64 "\n", expected, actual);
  }
}

void assert_true(bool actual) {
  if (actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %d, but was: %d", true, actual);
  }
}

#endif /* ASSERT_H_ */
