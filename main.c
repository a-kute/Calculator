#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Basic Calculator
//Welcome to Application
//Ask to input expression
//Evaluate and Ask if User wants to input another expression

//Function Prototypes
int calculate(int,int,char);


int main() {

    //Welcome
    printf("Welcome to the Calculator Application!\nPlease enter a valid expression to evaluate!\n");

    char input[20];


    char* pinput = &input;


    int firstInput;
    char operator;
    int secondInput;
    int counter = 0;

    start: do {

        pinput = calloc(1, sizeof(input));

        if (counter != 0) {
            printf("Enter an Expression\n");
            pinput = calloc(1, (char) 2);
            fgets(pinput,2,stdin);
            free(pinput);
            pinput = calloc(1, sizeof(input));

        }
        counter++;

        fgets(pinput, 21, stdin);
        if (strstr(pinput," ") == NULL) {
            printf("Please enter valid expression with spaces!\n");
            goto start;
        }
        firstInput = atoi(strtok(pinput," "));
        char* modifier = strtok(NULL," ");
        operator = modifier[0];
        secondInput = atoi(strtok(NULL," "));
        printf("%d%c%d = %d\n",firstInput,operator,secondInput,calculate(firstInput,secondInput,operator));
        free(pinput);
        pinput = calloc(1, (char) 4);
        printf("Do you want to enter another equation?\n");
        fgets(pinput, 4, stdin);


    } while (strcmp(pinput,"yes") == 0);
        //Exiting
        printf("Now exiting the application");
}

int calculate(int a, int b, char c) {

    switch (c) {
        case ('+') :
            return a + b;
        case ('-') :
            return a - b;
        case ('*') :
            return a * b;
        case ('/') :
            return a / b;
    }

}



