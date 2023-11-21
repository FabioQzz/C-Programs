#include <stdio.h>
#include <stdlib.h>

void mul(int *v1, int *v2, int n, int *v3);

int main(){
    //supposing simplified input with n=3
    int n=3;
    int v1[]= {0,3,2};
    int v2[]= {2,4,3};
    int v3[6]= {0};     //to avoid overflow, the res is on n*2 bits

    mul(v1,v2,n,v3);

    return 0;
}

void mul(int *v1, int *v2, int n, int *v3){
    int i, j, pos, sum;         //pos is the index of v3: it starts at 2*n+1
    int carry=0, shift;         //carry of the mul of 2 digits, shift of the res

    for(i=n-1, shift=0; i>=0; i--, shift++ ){  //external loop iterates on v2 multiplicator
        carry= 0;
        for(j= n-1, pos= 2*n-1; j>=0; j--, pos--){ //internal loop iterates on v1 multiplicand
            sum = v3[pos-shift] + (v2[i] * v1[j]) + carry;
            v3[pos-shift] = sum % 10;
            carry = sum / 10;
            printf("carry: %d\n", carry);
        }
        if(carry!=0){
            v3[pos-shift]= carry;
        }
    }

    printf("Product = ");
    for(j=0; j<2*n; j++){
        printf("%d", v3[j]);
    }
}