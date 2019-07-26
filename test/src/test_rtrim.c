#include <stdlib.h>

#include "assert.h"
#include "rtrim.h"

int main(int argc, char *argv[]) {
  char* actual;

  actual = rtrim("");
  assert_equals_Str_Str("", actual);
  free(actual);

  actual = rtrim(" \t\n ");
  assert_equals_Str_Str("", actual);
  free(actual);

  actual = rtrim("abc");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = rtrim("abc ");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = rtrim("abc     ");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = rtrim("abc\t\n");
  assert_equals_Str_Str("abc", actual);
  free(actual);

  actual = rtrim("   abc");
  assert_equals_Str_Str("   abc", actual);
  free(actual);
}
