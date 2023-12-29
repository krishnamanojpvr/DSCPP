#include<iostream>
using namespace std;
class node{
    public:
    int row;
    int column;
    int value;
    node * next;
    node (int r,int c,int v){
        row = r;
        column = c;
        value =v;
        next = NULL;
    }
};
void create_node(node * & head,int r , int c , int v){
    
    node * newnode = new node(r,c,v);
    if(head == NULL){
        head = newnode;
        return;
    }
    node * temp = head;
    
    while (temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= newnode;   
}

void display(node * head){
    node * temp =head;
     cout<<"row: ";
    while(temp!=NULL){
        cout<<temp->row<<" ";
        temp= temp->next;
    }
    temp =head;

    cout<<endl<<"column :";
    while(temp!=NULL){
        cout<<temp->column<<" ";
        temp= temp->next;

    }
    temp = head;
    cout<<endl<<"value :";

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp= temp->next;

    }
}

int main() {
    node * head = NULL;
  

// 4x5 sparse matrix
int sparseMatrix[4][5] = { 
{ 0 , 0 , 3 , 0 , 4 },
{ 0 , 0 , 5 , 7 , 0 },
{ 0 , 0 , 0 , 0 , 0 },
{ 0 , 2 , 6 , 0 , 0 } };

for (int i = 0; i < 4; i++)
{
    for(int j =0 ; j < 5 ; j++){
        if(sparseMatrix[i][j]!=0){
            create_node(head,i,j,sparseMatrix[i][j]);
        }
    }
  
}

    display(head);
    

    return 0;
}