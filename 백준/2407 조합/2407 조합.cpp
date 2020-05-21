#include <iostream>
using namespace std;
const long long int maximum = 1e17;
 
typedef struct my{ 
  long long int high = 0;  
  long long int low = 0;
}my;
 
my operator+(my a, my b) {
  my c;
  c.high = a.high + b.high;
 
  if (a.low + b.low > maximum) {
    c.low = a.low + b.low - maximum;
    c.high++;
  }
  else {
    c.low = a.low + b.low;
  }
  return c;
}
 
my dp[101][101];
 
my rec(int n, int k) {
  if (dp[n][k].low != 0 || dp[n][k].high != 0) return dp[n][k];
  else if (n <= 0) return dp[n][k];
  else if (k == 0 || n == k) {
    dp[n][k].low = 1;
    return dp[n][k];
  }
  return dp[n][k] = rec(n - 1, k - 1) + rec(n - 1, k);
}
 
int main() {
  int n, m;
  my temp;
  cin >> n >> m; 
  if (n - m < m) m = n - m;
  
  temp = rec(n, m);
  if (temp.high != 0) cout << temp.high;
  cout << temp.low;
}
