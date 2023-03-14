#include <stdio.h>
#include <string.h>

int main(){
    char linha[1000];
    int n, compLinha, nAlternadas, nVogais, nConsoantes;
    
    if(scanf("%d", &n) != 1){
        return 1;
    }
    
    int valores[n];

    for(int i = 0; i < n; i++){
        if(scanf(" %[^\n]s", linha) != 1){
            return 1;
        }

        compLinha = strlen(linha);
        nAlternadas = nConsoantes = nVogais = 0;
        
        for(int j = 0; j < compLinha; j++){
            if(linha[j] == ' '){
                if(nConsoantes < 2 && nVogais < 2)
                    nAlternadas++;
                nConsoantes = nVogais = 0;
            }
            else if(nConsoantes >= 2 || nVogais >= 2){
                continue;
            }
            else if(linha[j] == 'A' ||linha[j] == 'E' ||linha[j] == 'I' ||linha[j] == 'O' ||linha[j] == 'U' ||linha[j] == 'Y'){
                nConsoantes = 0;
                nVogais++;
            }
            else{
                nVogais = 0;
                nConsoantes++;
            }
        }

        if(nConsoantes < 2 && nVogais < 2)
            nAlternadas++;

        valores[i] = nAlternadas;
    }

    for(int z = 0; z < n; z++){
        printf("%d\n",valores[z]);
    }

    return 0;
}