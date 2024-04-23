#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> &arr) {
  if (arr.size() <= 2) return 0;

  int cnt[101] { 0 };

  for (auto val : arr) {
    cnt[val] += 1;
  }

  int ans = 0;
  for (int i = 0; i <= 100; i++) {
    ans += cnt[i] / 3;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t, n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;

    vector<int> arr(n);

    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }

    cout << cal(arr) << '\n';
  }

  return 0;
}
