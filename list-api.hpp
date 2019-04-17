#pragma once

#include <iostream>

namespace LeetCodeSL {
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// push_back

// pop

// insert

// delete
void deleteList(ListNode * &head)
{
    if (head == nullptr)
        return ;
    
    ListNode *next = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = nullptr;
        delete head;
        head = next;
    }
}

//empty
bool empty(ListNode * head) {
    return (head==nullptr ? true:false);
}

// print list
void printList(ListNode * head)
{
    if (head == nullptr) {
        std::cout << "list is empty" << std::endl;
        return;
    }

    ListNode * cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << "->";
        cur = cur->next;
    }
    std::cout << std::endl;
}

ListNode * createListByArray(int * array, size_t size)
{
    bool bFirst = true;
    ListNode * head = nullptr;
    ListNode * cur  = nullptr;
    for (int i = 0; i < size; i++)
    {
        ListNode * newNode = new ListNode(array[i]);
        if (bFirst) {
            cur = newNode;
            head = cur;
            bFirst = false;
        } else {
            cur->next = newNode;
            cur = newNode;
        }
    }
    return head;
}

} // namespace LeetCodeSL