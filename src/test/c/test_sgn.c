#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "sgn.h"

void assert_equals(int64_t expected, int64_t actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %" PRId64 ", but was: %" PRId64 "\n", expected, actual);
  }
}

int main(int argc, char *argv[]) {
  assert_equals(0, sgn(0));
  assert_equals(1, sgn(1));
  assert_equals(1, sgn(4711.0));
  assert_equals(-1, sgn(-1));
  assert_equals(-1, sgn(-3.14));
}
