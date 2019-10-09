#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// There are 3 distinctive big steps.
// Since this is the algorithmic_decomposition so all the steps are already set up in order.
// All the conditions are coded inside the function so it will return different values based on the value of the 
// assigned parameteres.

void getTeaLeavesReady(int *teaLeaves){
    if(*teaLeaves == 0){
        printf("1. Green tea\n2. Black tea\n");
        printf("Choose type of tea (1 - 2 ): ");
        int option;
        scanf("%d",&option);
        fflush(stdin);
        char * teaType = (char *)malloc(sizeof(char)*11);
        if(option == 1) {
            printf("Fetching green tea.\n");
            strcpy(teaType, "Green Tea");
        } else {
            printf("Fetching black tea.\n");
            strcpy(teaType, "Black Tea");
        }
        printf("Pour spoon %s into pot.\n", teaType);
        *teaLeaves = 1; 
    } else {
        printf("The tea leaves are ready.\n");
    }
}

void pouringWater(int * water){
    if(*water == 0) {
        printf("Pouring boiled water.\n");
        *water = 1;
    }
        
    else printf("The pot is filled with boiled water.\n");
}

void wait(int teaLeaves, int water){
    if(teaLeaves == 1 && water == 1){
        printf("Brewing. Waiting.\nTea is ready.\n");
    } else {
        printf("The pot is not ready yet.");
    }
}

int main(){
    int teaLeaves = 0;
    int water = 0;
    getTeaLeavesReady(&teaLeaves);
    pouringWater(&water);
    wait(teaLeaves, water);
    return 0;
}