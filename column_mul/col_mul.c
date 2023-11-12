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
    int i, j, pos;        //pos is the index of v3: it starts at 2*n+1
    int carry, shift;     //carry of the mul of 2 digits, shift of the res

    for(i=3; i>0; i-- ){  //external loop iterates on v2 multiplicator
        
        for(j=3; j>0; j++){ //internal loop iterates on v1 multiplicand
            v3[pos] = (v2[i] * v1[j]) + carry;
            carry = v3[pos] % 10;
        }
    }


}