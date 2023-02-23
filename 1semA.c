#include <stdio.h>

int main(){
    int linha, max = 1;
    for (int i = 1;i <= 5; i++){
        int qtd;
        if (scanf("%d", &qtd) == 1){
            if (qtd > max){
                max = qtd;
                linha = i;
            }
        }
        else{
            printf("Erro a ler o número\n");
        }
    }
    printf("%d\n",linha);
    return 0;
}