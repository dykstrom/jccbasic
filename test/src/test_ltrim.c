#include <stdlib.h>

#include "assert.h"
#include "ltrim.h"

int main(int argc, char *argv[]) {
  char* actual;

  actual = ltrim("");
  assert_equals_Str_Str("", actual);
  free(actual);

  actual = ltrim(" \t\n ");
  assert_equals_Str_Str("", actual);
  free(actual);

  actual = ltrim("abc");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = ltrim(" abc");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = ltrim("          abc");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = ltrim("\tabc");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = ltrim("abc ");
  assert_equals_Str_Str("abc ", actual);
  free(actual);
}
