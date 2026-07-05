class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* leftprev = &dummy;
        ListNode* curr = head;
        for(int i = 0; i < left -1;i++){
            leftprev = curr;
            curr = curr->next;
        }
        ListNode* prev = nullptr;
        for(int i = 0; i< right - left + 1; i++){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        leftprev->next->next = curr;
        leftprev->next = prev;
        return dummy.next;
    }
};