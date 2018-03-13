//clang 3.8.0
#define NULL 0
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
#include <iostream>
using namespace std;

    ListNode* isLoop(ListNode* pHead){
        ListNode* Node1 = pHead->next;
        ListNode* Node2 = pHead;
        while( (Node1->next!=NULL) && (Node1!=NULL) ){
            cout << Node1->val << " " << Node2->val << endl;
            if(Node1 == Node2) break;
            Node1 = Node1->next->next;
            Node2 = Node2->next;
        }
        if(Node1->next == NULL) return NULL;
        if(Node1 == NULL) return NULL;
        cout << Node1->val << endl;
        return Node1;
    }

 ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        ListNode* nodeInLoop = isLoop(pHead);
        if(nodeInLoop == NULL)
            return NULL;
        //has loop
        ListNode* node = nodeInLoop;
        //get the number of nodes in loop
        int number = 1;
        while(node->next != nodeInLoop){
            number++;
            node = node->next;
        }
        //Node1先走number步
        ListNode* Node1 = pHead;
        ListNode* Node2 = pHead;
        for(int i = 0 ; i<number ; i++){
            Node1 = Node1->next;
        }
        while(Node1 != Node2){
            Node1 = Node1->next;
            Node2 = Node2->next;
        }
        return Node1;
    }
    

int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);
    ListNode a6(6);
    
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    a6.next = &a3;
    cout << EntryNodeOfLoop(&a1)->val <<endl;
    //std::cout << "Hello, world!\n";
}
