#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int powerset[1000][1000];

void genPow(){
    int setsize = 10;
    int pow_size = pow(2, setsize);
    int counter, j;

    for(counter = 0; counter < pow_size; counter++){
        for(j = 0; j<setsize; j++){
            if(counter & (1<<j)){
                //powerset[counter][j] = arr[j];
            }
        }
    }
}