/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.71%)
 * Total Accepted:    791.5K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* #include <iostream>
#include "list-api.hpp"
using namespace std;
using namespace LeetCodeSL; */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *cur = &head;
        ListNode * tmp = NULL;
        bool bCarry = false;
     
        while (l1 != NULL && l2 != NULL) {
          tmp = new ListNode(l1->val + l2->val + (bCarry ? 1 : 0));
          if (tmp->val >= 10) {
            bCarry = true;
            tmp->val -= 10;
          } else {
            bCarry = false;
          }
          l1 = l1->next;
          l2 = l2->next;
          cur->next = tmp;
          cur = tmp;
        }

        while (l1 != NULL) {
            tmp = new ListNode(l1->val + (bCarry ? 1:0));
            if (tmp->val >= 10) {
              bCarry = true;
              tmp->val -= 10;
            } else {
              bCarry = false;
            }

            l1 = l1->next;
            cur->next = tmp;
            cur = tmp;
        }

        while (l2 != NULL) {
            tmp = new ListNode(l2->val + (bCarry ? 1:0));
            if (tmp->val >= 10) {
              bCarry = true;
              tmp->val -= 10;
            } else {
              bCarry = false;
            }

            l2 = l2->next;
            cur->next = tmp;
            cur = tmp;
        }

        if (bCarry) {
          cur->next = new ListNode(1);
        }

        return head.next; 
    }
};
/* 
int main()
{
    Solution sl;
    int array1[] = {4, 5, 6};
    int array2[] = {7, 8, 9, 9, 9};
    ListNode * list1 = createListByArray(array1, sizeof(array1)/sizeof(int));
    printList(list1);
  
    ListNode * list2 = createListByArray(array2, sizeof(array2)/sizeof(int));
    printList(list2);

    ListNode * list3 = sl.addTwoNumbers(list1, list2);
    printList(list3);

    deleteList(list1);
    deleteList(list2);
    deleteList(list3);
    return 0;
} */

