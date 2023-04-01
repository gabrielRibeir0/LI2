#include <stdio.h>

typedef struct pedido{
    int id;
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

int lucroMax( pedido listaPedidos[], int pedidoAnterior, int tempo, int lucroAcumulado, int pedidosPassados[], int numPedidos, int contagemPedidos){
    //se a sequência do caminho já tiver o num de pedidos, quer dizer que chegamos ao fim das combinações e devolve o lucro acumulado (caso paragem)
    if(contagemPedidos == numPedidos)
        return lucroAcumulado;

    //se for a primeira chamada da função
    if(contagemPedidos == 0){
        pedidosPassados[0] = pedidoAnterior;
        contagemPedidos++;
    }

    int listaLucro[numPedidos - contagemPedidos]; //só é preciso guardar os lucros de n - contagem caminhos, os que já passamos não é preciso contar
    int j = 0;
    for(int i = 0; i < numPedidos; i++){
        if(estaNaLista(pedidosPassados, contagemPedidos, listaPedidos[i].id))
            continue;

        pedidosPassados[contagemPedidos] = listaPedidos[i].id;
        
        if(listaPedidos[i].tempoEntrega >= tempo + listaPedidos[i].tempoConfecao){
            listaLucro[j] = lucroMax(listaPedidos, listaPedidos[i].id, listaPedidos[i].tempoEntrega, listaPedidos[i].lucro + lucroAcumulado, pedidosPassados, numPedidos, contagemPedidos + 1);
            j++;
        }

    }
    
    if(j == 0)
        return 0;
    else
        return maxLista(listaLucro, j);
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
    }

    int contagemPedidos = 0;
    int listaLucros[n];
    int pedidosPassados[n];
    for(int i = 0; i < n; i++){
        listaLucros[i] = lucroMax(listaPedidos, listaPedidos[i].id, listaPedidos[i].tempoEntrega, listaPedidos[i].lucro, pedidosPassados, n, contagemPedidos);
    }


    printf("%d\n", maxLista(listaLucros, n));

    return 0;
}