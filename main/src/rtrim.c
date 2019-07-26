#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "rtrim.h"

char* rtrim(const char* s) {
  int index = strlen(s) - 1;

  // Walk backwards from the end while we only see whitespace
  while ((index >= 0) && isspace(s[index])) {
    index--;
  }

  // index is now length of substring - 1 (for empty strings it is -1)
  char* result = malloc(index + 2);

  if (index != -1) {
    strncpy(result, s, index + 1);
  }

  result[index + 1] = 0;
  return result;
}
