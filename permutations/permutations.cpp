#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> vec(nums.size(), -1);
      permute(nums, vec, 0, res);

      return res;
    }

    void permute(vector<int>& nums, vector<int>& vec, int c, vector<vector<int>>& res) {
      int size = (int) nums.size();
      if( c == size ) {
        res.push_back( vector<int>(size) );
        for(int n = 0; n < size; n++) {
          res.back()[vec[n]] = nums[n];
        }
      } else {
        for( int i = 0; i < size; i++ ) {
          if( vec[i] == -1 ) {
            vec[i] = c;
            permute(nums, vec, c+1, res);
            vec[i] = -1;
          }
        }
      }
    }

    vector<vector<int>> permute_swap(vector<int>& nums) {
      vector<vector<int>> res;
      permute_swap(nums, res, 0);
      return res;
    }

    void permute_swap(vector<int>& nums,vector<vector<int>> &res, int n)
    {
      if(n == (int)nums.size()-1)
        res.push_back(nums);
      else {
        for(unsigned i = n;i < nums.size(); ++i) {
          swap(nums[i], nums[n]);
          permute_swap(nums, res, n+1);
          swap(nums[i], nums[n]);
        }
      }
    }
};

int main() {
  Solution s;
  vector<int> nums = {11,22,33,44};

  vector<vector<int>> res = s.permute(nums);
  for( auto & vec : res ) {
    for( auto num : vec ) {
      cout<<num<<' ';
    }
    cout<<endl;
  }

  return 0;
}
