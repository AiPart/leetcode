class Solution {
public:

    int cnt = 0;
    int merged[50001];
    void merge_sort(int left, int right, vector<int>& A) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        //int mid = left + (right - left) / 2;
        merge_sort(left, mid, A);
        merge_sort(mid+1, right, A);

        // 这是一处优化，也可以去掉
        if (A[mid] <= A[mid+1]) {
            return;
        }

        int pl = left, pr = mid+1, pm = 0; 

        while (pl <= mid && pr <= right) {
            if (A[pl] <= A[pr]) {
                merged[pm++] = A[pl++];
            } else {
                merged[pm++] = A[pr++];
                cnt += mid - pl + 1; // 去掉这句就是普通的归并排序
            }
        }
        while (pl <= mid) {
            merged[pm++] = A[pl++];
        }
        while (pr <=right) {
            merged[pm++] = A[pr++];
        };
        for (int i = 0; i < pm; i++) {
            // 给原数组相应的部分排好序
            A[i + left] = merged[i];
        }
    }
    int reversePairs(vector<int>& nums) {
        merge_sort(0, nums.size() -1, nums);
        return cnt;
    }
};
