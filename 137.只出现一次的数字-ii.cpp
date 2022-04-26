/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //针对位运算 统计出所有数的每一bit为出现的次数。
        //统计完毕之后 把所有的不被三整除的位数拿出来 拼出的整数即为返回的数字
        int bitMap[32] = {0};

        const size_t size = nums.size();
        for(size_t idx = 0; size > idx; ++idx){
            int curNum = nums[idx];
            for(int shiftIdx = 0; shiftIdx < 32 && curNum != 0; ++shiftIdx){
                if ((curNum & (1 << shiftIdx)) != 0){
                    bitMap[shiftIdx]++; 
                    curNum &= ~(1 << shiftIdx);
                }
            }
        }

        int singleNum = 0;
        for(int shiftIdx = 0; shiftIdx < 32; ++shiftIdx){
            if (bitMap[shiftIdx] % 3 != 0){
                singleNum |= (1 << shiftIdx);
            }
        }

        //FIXME：work

        return singleNum;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    std::vector<int> vc;
    vc.push_back(2);
    vc.push_back(2);
    vc.push_back(3);
    vc.push_back(2);
    (new Solution())->singleNumber(vc);
    return 0;
}

