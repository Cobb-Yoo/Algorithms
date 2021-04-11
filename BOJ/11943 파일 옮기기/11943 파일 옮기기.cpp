#include <iostream>
using namespace std;

int main(){
	int firstApple, firstOrange;
	int secondApple, secondOrange;
	
	cin >> firstApple >> firstOrange >> secondApple >> secondOrange;
	
	cout << min((firstApple+secondOrange), (firstOrange+secondApple)) << endl;
}
