#ifndef STR_H_
#define STR_H_

// Returns a string representation of the given integer value. This function
// allocates memory. It is the caller's responsibility to free this memory.
char* str_I64(int64_t number);

// Returns a string representation of the given floating point value. This
// function allocates memory. It is the caller's responsibility to free this
// memory.
char* str_F64(double number);

#endif /* STR_H_ */
