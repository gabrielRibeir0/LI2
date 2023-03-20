#include <stdio.h>

int main(){
    int n, k, temp, guicheAtual, tamanhoSucc, loop;
    int guiches[100];
    int guichesPassados[99];

    if(scanf("%d", &n) != 1){
        return 1;
    }

    int succ[n][101];
    int listatamanhoSucc[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &k) != 1){
            return 1;
        }

        if(scanf("%d", &guicheAtual) != 1){
            return 1;
        }

        for(int j = 0; j < k; j++){
            if(scanf("%d", &temp) != 1){
                return 1;
            }
            guiches[j] = temp;
        }

        loop = tamanhoSucc = 0;
        while(!loop && guicheAtual != 0){
            succ[i][tamanhoSucc] = guicheAtual;
            guichesPassados[tamanhoSucc] = guicheAtual;
            tamanhoSucc++;
            guicheAtual = guiches[guicheAtual - 1];

            for(int w = 0; w < tamanhoSucc - 1; w++){
                if(guichesPassados[w] == guicheAtual){
                    loop = 1;
                    succ[i][tamanhoSucc-1] = -1;
                    break;
                }
            }
        }
        listatamanhoSucc[i] = tamanhoSucc;
       
    }

    for(int l = 0; l < n; l++){
        for(int z = 0; succ[l][z] < listatamanhoSucc[l]; z++){
            if(succ[l][z] == -1)
                printf("CICLO INFERNAL");
            else
                printf("%d ", succ[l][z]);
        }
        putchar('\n');
    }
    return 0;
}