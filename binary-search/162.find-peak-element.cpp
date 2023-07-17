/**
 * @link https://leetcode.com/problems/find-peak-element
 */
#include <vector>

class Solution
{
public:
  int findPeakElement(std::vector<int> &nums)
  {

    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left < right)
    {
      mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid + 1])
        right = mid;
      else
        left = mid + 1;
    }

    return left;
  }
};
