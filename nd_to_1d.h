#include <stdlib.h>

int nd_to_1d_idx(unsigned int dims, unsigned int* shape, unsigned int* idxs) {
    // https://stackoverflow.com/questions/29142417/4d-position-from-1d-index

    /*
    How to use:

        unsigned int index = nd_to_1d_idx(4,(unsigned int[]){2,8,8,3},(unsigned int[]){0,1,2,1});

    OR

        unsigned int dims = 4,
        unsigned int shape[dims] = {2,8,8,3};
        unsigned int nd_idx[dims] = {0,1,2,1};
        unsigned int index = nd_to_1d_idx(dims, shape, nd_idx); 

    BOTH will return 31
    */
    
    unsigned int* reversed = (unsigned int*)(malloc(sizeof(unsigned int) * dims-1));
    if(dims > 0) {
        if(dims < 2) {
            reversed[0] = 1;
        }
    }    
    
    unsigned int* prod_accu = (unsigned int*)(malloc(sizeof(unsigned int) * dims-1));
    prod_accu[0]=1;

    for(int i=dims-1; i>0; --i) {
        prod_accu[dims-i]=1;
        prod_accu[dims-i]=prod_accu[dims-i-1] * shape[i];
    }

    for(int i=0; i<dims; ++i) {
        reversed[i] = prod_accu[dims-i-1];
    }
    free(prod_accu);
    unsigned int index_1d = 0;
    for(int i=0; i<t->dims; ++i) {
        index_1d += reversed[i] * idxs[i];
    }
    free(reversed);
    return index_1d;
}




