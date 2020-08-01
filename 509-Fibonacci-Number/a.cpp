#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   int fib1(int N) {
      if(N<1) return 0;
      vector<int> memo(N+1,0);
      return helpler(memo, N);
   }

   int helpler(vector<int> &memo, int n)
   {
      if(n==0) return 0;
      if(n==1) return 1;

      if(memo[n] != 0) return memo[n];
      memo[n] = helpler(memo,n-1) + helpler(memo,n-2);
      return memo[n];
   }

   int fib2(int N) {
      if(N<1) return N;
      int prev = 1, curr = 1;

      for(int i=3;i<=N;++i)
      {
         int sum = prev + curr;
         prev = curr;
         curr = sum;
      }

      return curr;
   }
};

int main()
{
   Solution s;
   cout << s.fib1(20) << " " << s.fib2(20) << endl;

   return 0;
}
