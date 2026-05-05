class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0) return head;

        int st = len - k - 1;
        temp = head;

        while (st--) {
            temp = temp->next;
        }

        ListNode* newhead = temp->next;
        temp->next = NULL;

        ListNode* tail = newhead;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;

        return newhead;
    }
};