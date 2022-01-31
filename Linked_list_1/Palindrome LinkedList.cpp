/*
 Palindrome LinkedList
Send Feedback
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :

The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

 Remember/Consider :

While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

 Output format :

For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

 Constraints :

1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :

1
9 2 3 3 2 9 -1

Sample Output 1 :

true

Sample Input 2 :

2
0 2 3 2 5 -1
-1

Sample Output 2 :

false
true

Explanation for the Sample Input 2 :

For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.

*/
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// Function to check if two input
// lists have same data
// bool compareLists(struct Node* head1,
//                   struct Node* head2)
// {
//     struct Node* temp1 = head1;
//     struct Node* temp2 = head2;
 
//     while (temp1 && temp2)
//     {
//         if (temp1->data == temp2->data)
//         {
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
//         else
//             return 0;
//     }
 
//     // Both are empty reurn 1
//     if (temp1 == NULL && temp2 == NULL)
//         return 1;
 
//     // Will reach here when one is NULL
//     // and other is not
//     return 0;
// }

// void reverse(struct Node** head_ref)
// {
//     struct Node* prev = NULL;
//     struct Node* current = *head_ref;
//     struct Node* next;
     
//     while (current != NULL)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head_ref = prev;
// }

bool CompareTwoLinkedInLinks(Node * head1, Node * head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 && temp2)
    {

    if(temp1->data == temp2->data)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    else
    return 0;
    }

    if(temp1 == NULL && temp2 == NULL)
        return 1;

    return 0;
}

void reverse(Node ** head)
{
    Node *prev = NULL;
    Node *curr = *head;
    Node *next ;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;    
}

bool isPalindrome(Node *head)
{
    Node * fast = head ; Node * slow = head ;
    Node * Second_LinkedList ; Node * prev_slow = head ;
    Node * middle = NULL;
    bool result = true;
    if(head != NULL && head->next !=NULL)
    {
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        } 
        //slow is reached at mid
        //if LL is  odd 
        if(fast != NULL)
        {
            middle = slow;//store the middle node; 3->NULL;
            slow = slow->next;
        }
        Second_LinkedList = slow;       // 2->1->NULL
        prev_slow->next = NULL;         // make first LL ; 1->2->NULL
        reverse(&Second_LinkedList);    // 2->1->NULL
        result = CompareTwoLinkedInLinks(head , Second_LinkedList);
        //agin do reverse fun to print the same
        reverse(&Second_LinkedList);

        if(middle != NULL)//for odd
        {
            prev_slow->next = middle;//assign the middle node
            middle->next = Second_LinkedList;
        }
        else
        {
            prev_slow->next = Second_LinkedList;
        }
    }
    return result;
    
//     Node * fast = head ; 
//     Node * slow = head ; Node *Second_LL ; Node * prev_slow = head;
//     Node * Mid_Node = NULL;
//     bool result = true;
    
//     if(head != NULL && head->next != NULL)
//     {
//         while(fast != NULL && fast->next != NULL)
//         {
//             fast = fast->next->next;
//         	prev_slow = slow;        
//         	slow = slow->next;      
//         }
//         if(fast != NULL)//odd
//         {
//             Mid_Node = slow;
//             slow = slow->next;
//         }
//         Second_LL = slow;
//         prev_slow->next = NULL;
//         //TWO  LL IS NOW DIVIDED...
//         reverse(&Second_LL);
//         result = compareLists(head , Second_LL);
//         reverse(&Second_LL);
        
//         if(Mid_Node != NULL)//if odd
//         {
//             prev_slow->next= Mid_Node;
//             Mid_Node->next = Second_LL;
            
//         }
//         else
//         {
//             prev_slow->next = Second_LL;
//         }
                
//     }
//     return result;
    
}
 


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}