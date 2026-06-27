#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("二进制结果：");
    for(int i=31;i>=0;i--) printf("%d",(n>>i)&1);
    return 0;
}

//移位的极意,希望有一天我的代码也有后人瞻仰，哈哈