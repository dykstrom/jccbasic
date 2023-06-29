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

#ifndef LBOUND_RBOUND_H_
#define LBOUND_RBOUND_H_

#include <stdint.h>

// Sets OPTION BASE to the given value (0 or 1). Note that
// OPTION BASE affects only the lower bound of arrays.
void option_base(int64_t new_base);

// Returns the lower bound (smallest available subscript)
// for the first dimension of an array.
int64_t lbound(const void* array);

// Returns the lower bound (smallest available subscript)
// for the indicated dimension of an array.
int64_t lbound_I64(const void* array, int64_t dimension);

// Returns the upper bound (largest available subscript)
// for the first dimension of an array.
int64_t ubound(const void* array);

// Returns the upper bound (largest available subscript)
// for the indicated dimension of an array.
int64_t ubound_I64(const void* array, int64_t dimension);

#endif /* LBOUND_RBOUND_H_ */
