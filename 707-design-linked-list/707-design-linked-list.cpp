class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class MyLinkedList {
    Node* head;
    Node* tail;
public:
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* temp = head;
        for(int i = 0 ; i < index && temp; i++){
            temp = temp->next;
        }
        return temp == NULL ? -1 : temp->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        // cout<<head->data<<" ";
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        while(temp && temp->next){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        if(temp)
            temp->next = newNode;
        else
            head = newNode;
        // cout<<head->next->data<<" ";
    }
    
    void addAtIndex(int index, int val) {
        Node* temp = head;
        if(index == 0){
            Node* newnode = new Node(val);
            newnode->next = head;
            head = newnode;
            return;
        }
        for(int i = 0 ; i < index-1 && temp; i++){
            temp = temp->next;
        }
        if(temp){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        // temp = head;
        // while(temp){
        //     cout<<temp->data<<" ";
        //     temp = temp->next;
        // }
    }
    
    void deleteAtIndex(int index) {
        Node* temp = head;
        if(index == 0){
            head = head->next;
            return;
        }
        for(int i = 0 ; i < index-1 && temp; i++){
            temp = temp->next;
        }
        if(temp && temp->next){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */