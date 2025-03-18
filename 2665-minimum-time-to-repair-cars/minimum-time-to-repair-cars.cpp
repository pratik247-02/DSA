class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canRepairAll(ranks, cars, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    bool canRepairAll(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank);
            if (totalCars >= cars) return true;
        }
        return false;
    }
};