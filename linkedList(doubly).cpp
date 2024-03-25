#include <iostream>

using namespace std;

struct dnode
{
    int data;
    dnode *next;
    dnode *prev;
};

dnode *head = nullptr;

int insertHead(int n)
{
    dnode *temp = new dnode;
    temp->data = n;
    temp->next = head;
    temp->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = temp;
    }
    head = temp;
    return 1;
}

int insertTail(int n)
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    dnode *temp = new dnode;
    temp->data = n;
    temp->next = nullptr;
    temp->prev = nullptr;

    dnode *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return 1;
}

int insertAfter(int n, int after)
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    dnode *temp = new dnode;
    temp->data = n;
    temp->next = nullptr;
    temp->prev = nullptr;

    dnode *ptr = head;
    while (ptr != nullptr && ptr->data != after)
    {
        ptr = ptr->next;
    }

    if (ptr != nullptr)
    {
        temp->next = ptr->next;
        temp->prev = ptr;
        if (ptr->next != nullptr)
        {
            ptr->next->prev = temp;
        }
        ptr->next = temp;
        return 1;
    }
    else
    {
        cout << "Data not found";
        return 0;
    }
}

int insertBefore(int data, int before)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
        return 0;
    }

    dnode *n = new dnode;
    n->data = data;
    n->next = nullptr;
    n->prev = nullptr;

    if (head->data == before)
    {
        n->next = head;
        head->prev = n;
        head = n;
        return 1;
    }

    dnode *temp = head;
    while (temp->next != nullptr && temp->next->data != before)
    {
        temp = temp->next;
    }

    if (temp->next != nullptr)
    {
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != nullptr)
        {
            temp->next->prev = n;
        }
        temp->next = n;
        return 1;
    }
    else
    {
        cout << "Data not found" << endl;
        return 0;
    }
}

int deleteAtPosition(int position)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
        return 0;
    }

    if (position == 1)
    {
        dnode *temp = head;
        dnode *ptr = temp->next;
        delete (temp);
        head = ptr;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        return 1;
    }

    dnode *temp = head;
    int count = 1;

    while (count < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr && temp->next != nullptr)
    {
        dnode *ptr = temp->next;
        temp->next = ptr->next;
        if (ptr->next != nullptr)
        {
            ptr->next->prev = temp;
        }
        delete (ptr);
        return 1;
    }
    else
    {
        cout << "Position not found" << endl;
        return 0;
    }
}

int deleteHead()
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    dnode *temp = head;
    dnode *ptr = temp->next;
    delete (temp);
    head = ptr;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    return 1;
}

int deleteTail()
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    if (head->next == nullptr)
    {
        delete (head);
        head = nullptr;
        return 1;
    }
    dnode *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return 1;
}

void clearlist()
{
    dnode *temp = head;
    while (temp != nullptr)
    {
        dnode *ptr = temp->next;
        delete (temp);
        temp = ptr;
    }
    head = nullptr;
    cout << "List deleted! ";
}

int searchList(int s)
{
    dnode *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == s)
        {
            cout << "Element found" << endl
                 << endl;
            break;
        }

        temp = temp->next;
    }
}

void printList()
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    dnode *n = head;
    cout << "List: ";
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void reverseList()
{
    if (head == nullptr || head->next == nullptr)
    {

        return;
    }

    dnode *temp = nullptr;
    dnode *current = head;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    head = temp->prev;
}



void AscendingSort() {
    dnode* current = head;
    dnode* index = nullptr;

    while (current != nullptr) {
        index = current->next;

        while (index != nullptr) {
            if (current->data > index->data) {
                swap(index->data, current->data);
            }
            index = index->next;
        }
        current = current->next;
    }
}

void DescendingSort() {
    dnode* current = head;
    dnode* index = nullptr;

    while (current != nullptr) {
        index = current->next;

        while (index != nullptr) {
            if (current->data < index->data) {
                swap(index->data, current->data);
            }
            index = index->next;
        }
        current = current->next;
    }
}

int countNode() {
    dnode* ptr = head;
    int count = 0;

    while (ptr != nullptr) {
        count++;
        ptr = ptr->next;
    }
    cout << "Number of nodes : " << count;
    cout << endl;
}

int findMiddle() {
    if (head == nullptr || head->next == nullptr) {
        cout << head->data;
    }

    dnode* fast = head;
    dnode* slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle node : " << slow->data << endl;
}

int main()
{
    int n, choice;

    while (true)
    {
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert After" << endl;
        cout << "9. Insert Before" << endl;
        cout << "4. Print the list" << endl;
        cout << "5. Delete Head " << endl;
        cout << "6. Delete Tail " << endl;
        cout << "7. Delete at specific position " << endl;
        cout << "8. Search element " << endl;
        cout << "10.Reverse the list " << endl;
        cout << "11.Ascending Order Sort "<<endl;
        cout << "12.Descending Order Sort "<<endl;
        cout << "13.Count the node"<<endl;
        cout << "14.Find middle node "<<endl;
        cout << "0. Exit and clear list" << endl
             << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            clearlist();
            cout << "Updated List: " << endl;
            printList();
            return 0;
        case 1:
            cout << "Enter data: ";
            cin >> n;
            insertHead(n);
            cout << "Updated List: " << endl;
            printList();
            break;
        case 2:
            cout << "Enter data: ";
            cin >> n;
            insertTail(n);
            cout << "Updated List: " << endl;
            printList();
            break;
        case 3:
            int data, after;
            cout << "Data: " << endl;
            cin >> data;

            cout << "After which data: ";
            cin >> after;
            insertAfter(data, after);
            cout << "Updated List: " << endl;
            printList();
            break;
        case 4:
            printList();
            break;
        case 5:
            deleteHead();
            cout << "Updated List: " << endl;
            printList();
            break;
        case 6:
            deleteTail();
            cout << "Updated List: " << endl;
            printList();
            break;
        case 7:
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            deleteAtPosition(position);
            cout << "Updated List: " << endl;
            printList();
            break;
        case 8:
            int s;
            cout << "Enter element: ";
            cin >> s;
            searchList(s);
            break;
        case 9:
            int before;
            cout << "Enter data: " << endl;
            cin >> data;
            cout << "Enter before: " << endl;
            cin >> before;
            insertBefore(data, before);
            cout << "Updated List: " << endl;
            printList();
            break;
        case 10:
            reverseList();
            cout << "Updated List: " << endl;
            printList();
            break;
        case 11:
            AscendingSort();
            printList();
            break;
        case 12:
            DescendingSort();
            printList();
            break;
        case 13:
            countNode();
            printList();
            break;
        case 14:
            findMiddle();
            printList();
            break;

        default:
            cout << "Wrong input!!!" << endl;
        }
    }

    return 0;
}
