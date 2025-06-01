#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int value): data(value), link(NULL) {}
};

struct Link_List {
    Node* head;
    Link_List(): head(nullptr) {}

    Node* triverse_node(Node* t) {
        if (t->link == NULL) {
            return t;
        }
        return triverse_node(t->link); 
    }

    void create_node(int value) {
        Node* temp = new Node(value);
        if (!head) {
            head = temp;
        } else {
            Node* last = triverse_node(head);
            last->link = temp;
        }
    }

    void triverse_to_display(Node* temp) {
        if (temp == NULL) {
            cout << "List End" << endl;
            return;
        }
        cout << temp->data << " ";
        triverse_to_display(temp->link);
    }

    void display() {
        if (!head) {
            cout << "NO List :(" << endl;
            return;
        }
        triverse_to_display(head);
    }
};

int main() {
    Link_List list;

    list.create_node(10);
    list.create_node(20);
    list.create_node(30);
    list.create_node(40);
    

    cout << "Linked List Contents: ";
    list.display();
    list.create_node(50);
    list.display();
    return 0;
}
