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
     int peak(MountainArray &mountainArr) {
        int low = 0; int high = mountainArr.length()-1;
        while(low<high){
            int mid = low +(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int binarysearch(int l, int r, int target, MountainArray &mountainArr){
        while(l<=r){
            int mid = l + (r -l)/2;
            if(target==mountainArr.get(mid)){
                return mid;
            }else if (target<mountainArr.get(mid)){
                r = mid -1;
            } else{
                l = mid + 1;
            }
        }
        return -1;
    }
    int revsearch(int l, int r, int target, MountainArray &mountainArr){
         while(l<=r){
            int mid = l + (r -l)/2;
            if(target==mountainArr.get(mid)){
                return mid;
            }else if (target<mountainArr.get(mid)){
                l = mid + 1;
            } else{
                r = mid -1;;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int idx = peak(mountainArr);

        int residx = binarysearch(0,idx,target,mountainArr);

        if(residx!=-1){
            return residx;
        }

        residx = revsearch(idx+1,n-1,target,mountainArr);

        return residx;

    }
};
