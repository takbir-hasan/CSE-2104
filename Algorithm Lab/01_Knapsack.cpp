#include <bits/stdc++.h>
using namespace std;

int KnapSack(int W, int wt[], int val[], int i, vector<vector<int> >& dp)
{

  if (i < 0)
    return 0;
    
  if (dp[i][W] != -1)
    return dp[i][W];

  if (wt[i] > W)
  {
    dp[i][W] = KnapSack(W, wt, val, i - 1, dp);
    return dp[i][W];
  }
  else
  {

    dp[i][W] = max(val[i] + KnapSack(W - wt[i], wt, val, i - 1, dp),KnapSack(W, wt, val, i - 1, dp));

    return dp[i][W];
  }
}

int main()  
{

  int wt[] = {2,3,4,7,6};
      int n = sizeof(wt)/sizeof(wt[0]);
  
  int p[] = {4,15,5,8,22};

  
  int cap = 15;

 vector<vector<int> > dp(n,vector<int>(cap + 1, -1));

  cout << "Maximum profit: " << KnapSack(cap, wt, p, n - 1, dp);

  return 0;
}
