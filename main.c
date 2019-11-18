#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 10
#define MAX_DRINK_NAME 10
#define MAX_FOODTYPE_NAME 20
#define MAX_LINE 10
void readFoodTypes(char * model);

int main() {
    int noOfFood;
    printf("Please input number of food types\n");
    scanf("%d",&noOfFood);
    char ** food;
    printf("Please input the food types \n");
    food = (char**)malloc(noOfFood* sizeof(char*));
    for(int i=0;i<noOfFood;i++) {
        // read each brand
        food[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        scanf("%s",food[i]);
    }

    int * noOfFoodTypes= (int*)malloc(noOfFood * sizeof(int));
    char *** FoodTypes = (char***)malloc(noOfFood * sizeof(char**));
    double ** prices = (double**)malloc(noOfFood* sizeof(double*));
    for(int i=0; i<noOfFood; i++) {
        // read no of models
        printf("Please input no of speciffic foods for food %s\n",food[i]);
        scanf("%d",&noOfFoodTypes[i]);
        getchar();

        //read models & prices
        FoodTypes[i] = (char**)malloc(noOfFoodTypes[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfFoodTypes[i]* sizeof(double));

        printf("Please input %s speciffic foods &prices: each line in the format <speciffic food>,(price)\n",food[i]);
        for(int j=0;j<noOfFoodTypes[i];j++){

            FoodTypes[i][j] = (char*)malloc(MAX_FOODTYPE_NAME* sizeof(char));
            readFoodTypes(FoodTypes[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &prices[i][j]);
        }
    }
    int noOfDrinks;
    printf("Please input number of drinks\n");
    scanf("%d",&noOfDrinks);
    char ** drinks = (char**)malloc(noOfDrinks* sizeof(char*));
    double * drinksPrices = (double*)malloc(noOfDrinks* sizeof(double));
    getchar();
    printf("Please input the drinks: each line in the format <drink> (price): \n");
    for(int i=0;i<noOfDrinks;i++) {
        char line[MAX_LINE];
        gets(line);
        drinks[i] = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
        sscanf(line, "%s %d\n",drinks[i], &drinksPrices[i]);

    }
    // display data
    printf("The food data is:\n");
    for(int i=0;i<noOfFood;i++) {
        // display brand
        printf("%s: ", food[i]);
        for(int j=0;j<noOfFoodTypes[i];j++) {
            printf("%s (%.2lf)",FoodTypes[i][j],prices[i][j]);
            if(j<noOfFoodTypes[i]-1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("The drink data is:\n");
    printf("drinks: ");
    for(int i=0;i<noOfDrinks;i++){
        printf("%s ",drinks[i]);
        if(i<noOfDrinks-1){
            printf(", ");
        }
    }
    printf("\n");
    printf("prices: ");
    for(int i=0;i<noOfDrinks;i++){
        printf("%d",drinksPrices[i]);
        if(i<noOfDrinks-1){
            printf(",");
        }

    }
    // free memory
    for(int i=0;i<noOfFood;i++) {
        for(int j=0;j<noOfFoodTypes[i];j++) {
            free(FoodTypes[i][j]);
        }
        free(FoodTypes[i]);
        free(prices[i]);
        free(food[i]);
    }
    free(FoodTypes);
    free(prices);
    free(food);
    free(noOfFoodTypes);
    for(int i=0;i<noOfDrinks;i++){
        free(drinks[i]);
    }
    free(drinks);
    free(drinksPrices);
    return 0;
}

void readFoodTypes(char * FoodTypes) {
    char c = getchar();
    int i=0;
    while(c!=',') {
        FoodTypes[i] = c;
        c = getchar();
        i++;
    }
    FoodTypes[i] = '\0';
}
