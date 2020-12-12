#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	
	long long answer1, answer2;
	answer1 = stoi(a)*pow(10, b.size())+stoi(b);
	answer2 = stoi(c)*pow(10, d.size())+stoi(d);
	
	cout << answer1 + answer2 << endl;
}
