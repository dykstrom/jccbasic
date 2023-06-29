/*
 * Copyright (C) 2023 Johan Dykstrom
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

#include <stdio.h>

#include "assert.h"
#include "lbound_ubound.h"

void should_get_bounds_of_one_dimension_array() {
  // Simulate how JCC arranges variables in memory
  int64_t array[5] = { 2, 1, 10, 20, 30 };
  /*
  printf("array[0] (= size of dimension 1):  %p\n", &array[0]);
  printf("array[1] (= number of dimensions): %p\n", &array[1]);
  printf("array[2] (= actual array):         %p\n", &array[2]);
  */
  option_base(0);
  assert_equals_I64_I64(0,        lbound(&array[2]));
  assert_equals_I64_I64(array[0], ubound(&array[2]));
}

void should_get_bounds_of_two_dimension_array() {
  // Simulate how JCC arranges variables in memory
  int64_t array[9] = { 1, 2, 2, 10, 20, 30, 10, 20, 30 };
  /*
  printf("array[0] (= size of dimension 2):  %p\n", &array[0]);
  printf("array[1] (= size of dimension 1):  %p\n", &array[1]);
  printf("array[2] (= number of dimensions): %p\n", &array[2]);
  printf("array[3] (= actual array):         %p\n", &array[3]);
  */
  option_base(0);
  assert_equals_I64_I64(0,        lbound_I64(&array[3], 1));
  assert_equals_I64_I64(array[1], ubound_I64(&array[3], 1));
  assert_equals_I64_I64(0,        lbound_I64(&array[3], 2));
  assert_equals_I64_I64(array[0], ubound_I64(&array[3], 2));
}

void should_get_bounds_when_option_base_is_1() {
  // Simulate how JCC arranges variables in memory
  int64_t array[11] = { 3, 1, 2, 10, 20, 30, 40, 50, 60, 70, 80 };
  option_base(1);
  assert_equals_I64_I64(1,        lbound_I64(&array[3], 1));
  assert_equals_I64_I64(array[1], ubound_I64(&array[3], 1));
  assert_equals_I64_I64(1,        lbound_I64(&array[3], 2));
  assert_equals_I64_I64(array[0], ubound_I64(&array[3], 2));
}

int main(int argc, char *argv[]) {
  should_get_bounds_of_one_dimension_array();
  should_get_bounds_of_two_dimension_array();
  should_get_bounds_when_option_base_is_1();
}
