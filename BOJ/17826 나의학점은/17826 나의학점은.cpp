#include <iostream>
using namespace std;

int score[301];

int main(){
	for(int i=1;i<=50;i++) {
		int num; cin >> num;
		score[num] = i;
	}
	
	int hong; cin >> hong;
	
	if(score[hong] <= 5) cout << "A+\n";
	else if(score[hong] <= 15) cout << "A0\n";
	else if(score[hong] <= 30) cout << "B+\n";
	else if(score[hong] <= 35) cout << "B0\n";
	else if(score[hong] <= 45) cout << "C+\n";
	else if(score[hong] <= 48) cout << "C0\n";
	else cout << "F\n";
}
