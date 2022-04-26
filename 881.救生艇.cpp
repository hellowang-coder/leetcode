// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem881.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>    //rand()
#include <time.h>    //time()

using namespace std;
// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end(), std::less<int>());
        int l = 0, r = people.size() - 1;
        int cnt = 0;
        while(l < r){
            if(people[l] + people[r] <= limit){
                ++l;
                --r;
            }else{
                --r;
            }
            ++cnt;
        }
        if(l == r){
            ++cnt;
        }

        return cnt;
    }
};
// @lc code=end

