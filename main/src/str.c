#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "str.h"

char* str_I64(int64_t number) {
  int length = snprintf(0, 0, "% I64d", number);
  char *result = (char *) malloc(length + 1);
  snprintf(result, length + 1, "% I64d", number);
  return result;
}

char* str_F64(double number) {
  int length = snprintf(0, 0, "% f", number);
  char *result = (char *) malloc(length + 1);
  snprintf(result, length + 1, "% f", number);
  return result;
}
