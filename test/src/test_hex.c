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

#include "assert.h"
#include "hex.h"

int main(int argc, char *argv[]) {
  char* actual;

  actual = hex$(0);
  assert_equals_Str_Str("0", actual);
  free(actual);

  actual = hex$(10);
  assert_equals_Str_Str("A", actual);
  free(actual);

  actual = hex$(255);
  assert_equals_Str_Str("FF", actual);
  free(actual);

  actual = hex$(-1);
  assert_equals_Str_Str("FFFFFFFFFFFFFFFF", actual);
  free(actual);

  actual = hex$(123456789);
  assert_equals_Str_Str("75BCD15", actual);
  free(actual);
}
