#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "ltrim.h"

char* ltrim(const char* s) {
  while ((s[0] != 0) && isspace(s[0])) {
    s++;
  }
  char* result = malloc(strlen(s) + 1);
  return strcpy(result, s);
}
