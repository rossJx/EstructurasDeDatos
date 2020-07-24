#include <iostream>

using namespace std;

class Node{
    public:
        int number;
        const char* word;
        Node *next, *prev;
        Node(int value)
        {
            prev = nullptr;
            next = nullptr;
            number = value; 
            word = nullptr;
        }
        Node(const char* value)
        {
            prev = nullptr;
            next = nullptr;
            number = '\0'; //Number is set to null character to allow
            word = value;  //comparision on conditionals at printing
        }
};

class doublyLinkedList{
    public:
        Node *root;
        doublyLinkedList(){
            root = nullptr;
        }

        bool isEmpty()
        {
            if (this->root == nullptr) return true;
            else return false;
        }

        void insertAtEnd(int data)  //Use polymorphism to help in decision
        {                           //of storing either int or char*
            if(this->isEmpty()){
                root = new Node(data);
                return;
            }
            Node *ref = this->root;
            while (ref->next != nullptr) ref = ref->next;
            Node *new_node = new Node(data);
            ref->next = new_node;
            new_node->prev = ref;
        }
        void insertAtEnd(const char* data)
        {
            if(this->isEmpty()){
                root = new Node(data);
                return;
            }
            Node *ref = this->root;
            while (ref->next != nullptr) ref = ref->next;
            Node *new_node = new Node(data);
            ref->next = new_node;
            new_node->prev = ref;
        }

        void insertAtBeginning(int data)
        {
            if(this->isEmpty()){
                root = new Node(data);
                return;
            }
            else{
                Node *new_node = new Node(data);
                root->prev = new_node;
                new_node->next = root;
                root = new_node;
            }
        }
        void insertAtBeginning(const char* data)
        {
            if(this->isEmpty()){
                root = new Node(data);
                return;
            }
            else{
                Node *new_node = new Node(data);
                root->prev = new_node;
                new_node->next = root;
                root = new_node;
            }
        }

        void insertAtPosition(int position, int data)
        {
            if (position == 0) this ->insertAtBeginning(data);
            else if (this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else{
                Node *ref = root;
                for(int i=0; i<position; i++){
                    if(ref == nullptr){
                        cout << "Invalid action. The list has no element ["<<position<<"] and forward\n";
                        return;
                    }
                    ref = ref->next;
                }
                Node *new_node = new Node(data);
                if(ref == nullptr) this->insertAtEnd(data);
                else{
                    ref->prev->next = new_node;
                    new_node->prev = ref->prev;
                    new_node->next = ref;
                    ref->prev = new_node;
                }
            }
        }

        void insertAtPosition(int position, const char* data)
        {
            if (position == 0) this ->insertAtBeginning(data);
            else if (this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else{
                Node *ref = root;
                for(int i=0; i<position; i++){
                    if(ref == nullptr){
                        cout << "Invalid action. The list has no element ["<<position<<"] and forward\n";
                        return;
                    }
                    ref = ref->next;
                }
                Node *new_node = new Node(data);
                if(ref == nullptr) this->insertAtEnd(data);
                else{
                    ref->prev->next = new_node;
                    new_node->prev = ref->prev;
                    new_node->next = ref;
                    ref->prev = new_node;
                }
            }
        }

        void deleteFirstElement()
        {
            if(this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else if (root->next == nullptr) root = nullptr;
            else{
                root = root->next;
                root->prev = nullptr;
            }
        }

        void deleteLastElement()
        {
            if(this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else if (root->next == nullptr) root = nullptr;
            else{
                Node *ref = root;
                while(ref->next != nullptr) ref = ref ->next;
                ref->prev->next = nullptr;
            }
        }

        void deleteAtPosition(int position){
            if (this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else if(position == 0) this ->deleteFirstElement();
            else{
                Node *ref = root;
                for (int i = 0; i < position; i++)
                {
                    if(ref->next == nullptr){
                        cout << "Invalid action. The list has no element ["<<position<<"] and forward\n";
                        return;
                    }
                    ref = ref->next;
                }
                if(ref->next == nullptr) this->deleteLastElement();
                else{
                    ref->prev->next = ref->next;
                    ref->next->prev = ref->prev;
                }
            }
        }

        void search(int data)
        {
            if(this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else{
                Node *ref = root;
                int count = 0;
                while (true){
                    if(ref == nullptr){
                        cout << "Sorry. The list has no element "<< data <<endl;
                        return;
                    }
                    else if (data == ref->number && ref->number!='\0')
                    {
                        cout << "Element "<< data << " located at position [" << count <<"]"<<endl;
                        return;
                    }
                    ref = ref->next;
                    count++;
                }
            }
        }
        void search(const char* data)
        {
            if(this->isEmpty()) cout << "Invalid action. The list is empty\n";
            else{
                Node *ref = root;
                int count = 0;
                while (true){
                    if(ref == nullptr){
                        cout << "Sorry. The list has no element "<< data <<endl;
                        return;
                    }
                    else if (data == ref->word)
                    {
                        cout << "Element "<< data << " located at position [" << count <<"]"<<endl;
                        return;
                    }
                    ref = ref->next;
                    count++;
                }
            }
        }

        void show()
        {
            if(this->isEmpty()) 
                cout<<"The list is empty. Insert something :)\n";
            else{
                Node *ref = this->root;
                cout << "| ";
                while (ref->next != nullptr)
                {
                    if(ref->number!='\0') cout << ref->number << " <-> ";
                    else cout << ref->word << " <-> ";
                    ref = ref->next; 
                }
                if(ref->number!='\0') cout << ref->number << " |\n";
                else cout << ref->word << " |\n";
            }
        }
};

int main(){
    doublyLinkedList *list = new doublyLinkedList();

    //Put here a menu or the options you would like your list to do.

    list->insertAtEnd("d");
    list->insertAtEnd("e");
    list->insertAtEnd("f");
    list->insertAtEnd("g");
    list->insertAtBeginning("c");
    list->insertAtBeginning("b");
    list->insertAtBeginning("a");
    list->show();
    list->deleteAtPosition(7);
    list->deleteAtPosition(1);
    list->show();
    list->deleteAtPosition(5);
    list->show();
    list->deleteAtPosition(0);
    list->show();
    list->insertAtPosition(1,1);
    list->show();
    list->search(0);
    
    system("pause");
    return 0;
}