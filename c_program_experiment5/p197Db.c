#include <stdio.h>

void fuyin(int a[], int b[])
{
    int i;
    for(i = 0; i < 25; i++)
        b[i] = a[i];
}

void xuanze(int arr[])
{
    int i,j,min,temp;
    for(i = 0; i < 24; i++)
    {
        min = i;
        for(j = i+1; j < 25; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void maopao(int arr[])
{
    int i,j,temp;
    for(i = 0; i < 24; i++)
    {
        for(j = 0; j < 24 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void charu(int arr[])
{
    int i,j,key;
    for(i = 1; i < 25; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void dayin(int arr[])
{
    int i;
    for(i = 0; i < 25; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int yuan[25], sz[25], mp[25], cr[25];
    int i;
    for(i = 0; i < 25; i++)
        scanf("%d",&yuan[i]);
    
    fuyin(yuan, sz);
    xuanze(sz);
    printf("xuanze paixu jie guo: ");
    dayin(sz);

    fuyin(yuan, mp);
    maopao(mp);
    printf("maopao paixu jie guo: ");
    dayin(mp);

    fuyin(yuan, cr);
    charu(cr);
    printf("charu paixu jie guo: ");
    dayin(cr);
    return 0;
}