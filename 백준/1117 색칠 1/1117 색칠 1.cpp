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
	
	// ���ڰ� �ʹ� Ŀ�� ���� ������ string���� �ϴ� ���� ������ �ʹ� �̷��� ����
	// num is too long... calculate to  "string" 
}
