#include <iostream>
using namespace std;

int main(){
	for(int i=0;i<3;i++){
		int sh,sm,ss, eh,em,es;
		cin >> sh >> sm >> ss >> eh >> em >> es;
		
		int ah,am,as;
		
		as = es - ss;
		if(as < 0) {
			as += 60;
			em--;
			if(em < 0) {
				em += 60;
				eh--;
			}
		}
		
		am = em - sm;
		if(am < 0){
			am += 60;
			eh--;
		}
		
		ah = eh - sh;
		
		cout << ah << " " << am << " " << as << endl;
	}
}
