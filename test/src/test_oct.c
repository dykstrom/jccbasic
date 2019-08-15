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
#include "oct.h"

int main(int argc, char *argv[]) {
  char* actual;

  actual = oct$(0);
  assert_equals_Str_Str("0", actual);
  free(actual);

  actual = oct$(10);
  assert_equals_Str_Str("12", actual);
  free(actual);

  actual = oct$(255);
  assert_equals_Str_Str("377", actual);
  free(actual);

  actual = oct$(-1);
  assert_equals_Str_Str("1777777777777777777777", actual);
  free(actual);

  actual = oct$(123456789);
  assert_equals_Str_Str("726746425", actual);
  free(actual);
}
