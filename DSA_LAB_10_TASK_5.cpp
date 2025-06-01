
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
    
    
//    1.Insertion:
//    Insert a node at the end of the list recursively.
    Node* triverse_node(Node* t) {
        if (t->link == NULL) {
            return t;
        }
        return triverse_node(t->link);
    }



//    Insert a node at the beginning of the list recursively.
void Add_Node_at_head(int value)
    {
    Node* temp=new Node(value);
    if(!head)
    {
        head=temp;
        return;
    }
    temp->link=head;
    head=temp;
}
    
//    Insert a node at a given position recursively.
    void ADD_AT_A_SPYECIFIC_POSTION(Node* temp,int pos,int i,Node* new_node)
    {
        if(pos==i)
        { new_node->link=temp->link;
            temp->link =new_node;
            return;
           }
      return  ADD_AT_A_SPYECIFIC_POSTION(temp->link, pos,i+1,new_node);
    }
    void ADD_AT_A_SPYECIFIC_POSTION_helper(int value,int pos)
    {
        Node* new_node=new Node(value);
        Node* temp=head;
        int i=0;
        ADD_AT_A_SPYECIFIC_POSTION(temp, pos,i,new_node);
    }
//    2.Deletion:
//    Delete a node by value recursively.
    void delete_by_value(int value, Node* temp) {
        if (!temp || !temp->link) return;

        if (temp->link->data == value) {
            Node* toDelete = temp->link;
            temp->link = temp->link->link;
            delete toDelete;
            return;
        }
        delete_by_value(value, temp->link);
    }

    void deleteing_value(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* toDelete = head;
            head = head->link;
            delete toDelete;
            return;
        }
        delete_by_value(value, head);
    
    }
//    Delete a node at a given position recursively.
   
    void delete_by_position(int pos, Node* temp, int i, Node* prev) {
        if (!temp)
            return;
        if (pos == i) {
            if (prev) {
                prev->link = temp->link;
                delete temp;
            } else {
                // Deleting head
                head = temp->link;
                delete temp;
            }
            return;
        }
        delete_by_position(pos, temp->link, i + 1, temp);
    }
    void delete_by_position_helper(int pos)
    {
        Node* temp=head,*prev=NULL;
        int i=0;
        delete_by_position(pos,temp,i ,prev);
    }
//    3.Searching:
//    Search for a value in the list recursively and return its position (1-based index). Return -1 if not found.
    int search_recursive(Node* temp, int value, int index) {
        if (!temp) return -1;
        if (temp->data == value) return index;
        return search_recursive(temp->link, value, index + 1);
    }

    int search(int value) {
        return search_recursive(head, value, 1); // 1-based index
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
    cout << "Initial List: ";
    list.display();

    list.Add_Node_at_head(5);
    cout << "After Adding 5 at Head: ";
    list.display();

    list.ADD_AT_A_SPYECIFIC_POSTION_helper(25, 3); // Insert 25 at position 3 (after 2nd node)
    cout << "After Adding 25 at Pos 3: ";
    list.display();

    list.deleteing_value(30);
    cout << "After Deleting 30: ";
    list.display();

    list.delete_by_position_helper(2); // Delete node at pos 2
    cout << "After Deleting at Pos 2: ";
    list.display();

    int pos = list.search(40);
    if (pos != -1) cout << "40 Found at Position: " << pos << endl;
    else cout << "40 Not Found" << endl;

    return 0;
}

