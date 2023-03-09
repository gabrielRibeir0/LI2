#include <stdio.h>
#include <string.h>

int main(){
  int n, num_comandos, pos = 5;
  char comandos[21];

  //Ler o número de linhas
  if(scanf("%d", &n) != 1){
    printf("Erro na leitura");
    return 1;
  }
  
  int codigo[n];

  //Ciclo para ler e processar cada linha de comandos
  for(int i = 0; i < n; i++){
    if(scanf("%s", comandos) != 1){
      printf("Erro na leitura");
      return 1;
    }

    num_comandos = strlen(comandos);
    
    //Processamento de comando a comando atualizando a posição
    for(int j = 0; j < num_comandos; j++){
      if(comandos[j] == 'C'){
        if(pos < 7)
          pos += 3;
      }
      else if(comandos[j] == 'B'){
        if(pos > 3)
          pos -= 3;
      }
      else if(comandos[j] == 'D'){
        if(pos % 3 != 0)
          pos++;
      }
      else if(comandos[j] == 'E'){
        if(pos % 3 != 1)
          pos--;
      }
    }
    codigo[i] = pos;      //Guardar o código dígito a dígito num array
  }

  //Escrever o código no final
  for(int i = 0; i < n; i++){
    printf("%d", codigo[i]);
  }
  putchar('\n');

  return 0;
}