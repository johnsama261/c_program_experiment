#include <stdio.h>

int main()
{
    int classrank,failcount,gracemarks = 0;
    printf("classrank\n");
    scanf("%d",&classrank);
    printf("failcount\n");
    scanf("%d",&failcount);

    switch (classrank)
    {
        case 1:
            if (failcount<=3)
            {
                gracemarks = failcount*5;
            }
            else{
                gracemarks = 0;
            }
            break;
        
        case 2:
            if(failcount<=2)
            {
                gracemarks = failcount*4;
    
            }
            else
            {
                gracemarks = 0;
            }
            break;
        
        case 3:
            if(failcount==1)
            {
                gracemarks =5;
            }
            else{
                gracemarks =0;
            }
            break;
        default:
            printf("false\n");
            return 0;

    }
    printf("恩典分是%d\n",gracemarks);
    return 0;
}