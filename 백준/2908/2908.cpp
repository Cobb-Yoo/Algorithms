#include <stdio.h>

void swap(int *n){
    int tmp;
    
    tmp = *n / 100;
    tmp += ((*n / 10) % 10) * 10;
    tmp += (*n % 10) * 100;
    
    *n = tmp;
}

main(){
    int a,b;
    
    scanf("%d %d",&a, &b);
    
    swap(&a);
    swap(&b);
    
    if(a > b)
        printf("%d\n",a);
    else
        printf("%d\n",b);
}
