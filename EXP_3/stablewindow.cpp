#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> attendance(n);
    for (int i = 0; i < n; i++)
    {
        cin >> attendance[i];
    }
    unordered_map<int, int> mp;
    int sum = 0, mx = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (attendance[i] == 'P' || attendance[i] == 'p')
            sum++;
        else if (attendance[i] == 'A' || attendance[i] == 'a')
            sum--;
        if (mp.find(sum) != mp.end())
        {
            mx = max(mx, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    cout << mx << endl;
    return 0;
}
