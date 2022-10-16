//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
#include<stack>
class Solution
{
    
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        Node* pre= NULL;
        Node* curr = head;
        Node* currnext = NULL;
        
        while(curr != NULL){
            currnext = curr->next;
            
            curr->next =  pre;
            pre = curr;
            curr = currnext;
        }
        return pre;
        
        // stack<int> n;
        // int data;
        // Node* temp = head;
        
        // while(temp != NULL){
        //     n.push(temp -> data);
        //     temp = temp -> next;
        // }
        
        // Node* dummy = new Node(-1);
        // Node* p = dummy;
        
        // while(!n.empty()){
        //     int iti = n.top();
        //     n.pop();
        //     Node* nnode = new Node(iti);
            
        //     p->next = nnode;
        //     p = p->next;
        // }
        
        // return dummy->next;
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends