#include <iostream>
#include <algorithm>
using namespace std;
int arr[10010], n;
 
void go(int l, int r) {
    if (l > r) return;
 
    int root = l;
    int s = l, e = r;
    while (arr[s] >= arr[root]) s++;
    while (arr[e] > arr[root]) e--;
    go(s, e);
    go(e + 1, r);
    printf("%d\n", arr[root]);
    
}
int main() {
    int x;
    while (scanf(" %d", &x) != -1) arr[n++] = x;
    go(0, n - 1);
}
