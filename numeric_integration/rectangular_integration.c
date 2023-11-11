#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 10
float HornerEvaluation(int P[],float x);

int main(){
    int coeff[max]={0}, i;
    int grade, a, b, M; //grade, extremes, # of intervals
    float x_tilde, h;   //x_tilde is the median point of the interval h
    float integral;

    printf("Insert the grade: ");
    scanf(" %d", &grade);
    if(grade <= max){
        printf("Insert the %d+1 coeffcients:\n", grade);
        for(i=0; i<=grade; i++){
            scanf(" %d", &coeff[i]);            
        }
    }else{
        printf("Grade not valid\n");
        return -1;
    }

    printf("Insert the extremes of integration:");
    scanf("%d %d", &a, &b);
    printf("Insert M: ");
    scanf("%d", &M);

    h =  (b-a)/(float)M;
    x_tilde = a + h/(float)2 ;
    
    //printf("a= %d, b=%d\n", a,b);
    //printf("Median point: %f\n", x_tilde);
    //printf("Width of an interval is %f\n", h);

    //HornerEvalution is called for M times, evaluating the polynom in x_tilde
    for(i=0;i<M;i++){
        integral = integral + HornerEvaluation(coeff, x_tilde);
        x_tilde = x_tilde + h;
    }
    printf("The result of the integration is %f\n", integral*h);
    return 0;
}

float HornerEvaluation(int P[],float x){
    float res = 0.0;
    int i;
    //Considering grade=4
    //p(x)=(((((c4x + c3)x + c2)x + c1)x + c0)
    for(i=max;i>=0;i--){
        res = res*x + P[i];
    }
    return res;
}