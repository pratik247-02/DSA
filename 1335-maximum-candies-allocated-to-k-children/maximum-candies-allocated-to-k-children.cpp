class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = std::accumulate(candies.begin(), candies.end(), 0LL);
        if (totalCandies < k) return 0;

        int left = 1, right = *std::max_element(candies.begin(), candies.end());
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (canDistribute(candies, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
        }

private:
    bool canDistribute(const std::vector<int>& candies, long long k, int candiesPerChild) {
        long long count = 0;
        for (int pile : candies) {
            count += pile / candiesPerChild;
            if (count >= k) return true;
        }
        return count >= k;
    }
};