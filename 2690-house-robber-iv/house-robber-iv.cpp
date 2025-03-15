class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
         int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canRob(const vector<int>& nums, int k, int capability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                ++count;
                i++; // Skip the next house to ensure non-adjacency
            }
        }
        return count >= k;
    }
};