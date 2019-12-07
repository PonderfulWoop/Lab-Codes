#include <stdio.h>
#include <stdlib.h>

#define SEGS 5


int seg_table[SEGS][2];

void createTable(int base[], int limit[]){
    for(int i = 0; i<SEGS; i++){
        seg_table[i][0] = limit[i];
        seg_table[i][1] = base[i];
    }
}

int computePhy(int segment, int offset){
    int phyAddr;
    if(offset > seg_table[segment][0])
        return -1;
    else{
        phyAddr = seg_table[segment][1] + offset;
        return phyAddr;
    }
}

int main(){
    int base[SEGS], limit[SEGS];

    printf("Enter Limits and Bases for the 5 segments: \n");
    for(int i = 0; i<SEGS; i++){
        scanf("%d %d", &limit[i], &base[i]);
    }

    createTable(base, limit);

    int segment, offset;

    printf("Enter segment number and offset:\n");
    scanf("%d %d", &segment, &offset);

    if(computePhy(segment, offset) == -1)
        printf("Addressing Trap.\n");
    else
        printf("Physical Address: %d\n", computePhy(segment, offset));


    exit(0);
}