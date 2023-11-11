#include <stdio.h>
#include <stdlib.h>

#define max 10
float valutaHorner(float P[11],float x);

void main(){
    int coeff[max], i;
    int grade, a, b, M;

    printf("Insert the grade: ");
    scanf(" %d", &grade);
    if(grade <= max){
        printf("Insert the %d+1 coeffcients:\n", grade);
        for(i=0; i<=grade; i++){
            scanf(" %d", &coeff[i]);            
        }
    }else{
        printf("Grade not valid\n");
        return;
    }

    printf("Insert the extremes of integration: ");
    scanf("%d %d\n", &a, &b);
    printf("Insert M: ");
    scanf("%d\n", &M);





}