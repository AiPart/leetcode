class Solution {
public:

    int cnt = 0;
    int merged[50001];
    void merge_sort(int l, int r, vector<int>& A) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) / 2;
        merge_sort(l, mid, A);
        merge_sort(mid+1, r, A);

        int pl = l, pr = mid+1, pm = 0; 

        while (pl <= mid && pr <= r) {
            if (A[pl] <= A[pr]) {
                merged[pm++] = A[pl++];
            } else {
                merged[pm++] = A[pr++];
                cnt += mid - pl + 1;
            }
        }
        while (pl <= mid) {
            merged[pm++] = A[pl++];
        }
        while (pr <=r) {
            merged[pm++] = A[pr++];
        };
        for (int i = 0; i < pm; i++) {
            A[i + l] = merged[i]; 
        }
    }
    int reversePairs(vector<int>& nums) {
        merge_sort(0, nums.size() -1, nums);
        return cnt;
    }
};
