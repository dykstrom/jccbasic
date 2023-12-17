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
#include "sleep.h"
#include "timer.h"

int main(int argc, char *argv[]) {
  double start, stop;

  start = timer();
  sleep_F64(0.1);
  stop = timer();
  assert_true_Bool(stop - start >= 0.1);
  assert_true_Bool(stop - start < 0.2);

  start = timer();
  sleep_F64(0.5);
  stop = timer();
  assert_true_Bool(stop - start >= 0.5);
  assert_true_Bool(stop - start < 0.6);
}
