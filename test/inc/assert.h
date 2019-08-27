/*
 * Copyright (C) 2019 Johan Dykstrom
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// These functions should be macros...

void assert_equals_F64_F64(double expected, double actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %f, but was: %f\n", expected, actual);
  }
}

void assert_equals_F64_F64_F64(double expected, double actual, double delta) {
  if ((actual > expected - delta) && (actual < expected + delta)) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %f +/- %f, but was: %f\n", expected, delta, actual);
  }
}

void assert_not_equals_F64_F64(double unexpected, double actual) {
  if (unexpected != actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected difference, but was: %f\n", unexpected);
  }
}

void assert_equals_I64_I64(int64_t expected, int64_t actual) {
  if (expected == actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %" PRId64 ", but was: %" PRId64 "\n", expected, actual);
  }
}

void assert_equals_Str_Str(const char* expected, const char* actual) {
  if (strcmp(expected, actual) == 0) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: '%s', but was: '%s'\n", expected, actual);
  }
}

void assert_array_equals_F64_F64(double expected[], double actual[], int length) {
  for (int i = 0; i < length; i++) {
    if (expected[i] != actual[i]) {
      printf("FAIL: at index %d, expected: %f, but was: %f\n", i, expected[i], actual[i]);
      return;
    }
  }
  printf("OK\n");
}

void assert_array_not_equals_F64_F64(double unexpected[], double actual[], int length) {
  for (int i = 0; i < length; i++) {
    if (unexpected[i] != actual[i]) {
      printf("OK\n");
      return;
    }
  }
  printf("FAIL: expected difference, but all %d elements were equal\n", length);
}

void assert_true_Bool(bool actual) {
  if (actual) {
    printf("OK\n");
  } else {
    printf("FAIL: expected: %d, but was: %d", true, actual);
  }
}

#endif /* ASSERT_H_ */
