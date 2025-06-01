#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* link;
    Node(int value):data(value),prev(NULL),link(NULL){}
};
struct doubly_link_list{
    Node* head;
    doubly_link_list():head(nullptr){}
    void add_node_at_head(int value)
    {
        Node* temp=new Node(value);
        if(!head)
        {
            head=temp;
            return;
        }
        temp->link=head;
        head->prev=temp;
        head=temp;
    }
    void triverse_till_end(Node* temp, Node* move)
    {
        if (move->link == NULL)
        {
            move->link = temp;
            temp->prev = move;
            return;
        }
      return   triverse_till_end(temp, move->link);
    }
    void add_node_at_the_end(int value)
    {
        Node*temp=new Node(value);
        if(!head)
        {
            head=temp;
            return;
        }
        Node *move=head;
        triverse_till_end(temp,move);
        
    }
    void add_at_a_specific_postion(int pos,Node*temp,int i=0)
    {
        if(i>pos)
        {
            cout<<" Error out of bound :( "<<endl;
            return;
        }
        if(i<0)
        {
            cout<<" Error too small value :( "<<endl;
            return;
        }
        if(i==pos)
        {
            cout<<"\n  Enter the value for new Node: ";
            int value;
            cin>>value;
            Node* new_node=new Node(value);
            new_node->prev=temp;
            new_node->link=temp->link;
            temp->link=new_node;
            return;
        }
        add_at_a_specific_postion(pos,temp->link,i+1);
        
    }
    void delete_node_by_value_helper(int value,Node *temp)
    {
        if(!temp)
        {
            cout<<" \n No List KIDO ): ";
            return;
        }
        if(value==temp->data)
        {
            if (temp->prev)
                temp->prev->link = temp->link;
            if (temp->link)
                temp->link->prev = temp->prev;
            delete temp;
            return;
        }
        delete_node_by_value_helper(value,temp->link);
        return;
    }
    void delete_node_by_value(int value)
    {
        Node* temp=head;
        delete_node_by_value_helper(value,temp);
        
    }
    void delete_node_by_postion_helper(int pos,Node *temp,int i=0)
    {
        if(i>pos)
        {
            cout<<" Error out of bound :( "<<endl;
            return;
        }
        if(i<0)
        {
            cout<<" Error too small value :( "<<endl;
            return;
        }
        if(i==pos)
        {
            if (temp->prev)
                temp->prev->link = temp->link;
            if (temp->link)
                temp->link->prev = temp->prev;
            delete temp;
            return;
        }
       
        return  delete_node_by_postion_helper(pos,temp->link,i+1);
    }

    void delete_at_a_given_postion(int pos)
    {
        Node* temp=head;
        delete_node_by_postion_helper(pos,temp,0);
    }
    void search_a_number_helper(int value,Node* temp,int i)
    {
        if(temp->data==value)
        {   cout<<" Value "<<value<<" Found at: "<<i<<endl;
            return;
        }
        if(!temp)
        {
            cout<<" Error no List KIDO :( "<<endl;
            return;
            
        }
       
        
        return search_a_number_helper(value,temp->link,i+1);
    }
    void search_a_number(int value)
    {
        Node* temp=head;
        search_a_number_helper(value,temp,0);
    }
    char print_in_order(Node*temp)
    {
        if(temp==NULL)
        {
            cout<<" List End :) ";
            return -1;
        }
        cout<<temp->data<<" ";
        return temp->data;
        print_in_order(temp->link);
        
    }
    void print_straight()
    {
        if(!head)
        {
            cout<<" Error No list guys "<<endl;
            return;
        }
        Node* temp=head;
        print_in_order(temp);
    }
    char  print_in_reverse_order(Node* temp){
        if(temp==NULL)
        {
            cout<<" List End :) ";
            return -1;
        }
       
        print_in_reverse_order(temp->link);
        cout<<temp->data<<" ";
        return temp->data;
    }
    void print_backword()
    {
        if(!head)
        {
            cout<<" Error No list guys "<<endl;
            return;
        }
        Node* temp=head;
        print_in_reverse_order(temp);
    }
    bool palandrom_check()
    { Node*temp=head;
        if( print_in_reverse_order(temp)==  print_in_order(temp))
            return true;
        else
            return false;
    }
};
int main() {
    doubly_link_list dll;

    cout << "Adding nodes at head...\n";
    dll.add_node_at_head(30);
    dll.add_node_at_head(20);
    dll.add_node_at_head(10);
    
    cout << "List after adding nodes at head:\n";
    dll.print_straight();
    cout << "\n";

    cout << "\nAdding node at the end...\n";
    dll.add_node_at_the_end(40);
    dll.print_straight();
    cout << "\n";

    cout << "\nSearching for 20...\n";
    dll.search_a_number(20);

    cout << "\nDeleting node with value 20...\n";
    dll.delete_node_by_value(20);
    dll.print_straight();
    cout << "\n";

    cout << "\nDeleting node at position 1...\n";
    dll.delete_at_a_given_postion(1);
    dll.print_straight();
    cout << "\n";

    cout << "\nList in reverse (backward):\n";
    dll.print_backword();
    cout << "\n";

    return 0;
}
