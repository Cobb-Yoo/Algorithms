#include<iostream>
using  namespace std;

int init(int num){
	int i;
    for(i=num/2;i<num;i++){
        int n = i;
        int temp = i;
        
        while (temp) {
            n += temp % 10;
            temp /= 10;
        }
        
        if(num == n) break;
    }
    return i;
}

int main (){
    int n;
    cin >> n;
    int result = init(n);
    
    if(result == n)
    	cout << 0 << endl;
    else
    	cout << init(n) << endl;
}
