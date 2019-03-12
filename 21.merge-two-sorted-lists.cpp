/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.03%)
 * Total Accepted:    522.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * newList = NULL;        
        ListNode * tmp = NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            newList = l1;
            tmp = newList;
            l1 = l1->next;
        } else {
            newList = l2;
            tmp = newList;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val){
               tmp->next = l1; 
               tmp = tmp->next;
               l1 = l1->next;
            } else {
               tmp->next = l2; 
               tmp = tmp->next;
               l2 = l2->next;
            }
        }

        if (l1 == NULL)  tmp->next = l2;
        if (l2 == NULL)  tmp->next = l1;

        return newList;
    }
};

void printList(ListNode * list) 
{
    while (list != NULL) {
        std::cout << list->val << "->" ;
        list = list->next;
    }
}

ListNode * genListByArray(int * arry, size_t size) 
{
    ListNode * head = NULL;
    ListNode * cur = NULL;

    for (int i = 0; i < size; i++){
        ListNode *tmp = new ListNode(arry[i]);
        if (head == NULL) {
            cur = tmp;
            head = cur;
        } else {
            cur->next = tmp;
            cur = cur->next;
        }
    }

    return head;
}

void delList(ListNode * list)
{
    ListNode * tmp;
    while (list != NULL) {
       tmp = list;
       list = list->next;
       tmp->next = NULL; 
       delete tmp;
    }
}

int main() 
{
    Solution sl;
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5, 6};
    ListNode * aList = genListByArray(a, sizeof(a)/sizeof(int));
    ListNode * bList = genListByArray(b, sizeof(b)/sizeof(int));
    //printList(aList);
    ListNode * cList = sl.mergeTwoLists(aList, bList);
    printList(cList);

    //delList(aList);
    //delList(bList);
    delList(cList);
    return 0;
}

