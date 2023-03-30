#include <stdlib.h>

typedef struct cozinheiro{
        char nome[21];
        int peso;
        int altura;
    } cozinheiro;

void comparar(cozinheiro, cozinheiro){
    //primerio pela diferença a 90 peso
    //depois altura
    //depois nome
}

//função de trocar, da para remover
void swap_employee(cozinheiro *left, cozinheiro *right)
{
    cozinheiro tmp = *right;
    *right = *left;
    *left = tmp;
}

void ordenar(cozinheiro *arr, int left, int right)
{
    cozinheiro p = arr[(left+right)/2];    // as good as any
    int l = left, r = right;   // movable indicies

    while (l <= r)
    {
        while (compare_employee(arr+l, &p) < 0)
            ++l;
        while (compare_employee(arr+r, &p) > 0)
            --r;
        if (l <= r)
        {
            swap_employee(arr+l, arr+r);
            ++l; --r;
        }
    }

    if (left < r)
        ordenar(arr, left, r);
    if (l < right)
        ordenar(arr, l, right);
}


int main(){
    int n;
    
    if(scanf("%d", &n) != 1){
        return 1;
    }

    cozinheiro pessoas[n];

    for(int i = 0; i < n; i++){
        if(scanf("%s %d %d", pessoas[i].nome, pessoas[i].peso, pessoas[i].altura) != 3){
            return 1;
        }
    }

    //sort cozinheiro
    
    return 0;
}