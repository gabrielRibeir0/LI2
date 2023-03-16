#include <stdio.h>
#include <string.h>

int main(){
    int n, x, compLinha, diff = 1;
    char linha[1000];

    if(scanf("%d",&n) != 1){
        return 1;
    }

    int posicoes[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &x) != 1){
            return 1;
        }

        if(scanf("%s", linha) != 1){
            return 1;
        }

        compLinha = strlen(linha);

        for(int j = 0; j <= compLinha - x; j++){
            diff = 1;
            for(int k = j; diff && k < j + x - 1; k++){
                for(int l = k + 1; diff && l < j + x; l++){
                    if(linha[k] == linha[l])
                        diff = 0;
                }
            }
            if(diff){
                posicoes[i] = j;
                break;
            }
        }
        
        if(!diff)
            posicoes[i] = -1;
    }

    for(int w = 0; w < n; w++)
        printf("%d\n", posicoes[w]);
    return 0;
}