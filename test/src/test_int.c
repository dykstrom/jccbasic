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

#include "assert.h"
#include "int.h"

int main(int argc, char *argv[]) {
  assert_equals_I64_I64(99, int_F64(99.3));
  assert_equals_I64_I64(99, int_F64(99.5));
  assert_equals_I64_I64(99, int_F64(99.7));

  assert_equals_I64_I64(-100, int_F64(-99.3));
  assert_equals_I64_I64(-100, int_F64(-99.5));
  assert_equals_I64_I64(-100, int_F64(-99.7));
}
