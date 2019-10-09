#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//there are 5 functions for 5 actions that only describe the action only. 

struct TeaPot {
    int size;
    int teaType;
    int boilingWater;
    int status;
};

// #1
void menu(){
    printf("1. Fetch tea.\n2. Pour spoon tea into the pot.\n3. Add boilling water.\n4. Wait.\n5. Finish\nChoose one(1-5): ");
}

// #2
void fetchTea(struct TeaPot * pot){
    printf("1. Green tea\n2. Black tea\n");
    printf("Choose type of tea (1 - 2 ): ");
    int option;
    scanf("%d",&option);
    fflush(stdin);
    if(option == 1) {
        printf("Fetching green tea.\n");
        pot->teaType = 1;
    }
    else {
        printf("Fetching black tea.\n");
        pot->teaType = 2;
    }
}

// #3
void pourSpoonTeaIntoPot(struct TeaPot * pot){
    char * teaName = (char*)malloc(sizeof(char)*10); 
    if(pot->teaType == 1) strcpy(teaName, "green tea");
    else strcpy(teaName, "black tea");
    pot->size--;
    printf("Putting a spoon of %s tea into the pot.\n", teaName);
}

// #3.5
void putTeaInPot(){
    printf("Putting tea in the pot.\n");
}

// #4
void addBoilingWater(struct TeaPot * pot){
    printf("Adding boiling water.\n");
    pot->boilingWater = 1;
}

// #5
void wait(struct TeaPot * pot) {
    printf("Brewing tea. Waiting...\n");
    pot->status = 1;
}


// Break the process to 5 distinctive steps. All the logic of which step should be done first is well-defined 
// in the main() instead of the function itself. In short, there're some kinds of conditions.
// 
int main(){
    struct TeaPot pot;
    pot.size = 3;
    pot.boilingWater = 0;
    pot.teaType = 0;
    pot.status = 0;
    int option = 0;
    do {
        menu();
        scanf("%d", &option);
        fflush(stdin);
        switch(option){
        case 1: 
            fetchTea(&pot);
            break;
        case 2:
            if(pot.size == 0) printf("The pot is already filled with tea.\n");
            else if (pot.teaType == 0) printf("Fetch tea first.\n");
            else {
                putTeaInPot();    
                while(pot.size > 0){
                    pourSpoonTeaIntoPot(&pot);
                }           
            }
            break;
        case 3:
            if(pot.size != 0) printf("Put tea into the pot first\n");
            else if(pot.boilingWater == 0) addBoilingWater(&pot);
            else printf("The pot is already filled with boiled water.\n");
            break;
        case 4:
            if(pot.boilingWater == 0) printf("Keep waiting...\n");
            else wait(&pot);
            break;
        case 5:
            if(pot.status == 0){
                printf("Tea is not ready.\n");
                option = 1;
            } else printf("Tea is ready.\n");
            break;
        }
    }while(option > 0 && option < 5);  
    
    return 0;
}