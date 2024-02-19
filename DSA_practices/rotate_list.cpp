/**
 * The above code rotates a linked list to the right by k positions.
 * 
 * @param arr An array of integers representing the elements of the linked list.
 * @param n The variable `n` represents the number of elements in the linked list.
 * 
 * @return The function `rotateRight` in the `Solution` class returns a pointer to the head of the
 * rotated linked list.
 */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;

        // calculating size of the linked list
        int size = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }

        temp->next = head; // created a loop

        k = k % size; // handling when k > size

        // moving to the place where we need the node to point NULL
        while (--size >= k)
        {
            temp = temp->next;
        }

        ListNode *first = temp->next;
        temp->next = NULL;

        return first;
    }
};

// Function to create a linked list from an array
ListNode *createLinkedList(int arr[], int n)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        ListNode *newNode = new ListNode(arr[i]);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to display the linked list
void displayLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ListNode *head = createLinkedList(arr, n);
    delete[] arr;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    ListNode *rotatedList = solution.rotateRight(head, k);

    cout << "Rotated list: ";
    displayLinkedList(rotatedList);

    // Clean up the memory from the heap
    ListNode *temp;
    while (rotatedList != NULL)
    {
        temp = rotatedList;
        rotatedList = rotatedList->next;
        delete temp;
    }
    return 0;
}
