#include <iostream>
using namespace std;
 
int a, b;
 
int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a%b);
}
 
int main() {
    cin >> a >> b;
    int g = a > b ? gcd(a, b) : gcd(b, a);
    cout << g << '\n' << a*b / g << endl;
}

