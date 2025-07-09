// https://codeforces.com/contest/1042/problem/B

#include<bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  int dp[n + 1][8];
  memset (dp, 63, sizeof (dp) );
  dp[0][0] = 0;
  for (int i = 0 ; i < n ; i++) {
    int c; string s;
    cin >> c >> s;
    int msk = 0;
    for (int j = 0 ; j < s.size() ; j++)
      msk |= (1 << (s[j] - 'A') );
    for (int j = 0 ; j <= 7 ; j++) {
      dp[i + 1][j | msk] = min (dp[i + 1][j | msk], dp[i][j] + c);
      dp[i + 1][j] = min (dp[i + 1][j], dp[i][j]);
    }
  }
  if (dp[n][7] == 1061109567)
    dp[n][7] = -1;
  cout << dp[n][7];
}

int main() {
  ios_base::sync_with_stdio (false);
  cin.tie (0);
  int ts = 1;
  while (ts--) {
    Solve();
    cout << '\n';
  }
  return 0;
}
