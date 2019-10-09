#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// There are 3 mains function putTeaInPot (which consists of 3 other small functions), addBoilingWater() and waiting()
// The software describe the procedure of brewing tea.
// There are 3 sub functions.

void pourSpoonTeaIntoPot(char * teaType){
    printf("Pour spoon %s into pot.\n", teaType);
}

void fetchGreenTea(){
    printf("Fetching green tea.\n");
}

void fetchBlackTea(){
    printf("Fetching black tea.\n");
}

void putTeaInPot(){
    printf("1. Green tea\n2. Black tea\n");
    printf("Choose type of tea (1 - 2 ): ");
    int option;
    scanf("%d",&option);
    fflush(stdin);
    char * teaType = (char *)malloc(sizeof(char)*11);
    if(option == 1) {
        fetchGreenTea();
        strcpy(teaType, "Green Tea");
    } else {
        fetchBlackTea();
        strcpy(teaType, "Black Tea");
    } 
    pourSpoonTeaIntoPot(teaType);
}

void addBoilingWater(){
    printf("Adding boiling water.\n");
}

void waiting(){
    printf("Brewing tea. Waiting....\n");
}

int main(){
    putTeaInPot();
    addBoilingWater();
    waiting();
    return 0;
}