from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left=0
        right=len(nums)-1

        while (left <= right):
            mid = (left+right)//2

            if nums[mid] == target:
                return mid

            # left sorted array
            if nums[mid] >= nums[left]:
                if target > nums[mid]:
                    left = mid+1
                elif target < nums[left]:
                    left = mid+1
                else:
                    right = mid-1

            # right sorted array
            else:
                if target<nums[mid]:
                    right=mid-1
                elif target>nums[right]:
                    right=mid-1
                else:
                    left=mid+1

        return -1
    
list=[4,5,6,7,0,1,2]
target=0
ob=Solution()
print(ob.search(list,0))
