class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    // dp[i] := # of binary trees with arr[i] as root
    vector<long> dp(n, 1);
    unordered_map<int, int> numToIndex;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i)
      numToIndex[arr[i]] = i;

    for (int i = 0; i < n; ++i)  // arr[i] is root
      for (int j = 0; j < i; ++j)
        if (arr[i] % arr[j] == 0) {  // arr[j] is left subtree
          const int right = arr[i] / arr[j];
          if (const auto it = numToIndex.find(right); it != numToIndex.cend()) {
            dp[i] += dp[j] * dp[it->second];
            dp[i] %= kMod;
          }
        }

    return accumulate(dp.begin(), dp.end(), 0L) % kMod;
  }
};
