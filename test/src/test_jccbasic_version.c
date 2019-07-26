#include "assert.h"
#include "jccbasic_version.h"

int main(int argc, char *argv[]) {
  assert_true_Bool(jccbasic_version() >= 1000000);
}
