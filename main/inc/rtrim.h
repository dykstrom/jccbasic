#ifndef RTRIM_H_
#define RTRIM_H_

// Returns a copy of the given string, with trailing whitespace removed.
// This function allocates memory. It is the caller's responsibility to
// free this memory.
char* rtrim(const char* s);

#endif /* RTRIM_H_ */
