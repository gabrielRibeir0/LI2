#include <stdio.h>
#include <string.h>

int main(){
    int n, jaLido, minPresencas, minPresencas_indice, numPessoasLidas, numPessoas;
    char c;
    char nome[21];
    char pessoas[40][21];
    int presencas[40] = {0};

    if(scanf("%d", &n) != 1){
        return 1;
    }

    numPessoas = 0;

    for(int i = 0; i < n; i++){
        numPessoasLidas = 0;
        //Leitura nomes em 1 linha (condição até ler o numPessoas max -> 40)
        while(numPessoasLidas < 40){
            //ler o nome
            if(scanf("%s", nome) != 1){
                printf("Erro a ler");
                return 1;
            }
            //Ler o caracter a seguir ao nome (espaço ou '\n')
            c = getchar();

            //Verificar se o nome lido já está na lista
            jaLido = 0;
            for(int j = 0; j < numPessoas; j++){
                //Percorrendo a lista até ao número de pessoas já registadas, comparar o nome lido com cada um dos nomes da lista
                //Se for igual, não precisamos de adicionar à lista, basta aumentar o número de presenças no respetivo índice
                if(strcmp(pessoas[j], nome) == 0){
                    presencas[j]++;
                    jaLido = 1;
                    break;
                }
            }
            //Mais uma pessoa lida nesta linha
            numPessoasLidas++;

            //Se o nome não for repetido, aumentar o número de presenças, adicionar o nome à lista de pessoas e aumentar o número de pessoas na lista
            if(!jaLido){ 
                presencas[numPessoas]++;
                strcpy(pessoas[numPessoas], nome);
                numPessoas++;
            }
            
            //Se o caracter a seguir ao nome for um '\n' quer dizer que era o último da linha, logo para de ler
            if(c == '\n') break;
        }
    }

    //Inicializar o número mínimo de presenças com o número mais alto possível, o número de dias
    minPresencas = minPresencas_indice = n;
    for(int k = 0; k < numPessoas; k++){
        //Se o num de presenças lido for menor do que o atual, é o novo num minimo de presenças e o índice dele e da pessoa é o k
        if(presencas[k] < minPresencas){
            minPresencas = presencas[k];
            minPresencas_indice = k;
        }
    }

    //Escrever o nome da pessoa com o menor número de presenças (maior número de faltas)
    printf("%s\n", pessoas[minPresencas_indice]);
    return 0;
}