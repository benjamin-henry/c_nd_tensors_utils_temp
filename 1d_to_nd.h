#include <stdlib.h>

unsigned int 1d_to_nd_idx(unsigned int dims, unsigned int* shape, unsigned int 1d_idx) {
    // https://stackoverflow.com/questions/29142417/4d-position-from-1d-index
    // x = Index % D1;
    // y = ( ( Index - x ) / D1 ) %  D2;
    // z = ( ( Index - y * D1 - x ) / (D1 * D2) ) % D3;
    // t = ( ( Index - z * D2 * D1 - y * D1 - x ) / (D1 * D2 * D3) ) % D4;
    /* Technically the last modulus is not required,
    since that division SHOULD be bounded by D4 anyways... */
    
    
    /*
    How to use:

        unsigned int* nd_idx = 1d_to_nd_idx(4,(unsigned int[]){2,8,8,3},31);

    OR

        unsigned int dims = 4,
        unsigned int shape[dims] = {2,8,8,3};
        unsigned int 1d_idx = 31;
        unsigned int* nd_idx = 1d_to_nd_idx(dims, shape, 1d_idx); 

    BOTH will return {0,1,2,1}
    */
    unsigned int* prod_accu = (unsigned int*)(malloc(sizeof(unsigned int) * dims));
    prod_accu[dims-1] = 1;
    prod_accu[0] = 1;

    for(int i=dims-1; i>0; --i) {
        prod_accu[dims-i] = prod_accu[dims-i-1] * shape[i];
    }


    unsigned int * idxs = (unsigned int *)(malloc(sizeof(unsigned int) * dims));
    idxs[0] = 1d_idx % shape[dims-1];

    for(int i=1;i<dims;++i) {
        idxs[i] = ((1d_idx - idxs[i-1]) / prod_accu[i]) % shape[dims-1-i];
    }

    unsigned int * reversed = (unsigned int *)(malloc(sizeof(unsigned int) * dims));
    for(int i=0;i<dims;++i) {
        reversed[i] = idxs[dims-1-i];
        printf("%i%s", reversed[i], "\n");
    }
    free(idxs);
    return reversed;
}
  