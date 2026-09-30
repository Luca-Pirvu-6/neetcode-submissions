class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        for (int num : nums) {
            s[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : s) {
            buckets[count].push_back(num);
        }
        vector<int> result;
        for (int freq = buckets.size() - 1; freq >= 0 && result.size() < k; --freq) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    };

};
