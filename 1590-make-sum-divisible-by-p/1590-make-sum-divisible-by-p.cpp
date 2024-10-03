class Solution
{
    public:
        int minSubarray(vector<int> &nums, int p)
        {

            unordered_map < long long, long long > m;
            long long l = INT_MAX;
            long long sum = 0;
            m[0] = -1;
            unsigned long long x = 0;
            for (auto i: nums)
                x += i;
            x = x % p;
            if (x == 0)
                return 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                long long k = sum - x;
                if (m.find(k % p) != m.end())
                    l = min(l, i - m[k % p]);
                m[sum % p] = i;
            }
            if (l == INT_MAX || l == nums.size())
                return -1;
            return l;
        }
};