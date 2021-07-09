#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[M+1][2];
    for(int i=1; i<=M; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        if(arr[i][0]!=i)
        {
            printf("ID harus urut\n");
            return 0;
        }
    }

    int sum, id, total=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &sum, &id);
        if( id<1 || id>M)
        {
            printf("Maaf barang tidak tersedia\n");
        }
        else
        {
            total+=(sum*arr[id][1]);
        }
    }
    printf("%d\n", total);
    return 0;
}