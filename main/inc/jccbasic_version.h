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

#ifndef JCCBASIC_VERSION_H_
#define JCCBASIC_VERSION_H_

#include <stdint.h>

// Returns the current version of the JCC Basic standard library as a 64-bit
// integer. The last three digits of this integer represent the patch level.
// The three digits to the left of the patch level represent the minor version,
// and all the digits to the left of the minor version represent the major
// version. As an example, the version 1.12.7 would be returned as 1012007.
int64_t jccbasic_version();

#endif /* JCCBASIC_VERSION_H_ */
