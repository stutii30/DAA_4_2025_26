#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {0, 0, 1, 2, 3};
    int c;
    int n = v.size();
    cout << "Element whos upper bound you wanna find";
    cin >> c;
    int f = 0, l = n - 1;
    int ans = n;
    while (f <= l)
    {
        int mid = (f + l) / 2;
        if (v[mid] > c)
        {
            ans = mid;
            l = mid - 1;
        }
        else if (v[mid] <= c)
        {
            f = mid + 1;
        }
    }
    cout << v[ans];
}