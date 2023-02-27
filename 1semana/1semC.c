#include <stdio.h>

int main(){
    int x,y,z,aux;
    x = y = z = 1;
    
    if (scanf("%d",&aux)) x = aux;
    if (scanf("%d",&aux)) y = aux;
    if (scanf("%d",&aux)) z = aux;

    if (x>y){
        aux = x;
        x = y;
        y = aux;
    }
    if (y>z){
        aux = y;
        y = z;
        z = aux;
    }
    if (x>y){
        aux = x;
        x = y;
        y = aux;
    }

    printf("%d %d %d\n",x, y, z);

    return 0;
}