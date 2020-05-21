#include <iostream>
#define ll long long
using namespace std;

bool numbers[1000001];
 
int main(void){
    ll max, min;
    int count = 0;
 
    cin >> min >> max;
 
    for (ll i=2;i*i<=max;i++){
        ll x = min / (i*i);
        if (min % (i*i) != 0) x++;
 
        while (x*(i*i) <= max){
            numbers[x*(i*i) - min] = 1;
            x++;
        }
    }
    
    for (int i=0;i<=max-min;i++) if (numbers[i] == 0) count++; 
 
    cout << count << endl;
}
