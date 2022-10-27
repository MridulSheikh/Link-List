#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void inserAtHead(Node *&head, int val)
{
    // new node creation
    Node *newNode = new Node(val);
    // update of new node next
    newNode->Next = head;
    // update of head
    head = newNode;
}

void inserAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
};

void insertAtspacificPosition(Node *&head, int val, int position)
{
    Node *temp = head;
    int i = 0;

    while (i < position - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
};

int searchQunicValue(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    };
    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        };
        temp = temp->Next;
        count++;
    }
    return count;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    };
    return count;
}

void searchByduplicateValue(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    int flag = 0;
    int size = countLength(head);
    int pos[size + 1], j = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            pos[j] = count;
            j++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    if (flag == 0)
        cout << "The searched value is not yet in the list" << endl;
    else
    {
        pos[0] = j;
        cout << "The value is found at positoin: ";
        for (int i = 1; i < pos[0]; i++)
        {
            cout << pos[i];
            if (i < pos[0] - 1)
                cout << " ";
        }
        cout << endl;
    }
}

Test searchByduplicteVlauereturn(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    Test T;
    int j = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            T.position[j] = count;
            j++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = j;
    return T;
}

void insertValueAftersearch(Node *&head, int searchValue, int value)
{
    int position;
    position = searchQunicValue(head, searchValue);
    insertAtspacificPosition(head, value, position + 1);
}

void deletionFromHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the link list" << endl;
    }
}

void display(Node *n)
{

    while (n != NULL)
    {
        if (n != NULL)
        {
            cout << n->value;
            if (n->Next != NULL)
            {
                cout << " -> ";
            }
        }
        n = n->Next;
    }
    cout << endl;
}

void deletionFromTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
            cout << "There are not value for tail deletion" << endl;

        else
            deletionFromHead(head);
    }
}

void deletionAtSpacificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countLength(head))
    {
        if (position == 1)
        {
            deletionFromHead(head);
        }
        else if (position == countLength(head))
        {
            deletionFromTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        if (position > countLength(head))
        {
            cout << "position out of bound" << endl;
        }
        else
        {
            cout << "there is no value in linklist" << endl;
        }
    }
}

void deletionByvalueUnic(Node *&head, int value)
{
    int position;

    position = searchQunicValue(head, value);
    deletionAtSpacificPosition(head, position);
}

Node *reverseNoneRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = head->Next;

    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *next = head->Next;
    }

    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->Next;
    }

    return prev;
}

Node *reverseRecursive(Node *&head)
{
	//This is our base call 
	if(head->Next == NULL)
	{
			return head;
	}
	
	//Recursive call
	Node* newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
	
	return newHead;
};

int main()
{
    Node *head = NULL;

    cout << "Choice 0: Exit" << endl
         << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at Spacific position" << endl
         << "Choice 4: Search a value from link list" << endl
         << "Choice 5: Search a duplicate value from link list" << endl
         << "Choice 6: Insert a vlue after seaching value position" << endl
         << "Choice 7: Deletion from head" << endl
         << "Choice 8: Deletion from tail" << endl
         << "Choice 9: Deletion from a spacific positon" << endl
         << "Choice 10: Deletion by value (uniq list)" << endl
         << "Choice 11: revesal of list none-recursive way" << endl
         << "Choice 12: revesal of list recursive way" << endl;

    int choice = 1;
    int n, pos;

    while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 11 || choice == 10 || choice == 12)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> n;
            inserAtHead(head, n);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> n;
            inserAtTail(head, n);
            break;
        case 3:
            cout << "Enter the Desired position : ";
            cin >> pos;
            cout << "Enter the value: ";
            cin >> n;
            insertAtspacificPosition(head, n, pos);
            break;
        case 4:
            cout << "Enter the value for search : ";
            cin >> n;
            pos = searchQunicValue(head, n);
            if (pos != -1)
            {
                cout << "The Number is positoin is : " << pos << endl;
            }
            else
            {
                cout << "The Number is positoin is not found!" << endl;
            }
            break;
        case 5:
            cout << "Enter the value for search : ";
            cin >> n;
            Test T;
            T = searchByduplicteVlauereturn(head, n);
            if (T.position[0] == 1)
            {
                cout << "the search not yet in the list" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The value is found position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "enter the value for search : ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the insert value : ";
            cin >> n;
            insertValueAftersearch(head, searchValue, n);
            break;
        case 7:
            deletionFromHead(head);
            break;
        case 8:
            deletionFromTail(head);
            break;
        case 9:
            cout << "Enter the Desired position : ";
            cin >> pos;
            deletionAtSpacificPosition(head, pos);
            break;
        case 10:
            int value;
            cout << "Enter the value for deletion :";
            cin >> value;
            deletionByvalueUnic(head, value);
        case 11:
            head = reverseNoneRecursive(head);
            break;

        case 12: 
            reverseRecursive(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    display(head);

    int length = countLength(head);

    cout << "the length of list is : " << length << endl;
    

    return 0;
}
