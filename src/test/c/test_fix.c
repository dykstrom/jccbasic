#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "fix.h"

void assert_equals(int64_t expected, int64_t actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %" PRId64 ", but was: %" PRId64 "\n", expected, actual);
  }
}

int main(int argc, char *argv[]) {
  assert_equals(0, fix(0));
  assert_equals(1, fix(1));
  assert_equals(1, fix(1.7));
  assert_equals(-1, fix(-1));
  assert_equals(-3, fix(-3.14));
}
