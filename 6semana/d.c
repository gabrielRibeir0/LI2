#include <stdio.h>

typedef struct pedido{
    int id;
    int tempoEntrega;
    int tempoConfecao;
    int lucro;
} pedido;

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

int calculaLucro(pedido listaPedidos[], int numPedidos, int tempoAcumulado, int lucroAcumulado, int pedidosPossiveis[]){
    int listaLucros[numPedidos]; // array para guardar os lucros que se consegue fazendo cada pedido
    int copiaPedidos[numPedidos]; // array para fazer uma cópia dos pedidos possíveis, de forma a não alterar o array original

    //inicializar os lucros de cada pedido com um número baixo
    for(int i = 0; i < numPedidos; i++){
        listaLucros[i] = -1;
    }

    int cont = 0;

    for(int i = 0; i < numPedidos; i++){
        //alterar a possibilidade do pedido em função do tempo e se já foi feito e aumentar o contador
        if(pedidosPossiveis[i] && listaPedidos[i].tempoEntrega >= tempoAcumulado + listaPedidos[i].tempoConfecao){
            pedidosPossiveis[i] = 1;
            cont++;
        }
        else{
            pedidosPossiveis[i] = 0;
        }
    }

    if(cont == 0){ //se o contador de pedidos possíveis for 0, devolver o lucro que foi acumulado
        return lucroAcumulado;
    }
    else{
        for(int i = 0; i < numPedidos; i++){
            if(pedidosPossiveis[i]){ //se o pedido for possível calcular o lucro ao fazer esse pedido (max das combinações para a frente) e guardar no array
                for(int j = 0; j < numPedidos; j++){
                    copiaPedidos[j] = pedidosPossiveis[i];
                }
                copiaPedidos[i] = 0;
                listaLucros[i] = calculaLucro(listaPedidos, numPedidos, listaPedidos[i].tempoEntrega, lucroAcumulado + listaPedidos[i].lucro, copiaPedidos);
            }
            
        }
    }

    return maxLista(listaLucros, numPedidos); //return do maior lucro da lista (i.e maior lucro a partir de todas as combinações daqui para a frente)
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

    int listaLucros[n]; //array para guardar o maior lucro começando por fazer cada um dos pedidos
    int pedidosPossiveis[n]; //pedidos que é possível realizar, 1 se sim, 0 se não (é 0 se o pedido já tiver sido concluído ou se não tiver tempo)
    for(int i = 0; i < n; i++){
        //inicializar todos os pedidos como possíveis
        for(int j = 0; j < n; j++){
            pedidosPossiveis[j] = 1;
        }
        pedidosPossiveis[i] = 0; //o pedido em que começa deixa de ser possível fazer de novo

        //guardar o lucro máximo possível ao começar neste pedido no array
        listaLucros[i] = calculaLucro(listaPedidos, n, listaPedidos[i].tempoEntrega, listaPedidos[i].lucro, pedidosPossiveis);
    }

    printf("%d\n", maxLista(listaLucros,n)); //print do maior lucro
    return 0;
}