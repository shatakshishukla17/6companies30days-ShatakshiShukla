class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* temp1=head;
        while(temp1!=nullptr){
            Node* temp2=temp1;
            Node* prev=temp2;
            int size=m;
            
            while(size>0 && temp2!=nullptr){
                size--;
                prev=temp2;
                temp2=temp2->next;
            }
            
            int size2=n;
            while(size2>0 && temp2!=nullptr){
                size2--;
                temp2=temp2->next;
            }
            
            prev->next=temp2;
            temp1=temp2;
        }
        return head;
    }
};
