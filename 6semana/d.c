#include <stdio.h>

/*
fazer o maior de cada pedido + maior dos lucros possiveis
o maior dos lucros possiveis é com o tempo + tempo do anterior e lucro + lucro do anterior
se der tempo para fazer, ver o maior dos luros possiveis com esse
se nao saltar

se nao houver nenhum que de tempo chegou ao fim, retornar 0 so


chamada da função inicial, devolver 
*/

typedef struct pedido{
    int tempoEntrega;
    int tempoConfecao;
    int lucro;
} pedido;

int estaNaLista(int lista[], int n, int x){
    for(int i = 0; i < n; i++){
        if(lista[i] == x)
            return 1;
    }
    return 0;
}

int maxLista(int lista[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(lista[i] > max){
            max = lista[i];
        }
    }
    return max;
}

int lucroMax(int tracker,int pedidosPassados[], pedido lista[], int n,int pedidoFeito, int tempo, int lucro){
    int cont = 0;
    int listaLucro[n];

    if(tracker == 0)
        pedidosPassados[0] = pedidoFeito;

    for(int i = 0; i < n; i++){
        if()
            continue;
        if(lista[i].tempoEntrega >= tempo + lista[i].tempoConfecao){
            listaLucro[i] = lucro + lista[i].lucro + lucroMax(tracker, pedidosPassados, lista,  n, i , lista[i].tempoEntrega, lucro + lista[i].lucro);
            cont++;
        }
    }

    if(cont == 0)
        return 0;
    
    return maxLista(listaLucro, cont);
}

//alterar passagem de structs com aquilo de pointers (?)
int maior(pedido lista[], int n){
    int tracker = 0;
    int listaLucros[n];
    int pedidosPassados[n];
    for(int i = 0; i < n; i++){
        listaLucros[i] = lucroMax(tracker, pedidosPassados, lista, n ,i, lista[i].tempoEntrega, lista[i].lucro);
    }

    return maxLista(listaLucros, n);
}
 
int main(){
    int n, tmp;

    if(scanf("%d", &n) != 1){
        return 1;
    }

    pedido listaPedidos[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d %d %d %d", &tmp, &listaPedidos[i].tempoEntrega, &listaPedidos[i].tempoConfecao, &listaPedidos[i].lucro) != 4){
            return 1;
        }
    }

    printf("%d\n", maior(listaPedidos, n));

    return 0;
}