#include <stdio.h>

int main(){
    int n, k, guicheAtual, tamanhoSucc, loop, proximoGuiche, tamanho;

    if(scanf("%d", &n) != 1){
        return 1;
    }

    for(int i = 0; i < n; i++){
        if(scanf("%d", &k) != 1){
            return 1;
        }

        int guiches[k];
        int guichesPassados[k];

        if(scanf("%d", &guicheAtual) != 1){
            return 1;
        }

        for(int j = 0; j < k; j++){
            if(scanf("%d", &guiches[j]) != 1){
                return 1;
            }
        }

        guichesPassados[0] = guicheAtual;
        tamanho = loop = 0;
        while(!loop){
            proximoGuiche = guiches[guichesPassados[tamanho] - 1];

            if(proximoGuiche == 0)
                break;
            
            tamanho++;
            
            for(int w = 0; w < tamanho; w++){
                if(guichesPassados[w] == proximoGuiche){
                    loop = 1;
                    break;
                }
            }
        }

        for(int z = 0; z < tamanho; z++){
            printf("%d ", guichesPassados[z]);
        }

        if(loop)
            printf("CICLO INFERNAL ");

        putchar('\n');
    }
    return 0;
}