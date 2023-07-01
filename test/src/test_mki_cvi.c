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

#include <stdlib.h>

#include "assert.h"
#include "mki_cvi.h"
#include "randomize_rnd.h"
#include "timer.h"

int main(int argc, char *argv[]) {
  char* actual;

  // Test mki$
  actual = mki$(0x0);
  assert_array_equals_char_char("\0\0\0\0\0\0\0\0", actual, 8);
  free(actual);

  actual = mki$(0x61);
  assert_array_equals_char_char("a\0\0\0\0\0\0\0", actual, 8);
  free(actual);

  actual = mki$(0x6261);
  assert_array_equals_char_char("ab\0\0\0\0\0\0", actual, 8);
  free(actual);

  // Test cvi
  assert_equals_I64_I64(0x6261, cvi("ab\0\0\0\0\0\0"));

  // Test converting to a string and then back again
  randomize(timer());

  for (int i = 0; i < 10; i++) {
    int value = rand() * rand() - rand() * rand();
    char *s = mki$(value);
    assert_equals_I64_I64(value, cvi(s));
    free(s);
  }
}
