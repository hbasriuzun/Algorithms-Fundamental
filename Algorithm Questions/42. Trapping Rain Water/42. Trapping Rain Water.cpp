class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rmax(height.size());
        vector<int> lmax(height.size());
        lmax[0] = height[0];
        for(int i = 1; i < height.size() - 1; i++)
            lmax[i] = max(height[i], lmax[i - 1]);
        rmax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--)
            rmax[i] = max(height[i], rmax[i + 1]);
        int ans = 0;
        for (int i = 1; i < height.size() - 1; i++) 
            ans += min(lmax[i], rmax[i]) - height[i];
        return ans;
    }
};
