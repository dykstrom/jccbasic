#include "assert.h"
#include "fix.h"

int main(int argc, char *argv[]) {
  assert_equals_I64_I64(0, fix(0));
  assert_equals_I64_I64(1, fix(1));
  assert_equals_I64_I64(1, fix(1.7));
  assert_equals_I64_I64(-1, fix(-1));
  assert_equals_I64_I64(-3, fix(-3.14));
}
