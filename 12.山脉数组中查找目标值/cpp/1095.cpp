/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {
       int size = mountainArr.length();
        int top = findTop(mountainArr, 0, size - 1);
        int index = bsearch(mountainArr, 0, top, target, less<int>());
        if (index < 0) {
            index = bsearch(mountainArr, top, size - 1, target, greater<int>());
        }
        return index;
    }
    
    int findTop(MountainArray &mountainArr, int left, int right) {
        int mid = (left + right) / 2;
        if (left == right) {
            return -1;
        }
        // 左坡
        if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
            return findTop(mountainArr, mid, right);
        } else { // 右坡
            if (mountainArr.get(mid) > mountainArr.get(mid-1)) {
                return mid;
            }
            return findTop(mountainArr, left, mid);
        }
    }

    template <typename CMP>
    int bsearch(MountainArray &m, int left, int right, int target, CMP cmp) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == m.get(mid)) {
                return mid;
            }

            if (cmp(target, m.get(mid))) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};
