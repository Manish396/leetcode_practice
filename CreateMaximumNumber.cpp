class Solution {
public:
    vector<int> merge(vector<int> nums1, vector<int> nums2){
      vector<int> ret;
      int i = 0, j = 0;
      int n = nums1.size(), m = nums2.size();
      while (i < n || j < m) {
         if (greater(nums1, nums2, i, j)) {
            ret.push_back(nums1[i]);
            i++;
         }
         else {
            ret.push_back(nums2[j]);
            j++;
         }
      }
      return ret;
    }
    vector<int> modify(vector<int>& v, int k){
      stack<int> st;
      vector<int> ret;
      for (int i = 0; i < v.size(); i++) {
         int x = v[i];
         while (!st.empty() && st.top() < x && st.size() + (v.size() - i) - 1 >= k) {
            st.pop();
         }
         if (st.size() < k)
            st.push(x);
         }
         while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
         }
         reverse(ret.begin(), ret.end());
         return ret;
    }
    bool greater(vector<int>& a, vector<int>& b, int i, int j)
    {
         while (i < a.size() && j < b.size() && a[i] == b[j])
            i++, j++;
         return j == b.size() || (i < a.size() && a[i] > b[j]);
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
         vector<int> ret;
         int n = nums1.size();
         int m = nums2.size();
         for (int i = 0; i <= k; i++) {
            if (i <= n && (k - i) <= m) {
               vector<int> candidate = merge(modify(nums1, i), modify(nums2, k - i));
               if (greater(candidate, ret, 0, 0)) {
                  ret = candidate;
               }
            }
         }
         return ret;
    }
};
