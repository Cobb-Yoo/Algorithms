#include <stdio.h>
#include <string.h>

main(){
    char line[1000001];
    int count=0,i;
    int len;
    
    gets(line);
    
    len = strlen(line);
    
    for(i=0;i<len;i++){
        if(line[i] == ' ')
            count++;
    }
    
    if(line[0] == ' ') count--;
    if(line[len-1] != ' ') count++;
    
    printf("%d\n",count);
}
