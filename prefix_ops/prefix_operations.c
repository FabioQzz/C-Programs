#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

float prec = 0;

float operand(char s[], float prec);

void main(){
    char op;
    char operand1[max], operand2[max];
    int finish=0;
    float op1, op2, res;

    while(!finish){
        printf("Reading from stdin the expression:\n");
        fscanf(stdin," %c", &op);
        fscanf(stdin,"%s %s", operand1, operand2);
        op1 = operand(operand1,prec); //conversion from string2float
        op2 = operand(operand2,prec); //conversion from string2float

        switch (op)
        {
        case '+':
            res = op1 + op2;    
            break;
        case '-':
            res = op1 - op2;
            break;
        case '*':
            res = op1 * op2;
            break;
        case '/':
            res = op1 / op2;
            break;
        case '!':
            printf("Termination case\n");
            finish = 1;
            break;
        default:
            printf("Wrong operation inserted\n");
            break;
        } 

        prec = res;
        printf("Risultato: %f\n", res);

    }

}


float operand(char s[], float prec){
    float op;
    if(strcmp(s,"PREC")== 0){
        op = prec; 
    }else{
        op = atof(s);
    }

    return op;
}
