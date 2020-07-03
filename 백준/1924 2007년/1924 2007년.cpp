#include <iostream> 
#include <string>
using namespace std;

int marr[] = {31,29,31,30,31,30,31,31,30,31,30,31};
string darr[] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(){
	int x,y;
	cin >> x >> y;
	
	int cal = 0;
	
	for(int i=0;i<x-1;i++) cal += marr[i];
	cout << "cal : " << cal << endl;
	cal += y;
	cout << "cal : " << cal << endl;
	cout << darr[cal%7] << endl;
}
