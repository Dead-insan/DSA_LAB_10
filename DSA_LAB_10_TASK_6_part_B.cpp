#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* link;
    Node(int value): data(value), prev(NULL), link(NULL) {}
};

struct doubly_link_list {
    Node* head;
    doubly_link_list(): head(nullptr) {}

    Node* get_tail(Node* temp) {
        if (temp == NULL)
            return NULL;
        if (temp->link == NULL)
            return temp;
        return get_tail(temp->link);
    }

    bool palindrome_helper(Node* left, Node* right) {
        if (left == NULL || right == NULL)
            return true;

        if (left == right || right->link == left)
            return true;

        if (left->data != right->data)
            return false;

        return palindrome_helper(left->link, right->prev);
    }

    bool palandrom_check() {
        Node* tail = get_tail(head);
        return palindrome_helper(head, tail);
    }
};

int main() {
    doubly_link_list dll;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(0);

    dll.head = n1;
    n1->link = n2;
    n2->prev = n1;
    n2->link = n3;
    n3->prev = n2;

    if (dll.palandrom_check())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    return 0;
}
