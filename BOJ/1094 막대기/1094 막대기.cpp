#include <cstdio> 
int main(){
	short x;
	scanf("%d",&x);
	
	short a = 0;
	
	while(x){
		if(x & 1) a++;
		x >>= 1;
	}
	
	printf("%d",a);
}
