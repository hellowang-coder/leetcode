/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// @lc code=start

class Solution {
public:
    /**
     * @brief 
     *  翻转链表里指定的子区间指针 
     * @param head 
     * @param left 
     * @param right 
     * @return ListNode* 
     */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ret = head;
        ListNode* last = nullptr;
        //首先找到需要调整的头部
        int idx = 1;
        for(; head != nullptr && idx < left; ++idx){
            last = head;
            head = head->next;
        }
        if (head == nullptr){
            return ret;
        }
        
        ListNode* pre = nullptr;
        ListNode* rangeBeg = nullptr;
        for(; head != nullptr && idx <= right; ++idx){
            if (nullptr == pre){
                pre = head;
                rangeBeg = head;
                head = head->next;
                continue;
            }
            //TODO: 123
    
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        if (nullptr != last){    
            last->next = pre;
        }else{//说明是从头开始进行翻转的，返回值ret需要修改为pre
            ret = pre;
        }

        //翻转区域开始的节点的next指针 指向当前退出翻转的节点
        rangeBeg->next = head;

        return ret;
    }
};
// @lc code=end