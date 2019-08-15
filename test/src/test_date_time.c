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

#include <stdlib.h>
#include <string.h>

#include "assert.h"
#include "date_time.h"

int main(int argc, char *argv[]) {
  char* actual = date$();
  assert_equals_I64_I64(10, strlen(actual));
  assert_true_Bool(actual[2] == '-');
  assert_true_Bool(actual[5] == '-');
  free(actual);

  actual = time$();
  assert_equals_I64_I64(8, strlen(actual));
  assert_true_Bool(actual[2] == ':');
  assert_true_Bool(actual[5] == ':');
  free(actual);
}
