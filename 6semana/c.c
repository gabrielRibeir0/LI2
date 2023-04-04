#include <stdio.h>
#include <stdlib.h>

typedef struct pedido{
    int id;
    char dificuldade;
    int preco;
} pedido;
//comparador do qsort(); 0 se p1 e p2 são equivalentes, <0 se p1 é antes de p2 e >0 se p1 é depois de p2
int comparador(const void *p1, const void *p2){
    int preco_p1 = ((pedido *)p1)->preco;
    int preco_p2 = ((pedido *)p2)->preco;

    if(preco_p1 == preco_p2){
        //se o preço for igual, comparar as dificuldades
        char dificuldade_p1 = ((pedido *)p1)->dificuldade;
        char dificuldade_p2 = ((pedido *)p2)->dificuldade;

        if(dificuldade_p1 == dificuldade_p2){
            //se as dificuldades forem iguais, comparar os números do pedido
            int id_p1 = ((pedido *)p1)->id;
            int id_p2 = ((pedido *)p2)->id; 

            return id_p1 - id_p2;
        }
        else
            return dificuldade_p1 - dificuldade_p2;
    }
    else
        return preco_p2 - preco_p1;
}

int main(){
    int n;
    
    if(scanf("%d", &n) != 1){
        return 1;
    }

    pedido listaPedidos[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d %c %d", &listaPedidos[i].id, &listaPedidos[i].dificuldade, &listaPedidos[i].preco) != 3){
            return 1;
        }
    }

    qsort(listaPedidos, n, sizeof(listaPedidos[0]), comparador);

    for(int i = 0; i < n; i++){
        printf("%d %c %d\n", listaPedidos[i].id, listaPedidos[i].dificuldade, listaPedidos[i].preco);
    }
    
    return 0;
}