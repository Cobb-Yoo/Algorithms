#include <iostream>
using namespace std;

int w, h, f, c, x1, y1, x2, y2;
long long answer;

int main(){
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2; 
	
	answer = w * h;
	
	int firststep;
	int secondstep = c+1;
	
	for(int i=x1;i<x2;i++){
		for(int j=y1;j<y2;j++){
			if(i < f) firststep = 2;
			else firststep = 1;
			
			cout << firststep << " " << secondstep << endl;
			answer -= firststep*secondstep;
		}
	}
	
	cout << answer << endl;
	
	// 숫자가 너무 커서 빼기 연산을 string으로 하는 것이 좋을듯 싶다 미래의 나야
	// num is too long... calculate to  "string" 
}
