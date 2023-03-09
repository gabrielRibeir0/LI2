#include <stdio.h>
//USAR ARRAYS PORQUE EU LI MAL O ENUNCIADO PRONTO É ISSO
int main(){
    int n, k, visivel,contador = 0;

    if(scanf("%d", &n) != 1){
        printf("Erro na leitura");
        return 1;
    }

    int valores[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &k) != 1){
            printf("Erro na leitura");
            return 1;
        }

        int alturas[k];

        for(int j = 0; j < k; j++){
            if(scanf(" %d", &alturas[j]) != 1){
                printf("Erro na leitura");
                return 1;
            }
        }

        for(int j = 0; j < k; j++){
            visivel = 1;

            for(int v  = 0; v < j; v++){
                if(alturas[j] <= alturas[v]){
                    visivel = 0;
                    break;
                }
            }
            
            if(visivel == 1)
                contador++;
        }
        
        valores[i] = contador;
        contador = 0;
    }

    for(int i = 0; i < n; i++){
        printf("%d\n",valores[i]);
    }
    return 0;
}