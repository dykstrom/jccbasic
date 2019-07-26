#ifndef LTRIM_H_
#define LTRIM_H_

// Returns a copy of the given string, with leading whitespace removed.
// This function allocates memory. It is the caller's responsibility to
// free this memory.
char* ltrim(const char* s);

#endif /* LTRIM_H_ */
