#include <stdio.h>
int main(){
    int a, n, agente, chegada, partida, contadorAgentes, repetido;
    if(scanf("%d", &a) != 1){
        return 1;
    }
    
    int horas[24][a+1];

    for(int h = 0; h < 24; h++)
        horas[h][0] = 0;

    if(scanf("%d", &n) != 1){
        return 1;
    }

    for(int i = 0; i < n; i++){
        if(scanf("%d %d %d", &agente, &chegada, &partida) != 3){
            return 1;
        }

        for(int j = chegada; j <= partida; j++){
            contadorAgentes = horas[j][0];
            if(contadorAgentes == 0){           
                horas[j][1] = agente;
                horas[j][0]++;
            }
            else{
                repetido = 0;
                for(int w = 1; !repetido && w  <= contadorAgentes; w++){
                    if(horas[j][w] == agente)
                        repetido = 1;
                }

                if(repetido)
                    continue;
                
                else{
                    for(int k = contadorAgentes; k >= 0; k--){
                        if(k == 0){
                            horas[j][k+1] = agente;
                        }
                        else if(horas[j][k] > agente)
                            horas[j][k+1] = horas[j][k];
                        else{
                            horas[j][k+1] = agente;
                            break;
                        }
                    }
                    horas[j][0]++;
                }
            }
        }
    }

    for(int l = 0; l < 24; l++){
        if(horas[l][0] > 1){
            printf("%d ", l);
            for(int z = 1; z < horas[l][0]; z++){
                printf("%d ", horas[l][z]);
            }
            printf("%d", horas[l][horas[l][0]]);
            putchar('\n');
        }
    }
    return 0;
}