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

#ifndef RANDOMIZE_RND_H_
#define RANDOMIZE_RND_H_

// Reseeds the random number generator.
void randomize(double seed);

// Returns the next pseudo-random number in the sequence.
double rnd();

// Returns the next pseudo-random number in the sequence, after possibly
// reseeding the random number generator. Depending on the specified seed,
// the following can happen:
//   seed < 0.0   reseeds the random number generator, and returns the
//                next pseudo-random number in the sequence
//   seed = 0.0   returns the last number generated
//   seed > 0.0   returns the next pseudo-random number in the sequence
double rnd_F64(double seed);

#endif /* RANDOMIZE_RND_H_ */
