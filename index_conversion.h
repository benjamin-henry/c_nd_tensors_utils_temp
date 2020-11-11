#ifndef INDEX_CONVERSION_H
#define INDEX_CONVERSION_H

#include <stdlib.h>

// https://stackoverflow.com/questions/29142417/4d-position-from-1d-index

unsigned int* get_shape_factorials(unsigned int dims, unsigned int* shape);
unsigned int to_1d(unsigned int dims, unsigned int* shape, unsigned int* idxs, unsigned int* shape_factorials);
unsigned int * to_nd(unsigned int dims, unsigned int* shape, unsigned int index, unsigned int* shape_factorials);

#endif