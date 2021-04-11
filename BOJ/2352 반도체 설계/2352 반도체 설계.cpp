#include <iostream>
#include <vector>
 
using namespace std;
 
#define Max 40001
 
int n;
vector<int> v;
 
int main()
{
    cin.tie(0);
    cin >> n;
    int tmp;
 
    for (int i = 0; i < n; i++) {
    	
        cin >> tmp;
        int idx = lower_bound(v.begin(), v.end(), tmp) - v.begin(); 		
 		
        if (idx == v.size()) v.push_back(tmp);
        else v[idx] = tmp;
    }
 
    cout << v.size() << endl;
}

