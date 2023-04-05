#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para retirar os espaços e ordenar os nomes alfabeticamente
void ordenarSemEspacos(char nome[]) {
    int comp = strlen(nome);
    int i, j;
    for (i = j = 0; nome[i] != '\0'; i++){
        if (nome[i] != ' ')
            nome[j++] = nome[i];
        else
            comp--;
    }
    nome[j] = '\0';

    for (i = 0; i < comp - 1; i++) {
        for (j = i + 1; j < comp; j++) {
            if (nome[i] > nome[j]) {
                char aux = nome[i];
                nome[i] = nome[j];
                nome[j] = aux;
            }
        }
    }
}

int main(){

    int n,k;
    char vilao[101];
    char candidato[101];

    if(scanf("%d",&n) != 1){
        return 1;
    }
    
    int  *resultados[n];
    int qtdsAnagramas[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d",&k) != 1){
            return 1;
        }

        qtdsAnagramas[i] = k;
        resultados[i] = (int *) malloc(k * sizeof(int));
        

        if(scanf(" %[^\n]s", vilao) != 1){
            return 1;
        }

        ordenarSemEspacos(vilao);

        int count = 0;
        for(int j = 0; j < k; j++){
            if(scanf(" %[^\n]s", candidato) != 1){
                return 1;
            }
            ordenarSemEspacos(candidato);

            if(strcmp(vilao,candidato) == 0){
                resultados[i][count++] = j+1;
            }
        }

        if(count == 0){
            resultados[i][0] = -1;
        }
        qtdsAnagramas[i] = count;
    }

    for(int i = 0; i < n; i++){
        if(resultados[i][0] == -1){
            printf("%d\n",-1);
            continue;
        }
        else{
            printf("%d",resultados[i][0]);
        }
        for(int j = 1; j < qtdsAnagramas[i]; j++){
            printf(" %d", resultados[i][j]);
        }
        putchar('\n');
        
        free(resultados[i]);
    }
     
    return 0;
}