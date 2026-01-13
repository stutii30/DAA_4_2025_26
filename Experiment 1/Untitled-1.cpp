#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
void complexRec(int n)
{
    if (n <= 2)
    {
        return;
    }
    // recurrence relation-3T(n/2)+nlogn+n
    // time complexity=O(nlog3base2)
    int p = n;
    int c = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }
    c = c + n;
    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
    }
    if (n % 3 == 0)
    {
        reverse(small.begin(), small.end());
    }
    else
    {
        reverse(small.begin(), small.end());
    }
    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);
    c = c + n;
    cout << c << endl;
}
int main()
{
    int n;
    cin >> n;
    auto start = high_resolution_clock::now();
    complexRec(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count();
    return 0;
}