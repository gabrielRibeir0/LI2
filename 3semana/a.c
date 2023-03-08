#include <stdio.h>
#include <string.h>

int main(){
    char msg[1001];
    char ordem[9];
    int tamanho_msg, tamanho_ordem, n;

    if((scanf("%s",ordem)) != 1){
        printf("Erro na leitura\n");
        return 1;
    }

    if((scanf("%s",msg)) != 1){
        printf("Erro na leitura\n");
        return 1;
    }

    tamanho_msg = strlen(msg);
    tamanho_ordem = strlen(ordem);

    for(int i = 0; i < tamanho_ordem; i++){
        n = (int)ordem[i];
        for(int j = 0; j < tamanho_msg; j += tamanho_ordem){
            if(j + n - 49 >= tamanho_msg)
                break;
            putchar(msg[j + n - 49]);
        }
    }
    putchar('\n');

    return 0;
}