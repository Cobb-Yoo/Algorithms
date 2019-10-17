#include <iostream>
using namespace std;

int main(){
    int n;
    int tmp;
    int cycle=0;
    
    cin >> n;
    tmp = n;
    
    while(n != tmp || cycle == 0){
        tmp = (tmp%10)*10 + (tmp/10+tmp%10)%10;
        cycle++;
    }
	
    cout << cycle << '\n';

}
