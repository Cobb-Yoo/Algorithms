#include <iostream>
using namespace std;

int birth[3];
int today[3];

int main(){
	cin >> birth[0] >> birth[1] >> birth[2];
	cin >> today[0] >> today[1] >> today[2];
	
	//만 : 생일을 기준 
	//세 : 생년, 태어난 날 1세, 연도가 바뀌때마다++ 
	//연 : 태어난 년도는 0세 
	
	
	int first = 0;
	int second;
	int third;
	
	if(birth[0] < today[0]){
		if(birth[1] < today[1]) first = today[0] - birth[0];
		else if(birth[1] == today[1] && birth[2] <= today[2]) first = today[0] - birth[0];
		else first = today[0] - birth[0] - 1;
	}
		
	
	second = today[0]-birth[0]+1;
	third = second - 1;
	
	cout << first << endl;
	cout << second << endl;
	cout << third << endl;
}
