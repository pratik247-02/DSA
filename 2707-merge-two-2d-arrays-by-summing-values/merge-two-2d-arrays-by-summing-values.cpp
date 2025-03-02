class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> mp;
    
    for (auto &v : nums1) mp[v[0]] += v[1];  
    for (auto &v : nums2) mp[v[0]] += v[1];  

    vector<vector<int>> res;
    for (auto &p : mp) res.push_back({p.first, p.second});

    return res;
    }
};