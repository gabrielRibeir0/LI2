#include <stdio.h>

int main(){
    int n = 0, move = 0, x = 0, y = 0;
    
    if (scanf("%d",&n) == 1) n = n;

    for (int i = 0; i < n; i++){
        if (scanf("%d",&move) == 1){
            if (move % 4 == 1) y--;
            else if (move % 4 == 2) y++;
            else if (move % 4 == 3) x--;
            else x++;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}