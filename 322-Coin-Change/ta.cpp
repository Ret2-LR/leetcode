#include <vector>
#include <iostream>
#include "stdio.h"
using namespace  std;
// 暴力递归
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        m_coins = coins;
        auto res = dp(amount);
        cout << "cnt="<< cnt<< endl;
        return res;
    }

    int dp(int n)
    {
        if(n==0) return 0;
        if(n<0) return -1;

        int res = 0x7fffffff, sub=-1;
        for(int coin: m_coins){
            ++cnt;
            sub = dp(n-coin);
            if(sub == -1) continue;

            if(sub+1 < res) res = sub+1;
        }
        
        if(res != 0x7fffffff)
        {
            return res;            
        }
        else
            return -1;

    }
    int cnt=0;
    vector<int> m_coins;
};

// 带备忘录的递归解法
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        m_coins = coins;
        vector<int> memo(amount+1,0);
        auto res = dp(amount, memo);
        cout << "cnt="<< cnt<< endl;
        return res;
    }

    int dp(int n, vector<int> & memo)
    {
        if(n==0) return 0;
        if(n<0) return -1;

        if(memo[n]) return memo[n];

        int res = 0x7fffffff, sub=-1;
        for(int coin: m_coins){
            ++cnt;
            sub = dp(n-coin, memo);
            if(sub == -1) continue;

            if(sub+1 < res) res = sub+1;
        }

        if(res != 0x7fffffff)
        {
            memo[n] = res;
            return memo[n];            
        }
        else
            return -1;

    }
    int cnt=0;
    vector<int> m_coins;
};

// dp 数组的迭代解法
class Solution2 {
public:

    int coinChange(vector<int>& coins, int amount) {
        int min_coin = coins[0];
        for(int i=1;i<coins.size();i++)
        {
            if(coins[i] < min_coin)
                min_coin = coins[i];
        }
        //printf("min coin:%d\n", min_coin);
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=min_coin;i<dp.size();++i)
        {
            for(int coin: coins)
            {
                ++cnt;
                if(i-coin < 0) continue;
                dp[i] = min(dp[i],dp[i-coin] + 1);
            }
        }
        cout << "cnt="<< cnt<< endl;
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
    int cnt = 0;
};

int main()
{
    vector<int> m_coins={10,35,29,94,28,61};
    Solution s;
    auto res = s.coinChange(m_coins,123);
    cout << "res=" << res << endl;

    Solution1 s1;
    res = s1.coinChange(m_coins,123);
    cout << "res1=" << res << endl;

    Solution2 s2;
    res = s2.coinChange(m_coins,123);
    cout << "res2=" << res << endl;

    return 0;
}