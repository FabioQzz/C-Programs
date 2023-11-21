#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void readSet(int Set[], int n);

int main(){
    int V1[MAX], V2[MAX];
    int n;
    
    printf("Insert the dimension of Set 1:");
    scanf("%d", &n);
        if(n>0 && n <= MAX )
            readSet(V1, n);
        else
            return -1;
        
    printf("Insert the dimension of Set 2:");
    scanf("%d", &n);
        if(n>0 && n <= MAX )
            readSet(V2, n);
        else
            return -1;

    

    return 0;
}

//This function reads the sets
void readSet(int Set[], int n){
    int i;
    printf("Inserting set:\n");
    for(i=0; i<n; i++){
        scanf("%d", &Set[i]);
    }
}
