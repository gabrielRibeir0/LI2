#include <stdio.h>
#include <stdlib.h>

typedef struct pedido{
    int id;
    int tempoEntrega;
    int tempoConfecao;
    int lucro;
    int tempoMinimo;
} pedido;

typedef struct pilhaPedidos {
    pedido* listaPedidos;
    int numPedidos;
    int tempoAcumulado;
    int lucroAcumulado;
} pilhaPedidos;   

int comparador(const void *p, const void *q) 
{
    int l = ((pedido *)p)->tempoMinimo;
    int r = ((pedido *)q)->tempoMinimo; 
    return (l - r);
}
//função para calcular o maior elemento numa lista (usada para calcular o maior lucro)
int maxLista(int lista[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(lista[i] > max){
            max = lista[i];
        }
    }
    return max;
}

int calculaLucro(pedido listaPedidos[], int numPedidos, int tempoAcumulado, int lucroAcumulado){
    int listaLucros[numPedidos]; //array para guardar os lucros que se consegue fazendo cada pedido

    //inicializar os lucros de cada pedido com um número baixo
    for(int i = 0; i < numPedidos; i++){
        listaLucros[i] = -1;
    }

    int cont = 0;

    for(int i = numPedidos - 1; i >= 0; i--){
        //começar a verificar no fim da lista até encontrar o 1º pedido que não pode ser realizado (os que estão para trás também não vão poder)
        if(listaPedidos[i].tempoMinimo < tempoAcumulado){
            break;
        }
        cont++;
    }

    int aux = numPedidos - cont;

    if(cont == 0){ //se o contador de pedidos possíveis for 0, devolver o lucro que foi acumulado
        return lucroAcumulado;
    }
    else{
        for(int i = aux; i < numPedidos; i++){
            listaLucros[i] = calculaLucro(listaPedidos + aux, cont, listaPedidos[i].tempoEntrega, lucroAcumulado + listaPedidos[i].lucro);
        }
    }

    return maxLista(listaLucros + aux, cont); //return do maior lucro da lista (i.e maior lucro a partir de todas as combinações daqui para a frente)
}

int main(){
    int n;

    if(scanf("%d", &n) != 1){
        return 1;
    }

    pedido listaPedidos[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d %d %d %d", &listaPedidos[i].id, &listaPedidos[i].tempoEntrega, &listaPedidos[i].tempoConfecao, &listaPedidos[i].lucro) != 4){
            return 1;
        }
        listaPedidos[i].tempoMinimo = listaPedidos[i].tempoEntrega - listaPedidos[i].tempoConfecao; //tempo mínimo para começar o pedido
    }

    qsort(listaPedidos, n, sizeof(listaPedidos[0]), comparador);

    int listaLucros[n]; //array para guardar o maior lucro começando por fazer cada um dos pedidos
    for(int i = 0; i < n; i++){
        //guardar o lucro máximo possível ao começar neste pedido no array
        listaLucros[i] = calculaLucro(listaPedidos + i + 1, n - i - 1, listaPedidos[i].tempoEntrega, listaPedidos[i].lucro);
    }

    printf("%d\n", maxLista(listaLucros,n));
    return 0;
}