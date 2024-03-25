#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = nullptr;

int insertHead(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
    return 1;
}

int insertTail(int n)
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    node *temp = new node;
    temp->data = n;
    temp->next = nullptr;

    node *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return 1;
}

int insertAfter(int n, int after)
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    node *temp = new node;
    temp->data = n;
    temp->next = nullptr;

    node *ptr = head;
    while (ptr != nullptr && ptr->data != after)
    {
        ptr = ptr->next;
    }

    if (ptr != nullptr)
    {
        temp->next = ptr->next;
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

    node *n = new node;
    n->data = data;
    n->next = nullptr;

    if (head->data == before)
    {
        n->next = head;
        head = n;
        return 1;
    }

    node *temp = head;
    while (temp->next != nullptr && temp->next->data != before)
    {
        temp = temp->next;
    }

    if (temp->next != nullptr)
    {
        n->next = temp->next;
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
   if(head == nullptr){
    cout<<"Empty"<<endl;
    return 0;
   }

   if(position ==1){
    node *temp = head;
    node *ptr  = temp->next;
    delete(temp);
    head = ptr;

    return 1;
    }
    node *temp = head;
    int count =1;

    while(count <position-1 && temp!=nullptr){
            temp = temp->next;
            count++;

}
node *ptr = temp->next;
temp->next = temp->next->next;
delete(ptr);
return 1;
}

int deleteHead()
{
    if(head == nullptr){
        cout<<"Empty";
    }
    node *temp = head;
    node *ptr = temp->next;
    delete(temp);
    head = ptr;

    return 1;

}

int deleteTail() {
    if(head == nullptr){
        cout<<"Empty";
    }
    if(head->next==nullptr){
        delete(head);
        head = nullptr;
        return 1;
    }
    node *temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return 1;
}


void clearlist()
{
    node *temp = head;
    while (temp != nullptr)
    {
        node *ptr = temp->next;
        delete (temp);
        temp = ptr;
    }
    head = nullptr;
    cout << "List deleted! ";
}

void searchList(int data)
{
    int counter =0;
    node *ptr = head;
    while(ptr!=nullptr){
        if(ptr->data==data){
                counter++;
                cout<<"Data found at "<<counter<<"th position "<<endl;

        }

        ptr=ptr->next;
        counter++;
    }
}


void printList()
{
    if (head == nullptr)
    {
        cout << "Empty";
    }
    node *n = head;
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


    node *prev = nullptr;
    node *current = head;
    node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;


        prev = current;
        current = nextNode;
    }

    head = prev;
}

void AscendingSort(){
    node *current = head;
    node *index = nullptr;

    while(current!=nullptr){
        index = current->next;

        while(index!=nullptr){
            if(current->data > index->data){
                swap(index->data,current->data);
            }
            index = index->next;
        }
        current= current->next;
    }

}
void DescendingSort(){
    node *current = head;
    node *index = nullptr;

    while(current!=nullptr){
        index = current->next;

        while(index!=nullptr){
            if(current->data < index->data){
                swap(index->data,current->data);
            }
            index = index->next;
        }
        current= current->next;
    }

}

int countNode()
{
    node *ptr = head;
    int count = 0;

    while(ptr!=nullptr){
        count++;
        ptr = ptr->next;
    }
    cout<<"Number of nodes : "<<count;

    cout<<endl;

}

int findMiddle(){
    if(head == nullptr || head->next == nullptr){
        cout<<head->data;
    }

    node *fast = head;
    node *slow = head;

    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle node : "<<slow->data<<endl;
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
        cout << "10.Reverse the list "<<endl;
        cout << "11.Ascending Order Sort "<<endl;
        cout << "12.Descending Order Sort "<<endl;
        cout << "13.Count the node"<<endl;
        cout << "14.Find middle node "<<endl;
        cout << "0. Exit and clear list" << endl<< endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            clearlist();
            cout<<"Updated List: "<<endl;
            printList();
            return 0;
        case 1:
            cout << "Enter data: ";
            cin >> n;
            insertHead(n);
            cout<<"Updated List: "<<endl;
            printList();

            break;
        case 2:
            cout << "Enter data: ";
            cin >> n;
            insertTail(n);
            cout<<"Updated List: "<<endl;
            printList();

            break;
        case 3:
            int data, after;
            cout << "Data: " << endl;
            cin >> data;

            cout << "After which data: ";
            cin >> after;
            insertAfter(data, after);
             cout<<"Updated List: "<<endl;
            printList();
            break;
        case 4:
            printList();
            break;
        case 5:
            deleteHead();
            cout<<"Updated List: "<<endl;
            printList();
            break;
        case 6:
            deleteTail();
            cout<<"Updated List: "<<endl;
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

            cout<<"Enter element: ";
            cin>>data;
            searchList(data);
            break;
        case 9:
            int before;
            cout<<"Enter data: "<<endl;
            cin>>data;
            cout<<"Enter before: "<<endl;
            cin>>before;
            insertBefore(data,before);
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

