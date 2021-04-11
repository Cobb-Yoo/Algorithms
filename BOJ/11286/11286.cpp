#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<ll, vector<ll>, greater<ll>> P;
	priority_queue<ll> M;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		ll num;
		cin >> num;
		if(P.empty() && M.empty() && !num){
			cout << "0\n";
		}
		else if(P.empty() && !num){
			cout << M.top() << endl;
			M.pop();
		}
		else if(M.empty() && !num){
			cout << P.top() << "\n";
			P.pop();
		}
		else if(!num){
			if(P.top() + M.top() < 0){
				cout << P.top() << "\n";
				P.pop();
			}
			else{
				cout << M.top() << "\n";
				M.pop();
			}
		}
		else if(num > 0){
			P.push(num);
		}
		else if(num < 0){
			M.push(num);
		}
	}
}
