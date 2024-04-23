#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> construct(int n, int k) {
  vector<int> ans(n);
  if (n <= 0) return ans;
  if (n == 1) {
    ans[0] = k;
    return ans;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t, n, k;
  cin >> t;

  while (t--) {
    cin >> n >> k;

    vector<int> ans = construct(n, k);

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i==ans.size()];
    }
  }

  return 0;
}
