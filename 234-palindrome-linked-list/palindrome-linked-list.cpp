class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode*newHead = reverseLinkedList(head->next);
    ListNode* temp= head->next;
    temp->next=head;
    head->next=NULL;
    return newHead;
}

bool isPalindrome(ListNode *head)
{
        if(head==NULL||head->next==NULL){
            return true;
        }
        ListNode*fast = head;
        ListNode*slow = head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead= reverseLinkedList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            if(second->val!=first->val){
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
}
    
};