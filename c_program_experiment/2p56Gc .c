#include <stdio.h>

int main()
{
    float hardness,carbon,tensile;
    int a1,a2,a3,sum;

    printf("hardness carbon tensile\n");
    scanf("%f %f %f",&hardness,&carbon,&tensile);
    a1=(hardness>50);
    a2=(carbon<0.7);
    a3=(tensile>5600);
    sum = a1 + a2 + a3;
    if (sum == 3){
        printf("10");
    }
    else if (sum == 2){
        if (a1==1&&a2==1&&a3==0){
            printf("9");
        }
        else if(a1==0&&a2==1&&a3==1){
            printf("8");
        }
        else if(a1==1&&a2==0&&a3==1){
            printf("7");
        }
    }
    else if(sum == 1){
        printf("6");
    }
    else{
        printf("5");
    }

    return 0;
}