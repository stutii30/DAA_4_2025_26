#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
typedef long long ll;
const ll base = 31;
const ll mod = 1e9 + 9;
string normalize(string s)
{
    string res = "";
    for (char c : s)
    {
        if (isalpha(c))
        {
            res += tolower(c);
        }
        else if (c == ' ')
        {
            res += c;
        }
    }
    return res;
}
ll computeHash(const string &s, int start, int len)
{
    ll hash = 0;
    ll power = 1;
    for (int i = 0; i < len; i++)
    {
        hash = (hash + (ll)s[start + i] * power) % mod;
        power = (power * base) % mod;
    }
    return hash;
}
ll rollHash(ll oldHash, char oldChar, char newChar, ll power)
{
    oldHash = (oldHash - (ll)oldChar + mod) % mod;
    oldHash = (oldHash * base) % mod;
    oldHash = (oldHash + (ll)newChar * power) % mod;
    return oldHash;
}
int main()
{
    string text1, text2;
    cout << "Enter first text:\n";
    getline(cin, text1);
    cout << "Enter second text:\n";
    getline(cin, text2);
    text1 = normalize(text1);
    text2 = normalize(text2);
    int k = 3;
    unordered_map<ll, vector<int>> hashMap;
    ll power = 1;
    for (int i = 0; i < k - 1; i++)
    {
        power = (power * base) % mod;
    }
    if (text1.length() >= k)
    {
        ll hash = computeHash(text1, 0, k);
        hashMap[hash].push_back(0);
        for (int i = 1; i <= text1.length() - k; i++)
        {
            hash = rollHash(hash, text1[i - 1], text1[i + k - 1], power);
            hashMap[hash].push_back(i);
        }
    }
    cout << "\nMatching substrings:\n";
    bool found = false;
    if (text2.length() >= k)
    {
        ll hash = computeHash(text2, 0, k);
        if (hashMap.find(hash) != hashMap.end())
        {
            for (int idx : hashMap[hash])
            {
                cout << text2.substr(0, k)
                     << " found at index " << idx << " in Text1\n";
                found = true;
            }
        }
        for (int i = 1; i <= text2.length() - k; i++)
        {
            hash = rollHash(hash, text2[i - 1], text2[i + k - 1], power);
            if (hashMap.find(hash) != hashMap.end())
            {
                for (int idx : hashMap[hash])
                {
                    cout << text2.substr(i, k)
                         << " found at index " << idx << " in Text1\n";
                    found = true;
                }
            }
        }
    }
    if (!found)
    {
        cout << "No matching substrings found.\n";
    }
    return 0;
}