#include <stdbool.h>
#include <stdio.h>

#include "jccbasic_version.h"

void assert_true(bool actual) {
  if (actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %d, but was: %d", true, actual);
  }
}

int main(int argc, char *argv[]) {
  assert_true(jccbasic_version() >= 1000000);
}
