#include <stdlib.h>
#include "index_conversion.h"

// https://stackoverflow.com/questions/29142417/4d-position-from-1d-index

unsigned int* get_shape_factorials(unsigned int dims, unsigned int* shape){
    unsigned int* factorials = (unsigned int*)(malloc(sizeof(unsigned int) * dims));
    factorials[dims-1] = 1;
    factorials[0] = 1;

    for(unsigned int i = dims - 1; i>0; --i) {
        factorials[dims-i] = factorials[dims-i-1] * shape[i];
    }

    return factorials;
}

unsigned int to_1d(unsigned int dims, unsigned int* shape, unsigned int* idxs, unsigned int* shape_factorials){
    unsigned int index_1d = 0;
    for(int i=0; i < dims; ++i) {
        index_1d += shape_factorials[dims-i-1] * idxs[i];
    }
    return index_1d;
}

unsigned int * to_nd(unsigned int dims, unsigned int* shape, unsigned int index, unsigned int* shape_factorials){
    unsigned int * idxs = (unsigned int *)(malloc(sizeof(unsigned int) * dims));
    idxs[0] = index % shape[dims-1];

    for(int i = 1; i < dims; ++i) {
        idxs[i] = ((index - idxs[i-1]) / shape_factorials[i]) % shape[dims-1-i];
    }

    unsigned int * reversed = (unsigned int *)(malloc(sizeof(unsigned int) * dims));
    for(int i = 0; i < dims; ++i) {
        reversed[i] = idxs[dims-1-i];
    }
    free(idxs);
    return reversed;
}
