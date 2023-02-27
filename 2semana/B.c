#include <stdio.h>

int main(){
    int floor = 0, maxFloor = 0, n = 0, move = 0;

    if (scanf("%d",&floor) == 1) floor = floor;
    if (scanf("%d",&maxFloor) == 1) maxFloor = maxFloor;
    if (scanf("%d",&n) == 1) n = n;
    
    for (int i = 0; i < n; i++){
        if (scanf("%d", &move) == 1){
            if (move == 1 && floor + 1 <= maxFloor) floor++;
            else if (move == -1 && floor > 0) floor--;
        }
    }

    printf("%d\n",floor);
    return 0;
}