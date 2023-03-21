#include <stdio.h>

int main(){
    int n, k, primeiroGuiche, loop, proximoGuiche, tamanho;
    int guiches[100];

    if(scanf("%d", &n) != 1){
        return 1;
    }

    int guichesPassados[n][101];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &k) != 1){
            return 1;
        }


        if(scanf("%d", &primeiroGuiche) != 1){
            return 1;
        }

        for(int j = 0; j < k; j++){
            if(scanf("%d", &guiches[j]) != 1){
                return 1;
            }
        }

        guichesPassados[i][0] = primeiroGuiche;

        tamanho = loop = 0;
        while(!loop){
            proximoGuiche = guiches[guichesPassados[i][tamanho] - 1];

            if(proximoGuiche == 0)
                break;
            
            for(int w = 0; w < tamanho; w++){
                if(guichesPassados[i][w] == proximoGuiche){
                    loop = 1;
                    break;
                }
            }

            tamanho++;

            if(loop){
                guichesPassados[i][tamanho] = -1;
            }
            else{ 
                guichesPassados[i][tamanho] = proximoGuiche;
                guichesPassados[i][tamanho + 1] = -2;
            }
        }
    }

    for(int l = 0; l < n; l++){
        for(int z = 0; guichesPassados[l][z] != -2; z++){
            if(guichesPassados[l][z] == -1){
                printf("CICLO INFERNAL");
                break;
            }
            else{
                if(guichesPassados[l][z+1] == -2)
                    printf("%d", guichesPassados[l][z]);
                else
                    printf("%d ", guichesPassados[l][z]);
            }
        }
        putchar('\n');
    }
    return 0;
}