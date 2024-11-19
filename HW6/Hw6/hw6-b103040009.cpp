//Author:B103040009え獺睧
//Date:2022/11/14
//Purpose:倒ぉ﹃计т┮Τ瞷Ω计计ぇ计
#include <iostream>
using namespace std;
//treenode definition
class treenode{
    friend class bst;
    public:
        //treenode constructor
        treenode(int thedata,treenode* l,treenode* r,treenode* p){
            data = thedata; leftchild = l; rightchild = r; parent = p;
        }
    private:
        int data; treenode* rightchild; treenode* leftchild; treenode* parent;
};
class bst{
    public:
        //bst default constructor
        bst(){root=NULL;}
        treenode* Search(int k){
            //Search driver
            return Search(root,k);
        }
        treenode* Search(treenode* p,int k){
            //Search workhorse
            //Search the node that contain k recursively and return a pointer that points at it.
            if(!p)//if the binary tree is empty
                return 0;
            if(p->data == k)//found
                return p;
            if(p->data < k)   return Search(p->rightchild,k);
            return Search(p->leftchild,k);
        }
        void deletenode(int k){
            //this function deletes the node that contains k.
            //note that binary search tree will not contain more than one k in it.
            //this function doesn't check the node is in the tree or not.
            //because in this problem, we do deletion only if
            //we knew there is a node like that exists in the tree.
            treenode* c1 = root; treenode* c2 = 0;
            while(c1){
                //in this while loop we make c1 points to the node that we are going to remove,
                //and c2 points to the node that points to the node before c1.(c2 tracks c1).
                if(k == c1->data)   break;
                if(k < c1->data){
                    c2 = c1;
                    c1 = c1->leftchild;
                }
                else{
                    c2=c1;
                    c1=c1->rightchild;
                }
            }
            if(c1->leftchild==NULL&&c1->rightchild==NULL){
                //the node that we want to remove has zero child. =>simply remove it.
                if(c2==0){
                    //c1 == root
                    root = NULL;
                }
                else if(c1->data<c2->data)  c2->leftchild=NULL;
                else    c2->rightchild=NULL;
                delete c1;
            }
            else if(c1->leftchild!=NULL&&c1->rightchild!=NULL){
                //the node that we want to remove has two children.
                //we have to get the inorder successor of c1.
                //temp1 points at the inorder successor, and temp2 tracks temp1.
                treenode* temp1 = c1->rightchild; treenode* temp2 = c1;
                while(temp1->leftchild!=NULL){
                    temp2=temp1;
                    temp1=temp1->leftchild;
                }
                //the node that temp1 points at will not contain more than one child.
                //Moreover, the child is guaranteed to be the right child of temp1.
                //therfore, there are two conditions to handle.
                if(temp1->rightchild){
                    //simply move the right child up.
                    if(temp2->data<temp1->data){
                        temp2->rightchild = temp1->rightchild;
                        temp2->leftchild->parent = temp2;
                        c1->data = temp1->data;
                    }
                    else{
                        temp2->leftchild = temp1->rightchild;
                        temp2->leftchild->parent = temp2;
                        c1->data = temp1->data;
                    }
                    delete temp1;
                }
                else{
                    if(temp2->data<temp1->data){
                        temp2->rightchild=NULL;
                        c1->data = temp1->data;
                    }
                    else{
                        temp2->leftchild=NULL;
                        c1->data = temp1->data;
                    }

                    delete temp1;
                }
            }
            else{
                // the node that we want to remove has one child,
                //but we still needs to determine whether it is a left child or a right child.
                //afterward, things become simple.
                if(c2==0){
                    //root condition
                    if(c1->leftchild!=NULL) root=c1->leftchild;
                    else    root=c1->rightchild;
                }
                else if(c1->data<c2->data){
                    //c1 is the left child of c2
                    if(c1->leftchild!=NULL){
                        //left
                        c2->leftchild = c1->leftchild;
                        c1->leftchild->parent=c2;
                    }
                    else{
                        //right
                        c2->leftchild = c1->rightchild;
                        c1->rightchild->parent=c2;
                    }
                }
                else{
                    //c1 is the right child of c2
                    if(c1->leftchild!=NULL){
                        //left
                        c2->rightchild = c1->leftchild;
                        c1->leftchild->parent=c2;
                    }
                    else{
                        //right
                        c2->rightchild = c1->rightchild;
                        c1->rightchild->parent=c2;
                    }
                }
                delete c1;
            }
        }
        void insertnode(int k){
            //this function performs insertion.
            //But it doesn't check whether the node that we wants to insert is in the tree or not.
            //because we do insertion only if we knew that there isn't that kind of node in the tree.

            //we have to find the place to insert first.
            treenode* c1 = root;
            treenode* c2 = 0;
            //c2 points at a node that is going to become the parent of the new node
            // after we insert the new node.
            while(c1){
                c2 = c1;
                if(k == c1->data)   return;
                if(k < c1->data)    c1 = c1->leftchild;
                else    c1=c1->rightchild;
            }
            c1 = new treenode(k,0,0,c2);
            if(!root){
                //empty tree
                root = c1;
            }
            else if(k < c2->data)   c2->leftchild = c1;
            else    c2->rightchild = c1;
            return;
        }
        void printbstnode(){
            //printbstnode driver
            printbstnode(root);
        }
        void printbstnode(treenode* p){
            //Inorder traversal by stack(recursive)
            if(p){
                printbstnode(p->leftchild);
                cout<<" "<<p->data;
                printbstnode(p->rightchild);
            }
        }
        void printbstleft(){
            printbstleft(root);
        }
        void printbstleft(treenode* p){
            if(p){
                //Inorder traversal by stack(recursive)
                //but this function prints the information in the left child of the node
                // that is being traced.
                printbstleft(p->leftchild);
                if(p->leftchild)  cout<<" "<<p->leftchild->data;
                else    cout<<" 0";
                printbstleft(p->rightchild);
            }
        }
        void printbstright(){
            printbstright(root);
        }
        void printbstright(treenode* p){
            if(p){
                //Inorder traversal by stack(recursive)
                //but this function prints the information in the right child of the node
                // that is being traced.
                printbstright(p->leftchild);
                if(p->rightchild)  cout<<" "<<p->rightchild->data;
                else    cout<<" 0";
                printbstright(p->rightchild);
            }
        }
    private:
        treenode* root;
};
int main(){
    int flag=1;
    while(1){
        bst T;
        int num;
        while(cin>>num&&num!=-1){
            treenode* temp = T.Search(num);
            //every time we enter a number, we determine whether it exists in the tree or not.
            //if the answer is positive, delete.
            //if the answer is negative, insert.
            if(temp!=NULL)  T.deletenode(num);
            else    T.insertnode(num);

        }

        //this part of program prints the question-required output.
        if(flag==0) cout<<endl;
            flag=0;
            cout<<"node:";
            T.printbstnode();
            cout<<endl<<"left:";
            T.printbstleft();
            cout<<endl<<"right:";
            T.printbstright();
            cout<<endl;
    }
    system ("pause");
    return 0;
}
