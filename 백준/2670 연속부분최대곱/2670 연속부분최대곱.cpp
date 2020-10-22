#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<double> v(n);
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	double answer = v[0];
	for(int i=1;i<n;i++){
		if(v[i] <= v[i]*v[i-1]){
			v[i] = v[i]*v[i-1];
		}
		answer = max(answer, v[i]);
	}
	printf("%.3lf",answer);
}
