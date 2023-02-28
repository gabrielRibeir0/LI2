#include <stdio.h>

int main(){ 
    int n, vitoriasInzel = 0, vitoriasCMD = 0, empates = 0;
    char jogadaInzel, jogadaCMD;

    if (scanf("%d",&n) == 1){}

    for (int i = 0; i < n; i++){
        if (scanf(" %c", &jogadaInzel) == 1){}
        if (scanf(" %c", &jogadaCMD) == 1){}

        if ((jogadaInzel == '@' && jogadaCMD == '+') || (jogadaInzel == '|' && jogadaCMD == '*') || (jogadaInzel == 'X' && jogadaCMD == '-')){
            vitoriasInzel++;
        }
        else if ((jogadaInzel == 'X' && jogadaCMD == '*') || (jogadaInzel == '@' && jogadaCMD == '-') || (jogadaInzel == '|' && jogadaCMD == '+')){
            vitoriasCMD++;
        }
        else{
            empates++;
        }
    }

    printf("%d %d %d\n", vitoriasInzel, vitoriasCMD, empates);
    return 0;
}