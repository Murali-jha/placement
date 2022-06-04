Node* merge(Node* t1, Node* t2){
    
    Node* dummy = new Node(0);
    Node* res = dummy;
    
    while(t1 && t2){
        if(t1->data<=t2->data){
            dummy->bottom = t1;
            t1 = t1->bottom;
        }
        else{
            dummy->bottom = t2;
            t2 = t2->bottom;
        }
        dummy = dummy->bottom;
    }
    
    if(t1){
        dummy->bottom = t1;
    }
    if(t2){
        dummy->bottom = t2;
    }
    return res->bottom;
}
    

Node *flatten(Node *root)
{
   // Your code here
   if(root->next==NULL){
        return root;
    }
    Node* temp = flatten(root->next);
    return merge(root,temp);
}
