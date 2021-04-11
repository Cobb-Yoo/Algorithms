#include <iostream>
using namespace std;

int main(){
	int answer = 0;
	 
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			char tmp;
			cin >> tmp;
			
			if(i%2==0 && j%2==0 && tmp == 'F') answer++;
			else if(i%2==1 && j%2==1 && tmp == 'F') answer++;
		}
	}
	
	cout << answer << endl;
}
