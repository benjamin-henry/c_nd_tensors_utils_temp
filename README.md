C language -> Index Conversion between 1-D and N_D arrays  

example 1 :

```c
#include <stdio.h>
#include <stdlib.h>

#include "index_conversion.h"

int main() {
    unsigned int dims = 4;
    unsigned int shape[] = {2,8,8,3};
    unsigned int nd_idxs[] = {0,2,5,1};

    unsigned int* fact = get_shape_factorials(dims, shape);
    unsigned int idx = to_1d(dims, shape, nd_idxs, fact);
    unsigned int* idxs = to_nd(dims, shape, idx, fact);

    printf("%i%s", idx, "\n");
    for(int i = 0; i < dims; ++i) {
        printf("%i%s", idxs[i], ", ");
    }
    printf("%s", "\n");

    free(fact);
    free(idxs);

    return 0;
}

/*
Console output:
    64
    0, 2, 5, 1,
*/
```


example 2 :

```c
#include <stdio.h>
#include <stdlib.h>

#include "index_conversion.h"

int main() {
    // unsigned int dims = 4;
    // unsigned int shape[] = {2,8,8,3};
    // unsigned int nd_idxs[] = {0,2,5,1};

    unsigned int* fact = get_shape_factorials(4, (unsigned int[]){2,8,8,3});
    unsigned int idx = to_1d(4, (unsigned int[]){2,8,8,3}, (unsigned int[]){0,2,5,1}, fact);
    unsigned int* idxs = to_nd(4, (unsigned int[]){2,8,8,3}, idx, fact);

    printf("%i%s", idx, "\n");
    for(int i = 0; i < 4; ++i) {
        printf("%i%s", idxs[i], ", ");
    }
    printf("%s", "\n");

    free(fact);
    free(idxs);

    return 0;
}

/*
Console output:
    64
    0, 2, 5, 1,
*/
```