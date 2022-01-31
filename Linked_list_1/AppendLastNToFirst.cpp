/*
 AppendLastNToFirst
Send Feedback
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Input format :

The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.

Remember/Consider :

While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :

For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :

1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :

2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5

Sample Output 1 :

3 4 5 1 2
20 30 40 50 60 10

Sample Input 2 :

1
10 6 77 90 61 67 100  -1
4

Sample Output 2 :

90 61 67 100 10 6 77 

 Explanation to Sample Input 2 :

We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which represents the last 4 nodes. When we move this list to the front then the remaining part of the initial list which is, "10->6->77" is attached after 100. Hence, the new list formed with an updated head pointing to 90.

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

Node *appendLastNToFirst(Node *head, int k)
{
    if(head == NULL || k == 0)
        return head;
    
    {
    Node *fast=head;
    Node*slow=head;

    int c=1;

    while(c<k)
    {
        fast=fast->next;
        c++;
    }

Node *prev;


    while(fast->next!=NULL)
    {
        prev=slow;
        fast=fast->next;
        slow=slow->next;
        //prev=prev->next;
    }

    fast->next=head;
    head=slow;
    prev->next=NULL;



return head;

}

    /*Node *temp = head;
    if(head == NULL || n == 0)
        return head;
    
    int len = 0 ; int count  = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int k = len%n;
    Node *tail = temp;
    count = k - n - 1;
    int i = 0;
    while(temp != NULL && i<count){
        temp = temp->next;
        i++;
    }
     Node *head2 = temp->next;
    temp->next = NULL;

    Node *temp2 = head2;
    // while(temp2 != NULL){
    //     temp2 = temp2->next;        
    // }
     tail->next = head;
    return head2;*/
    
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}