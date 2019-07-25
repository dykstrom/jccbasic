#include "assert.h"
#include "sgn.h"

int main(int argc, char *argv[]) {
  assert_equals(0, sgn(0));
  assert_equals(1, sgn(1));
  assert_equals(1, sgn(4711.0));
  assert_equals(-1, sgn(-1));
  assert_equals(-1, sgn(-3.14));
}
