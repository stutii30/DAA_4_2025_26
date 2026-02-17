class Solution
{
public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // code here
        sort(stalls.begin(), stalls.end());
        int f = 1;
        int n = stalls.size();
        int ans = 0;
        int l = stalls[n - 1] - stalls[0];
        while (f <= l)
        {
            int mid = (f + l) / 2;
            if (ispos(stalls, mid, k))
            {
                ans = mid;
                f = mid + 1;
            }
            else
                l = mid - 1;
        }
        return ans;
    }
    bool ispos(vector<int> stalls, int mid, int k)
    {
        int count = 1;
        int pos = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - pos >= mid)
            {
                count++;
                pos = stalls[i];
            }
        }
        return count >= k;
    }
};