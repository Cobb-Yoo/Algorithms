#include <iostream>
using namespace std;
 
double arr[] = {1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	cout << "n e\n";
	cout << "- -----------\n";
	cout << "0 1\n";
	
	double answer=1;
	for(int i=1;i<10;i++){
		cout << i << " ";	
		
		answer += 1/arr[i];
		if (i == 1) printf("%d\n",2);
        else if (i == 2) printf("2.5\n");
        else printf("%.9f\n", answer);
    }
}
