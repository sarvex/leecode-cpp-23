/**
 * @link https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/
 */
#include <algorithm>
#include <vector>

class Solution
{
  std::vector<long long> result;

public:
  int maxCount(std::vector<int> &banned, int n, long long maxSum)
  {
    sort(banned.begin(), banned.end());

    result.resize(banned.size());
    for (int i = 0; i < banned.size(); i++)
      result[i] = (i == 0 ? 0 : result[i - 1]) + banned[i];

    int left = 0, right = n;
    while (left < right)
    {
      int mid = right - (right - left) / 2;
      if (More(mid, banned, n, maxSum))
        right = mid - 1;
      else
        left = mid;
    }
    int m = left;
    int t = upper_bound(banned.begin(), banned.end(), m) - banned.begin();
    return m - t;
  }

  bool More(long long m, std::vector<int> &banned, int n, long long maxSum)
  {
    int t = upper_bound(banned.begin(), banned.end(), m) - banned.begin();
    long long sum = (1 + m) * m / 2 - (t == 0 ? 0 : result[t - 1]);
    return sum > maxSum;
  }
};
