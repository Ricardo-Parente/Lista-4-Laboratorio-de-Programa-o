#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 3
#define M 3

int main(){
    unsigned char v[N][M],c[N][M],rf = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            v[i][j] = rand() % 256;
            printf("%hhu\t",v[i][j]);
        }
        printf("\n");
    }

    for(int k = 0; k < N; k++)
    {
        for(int l = 0; l < M; l++)
        {
            if (v[1][1] >= v[k][l])
            {
                c[k][l] = 1;
            }
            else{
                c[k][l] = 0;
            }
        }    
    }
    c[1][1] = '\0';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%hhu\t",c[i][j]);
        }
        printf("\n");
    }
    
    int potencia = 0;
    
    int indice[][2] = {
        {0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2},
        {2, 1}, {2, 0}, {1, 0}
    };
    for(int i = 0; i < 8; i++){
        int x = indice[i][0];
        int y = indice[i][1];
        if(c[x][y] == 1){
            rf += pow(2,potencia);
        }
        potencia++;
    }
    printf("Resultado final:%hhu",rf);
    return 0;
}