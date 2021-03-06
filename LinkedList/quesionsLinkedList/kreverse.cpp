#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
node* takeInput(){
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node *reverse_linked_list(node *head) {
    if(head==NULL||head->next==NULL)
        return head;
    node* smallhead=reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}
node* kReverse(node*head,int n) { 
    if(n==1)
        return head;
    int i=1;
    node*temp=head,*head1=head,*head2=head;
    while(temp!=NULL) {
        if(i%n==0||temp->next==NULL) { 
            node*head3=temp->next;
            temp->next=NULL;
            node*h=head2; head2=reverse_linked_list(head2);
            if(head1==head){
                head1=head2;
                head=head2;
            }
            else 
                head1->next=head2;
            h->next=head3;
            head1=h;
            head2=head3;
            temp=head3;
        } 
        else{
            temp=temp->next;
        }
        i++;
    }
    return head;
}

int main() {
    node* head = takeInput();
    print(head);
    head = kReverse(head ,3);
    print(head);
}
