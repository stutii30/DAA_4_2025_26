class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        // code here
        vector<int> ans;
        if (k == 1)
        {
            return arr;
        }
        int n = arr.size();
        for (int i = 0; i <= n - k; i++)
        {
            int mx = arr[i];
            for (int j = i; j < i + k; j++)
            {
                if (arr[j] > mx)
                {
                    mx = arr[j];
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};