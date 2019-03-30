#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);ListNode* head=ans;
        int k=0;
        while(l1&&l2){
            int c=l1->val+l2->val+k;
            ListNode* cur=new ListNode(c%10);
            if(c>=10)
                k=1;
            else
                k=0;
            ans->next=cur;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        ListNode *l3=l1;
        if(l1==NULL)
            l3=l2;
        while(l3!=NULL)
        {
            int c=l3->val+k;
            ListNode* cur=new ListNode(c%10);
            if(c>=10)
                k=1;
            else
                k=0;
            ans->next=cur;
            ans=ans->next;
            l3=l3->next;
        }
        if(k)
        {
            ListNode* cur=new ListNode(1);
            ans->next=cur;
        }
        return head->next;
       }
};
int main(){
    ListNode l1(2);
    ListNode l2(4);
    ListNode l3(3);
    ListNode l4(5);
    ListNode l5(6);
    ListNode l6(4);
    l1.next=&l2;
    l2.next=&l3;
    l4.next=&l5;
    l5.next=&l6;
    Solution s;
    ListNode *l=s.addTwoNumbers(&l1,&l4);
    cout<<l->val;
    l=l->next;
    cout<<l->val;
    l=l->next;
    cout<<l->val;
}
