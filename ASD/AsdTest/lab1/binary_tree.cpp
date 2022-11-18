
#include <iostream>
using namespace std;

struct node;
typedef node * tree;

struct node
{
    tree parent;
    tree left;
    tree right;
    int value;
};

tree init(int);
void insertLeft(tree &, int);
void insertRight(tree &, int);
void deleteAll(tree &);
void deleteLeft(tree &);
void deleteRight(tree &);
int maxCount(tree &);

static void print_spaces(int depth) {
    for(int i=0;i<depth;i++) 
        cout << "  ";
}

void printTree(tree t) {
    static int depth=0;
    depth++;
    if (t != NULL) {
        printTree(t->right);
        print_spaces(depth);
        cout << t->value << endl;
        printTree(t->left);
    }
        depth--;
}

int sbilanciamento(tree t) {

}

int camminoMax(tree t) {
    if(t != NULL) {
        int max = 0, max2 = 0;
        if(t->left != NULL && t->left->value >= t->value)
            max = camminoMax(t->left) + 1;
        if(t->right != NULL && t->right->value >= t->value)
            max2 = camminoMax(t->right) + 1;
        max = max > max2 ? max : max2 ; 
        return max;
    }
    return 0;
}

int livelloValore(tree t, int livello) {
    int conta = 0;
    if(t != NULL) {
        conta += livelloValore(t->left, livello + 1);
        conta += livelloValore(t->right, livello + 1);
        if(t->value == livello)
            conta++;
    }
    return conta;
}

int main(int argc, char * argv[]) {
    tree t = init(1);
    insertLeft(t, 1);
    insertLeft(t, 2);
    insertLeft(t, 2);
    insertRight(t, 10);
    insertRight(t, 2);
    insertRight(t, 3);
    printTree(t);
    cout << camminoMax(t) << endl;

    return 0;
}

tree init(int value) {
    tree t = new node;
    t->parent = NULL;
    t->left = NULL;
    t->right = NULL;
    t->value = value;
    return t;
}

void insertLeft(tree & t, int value) {
    if(t == NULL)
        t = init(value);
    else {
        insertLeft(t->left, value);
        t->left->parent = t;
    }
}

void insertRight(tree & t, int value) {
    if(t == NULL)
        t = init(value);
    else {
        insertRight(t->right, value);
        t->right->parent = t;
    }
}

void deleteAll(tree & t) {
    if(t != NULL) {
        deleteLeft(t);
        deleteRight(t);
        delete t;
        t = NULL;
    }
}

void deleteLeft(tree & t) {
    if(t != NULL)
        deleteAll(t->left);
}

void deleteRight(tree & t) {
    if(t != NULL)
        deleteAll(t->right);
}
int maxCount(tree & t){
    int max=0;
    int counter=1;
    if(t!= NULL){
        if(t->left!=nullptr && t->right!=nullptr){
            if(t->left->value+t->value >= t->value+t->right->value){
                if(t->left>t->value){
                counter+= maxCount (t->left);
                }
            } else if(t->right->value>t->value){
                counter+= maxCount(t->right);
            }
        } 

    }else{
        counter=0;
    }
    return counter;
}
