#include <stdio.h>

int main(){
    int a,b,c,var;
    a = b = c = var = 1;
    
    if (scanf("%d", &var) == 1) a = var;
    if (scanf("%d", &var) == 1) b = var;
    if (scanf("%d", &var) == 1) c = var;

    if (a==b || b==c)
        printf("OK\n");
    else if ((a>b && b>=c) || (a<b && b<=c))  
        printf("OK\n");
    else 
        printf("NAO\n");
    return 0;
}