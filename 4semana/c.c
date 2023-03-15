#include <stdio.h>
#include <string.h>

int main(){
    int n, x, j, compLinha, diff;
    char linha[1000];

    if(scanf("%d",&n) != 1){
        return 1;
    }

    int posicoes[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &x) != 1){
            return 0;
        }

        if(scanf("%s", linha) != 1){
            return 1;
        }

        compLinha = strlen(linha);
        diff = 1;

        for(j = 0; j < compLinha; j++){
            for(int k = j + 1; k < j + x; k++){
                if(linha[k] == linha[k-1]){
                    diff = 0;
                    break;
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