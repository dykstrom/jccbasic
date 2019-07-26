#ifndef ASSERT_H_
#define ASSERT_H_

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// These functions should be macros...

void assert_equals_I64_I64(int64_t expected, int64_t actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %" PRId64 ", but was: %" PRId64 "\n", expected, actual);
  }
}

void assert_equals_Str_Str(const char* expected, const char* actual) {
  if (strcmp(expected, actual) == 0) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: '%s', but was: '%s'\n", expected, actual);
  }
}

void assert_true_Bool(bool actual) {
  if (actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %d, but was: %d", true, actual);
  }
}

#endif /* ASSERT_H_ */
