#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cozinheiro{
    char nome[21];
    int peso;
    int altura;
} cozinheiro;

//comparador do qsort()
int comparador(const void *c1, const void *c2){
    int peso_c1 = ((cozinheiro *)c1)->peso;
    int peso_c2 = ((cozinheiro *)c2)->peso;
    int r = abs(90 - peso_c1) - abs(90 - peso_c2); //diferença da distância a 90 dos pesos
    if(r == 0){
        //se a distância a 90 for igual, comparar as alturas
        int altura_c1 = ((cozinheiro *)c1)->altura;
        int altura_c2 = ((cozinheiro *)c2)->altura;

        if(altura_c1 == altura_c2){
            //se também as alturas forem iguais, comparar o nome
            char nome_c1[21];
            char nome_c2[21]; 
            strcpy(nome_c1, ((cozinheiro *)c1)->nome);
            strcpy(nome_c2, ((cozinheiro *)c2)->nome);

            return strcmp(nome_c1, nome_c2);
        }
        else{
            r = altura_c2 - altura_c1;
            return r;
        }
    }
    else
        return r;
}

int main(){
    int n;
    
    if(scanf("%d", &n) != 1){
        return 1;
    }

    cozinheiro pessoas[n];

    for(int i = 0; i < n; i++){
        if(scanf("%s %d %d", pessoas[i].nome, &pessoas[i].peso, &pessoas[i].altura) != 3){
            return 1;
        }
    }

    qsort(pessoas, n, sizeof(pessoas[0]), comparador);

    for(int i = 0; i < n; i++){
        printf("%s %d %d\n", pessoas[i].nome, pessoas[i].peso, pessoas[i].altura);
    }
    
    return 0;
}