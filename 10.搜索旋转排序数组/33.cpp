class Solution {
public:
    int bsearch(vector<int>& nums, int left, int right, int target) {
        int mid = left + (right - left)/2;
        if (left < 0 || right > nums.size() || left > right) {
            return -1;
        }
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }

        cout<<mid<<endl;
        if (nums[left] < nums[mid]) { // 左区间有序
            cout<<nums[left]<<"---"<<nums[mid]<<endl;
            if (nums[left] < target && target < nums[mid]) {
                cout<<nums[left]<<"-"<<nums[mid]<<endl;
                return bsearch(nums, left, mid-1, target);
            } else {
                return bsearch(nums, mid+1, right, target);
            }
        } else { // 右区间
            if (nums[mid] < target && target < nums[right]) {
                return bsearch(nums, mid+1, right, target);
            } else {
                return bsearch(nums, left, mid-1, target);
            }
        }
    };

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        return bsearch(nums, 0, nums.size()-1, target);
    }
};
