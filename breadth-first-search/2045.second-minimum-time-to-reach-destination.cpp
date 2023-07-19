#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int secondMinimum(int n, std::vector<std::vector<int>> &edges, int time, int change) {
    std::vector<int> next[n + 1];
    for (auto edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      next[b].push_back(a);
    }

    std::vector<int> visited(n + 1, 0);
    std::vector<int> dist(n + 1, -1);
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
      auto [cur, t] = q.front();
      q.pop();

      int tt;
      int round = t / change;
      if (round % 2 == 0)
        tt = t + time;
      else
        tt = (round + 1) * change + time;

      for (int nxt: next[cur]) {
        if (visited[nxt] < 2 && dist[nxt] < tt) {
          dist[nxt] = tt;
          visited[nxt] += 1;
          q.push({nxt, tt});

          if (visited[nxt] == 2 && nxt == n)
            return tt;
        }
      }
    }
    return -1;
  }
};
