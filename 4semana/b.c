#include <stdio.h>
#include <string.h>

int main(){
    int n, compLinha, encontrado;
    char linha[1000]; 

    if(scanf("%d", &n) != 1){
        return 1;
    }

    char letras[n+1];
    letras[n] = '\0';

    for(int i = 0; i < n; i++){
        if(scanf("%s", linha) != 1){
            return 1;
        }

        compLinha = strlen(linha);
        encontrado = 0;

        for(int j = 0; !encontrado && j < compLinha; j++){
            for(int k = j + 1; !encontrado && k < compLinha; k++){
                if(linha[j] == linha[k]){
                    letras[i] = linha[j];
                    encontrado = 1;
                }
            }
        }  
    }

    printf("%s\n",letras);
    return 0;
}