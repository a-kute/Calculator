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

    //take input
    char input[20];
    int firstInput;
    char operator;
    int secondInput;
    start: do {
        fgets(input, sizeof(input), stdin);
        if (strstr(input," ") == NULL) {
            printf("Please enter valid expression with spaces!\n");
            goto start;
        }
        firstInput = atoi(strtok(input," "));
        char* modifier = strtok(NULL," ");
        operator = modifier[0];
        secondInput = atoi(strtok(NULL," "));
        printf("%d%c%d = %d\n",firstInput,operator,secondInput,calculate(firstInput,secondInput,operator));
        printf("Do you want to enter another equation?\n");
        fgets(input, sizeof(input), stdin);
    } while (strcmp(input,"yes") == 0);
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



