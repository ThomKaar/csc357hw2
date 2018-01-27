/*Written for God by his grace.*/
#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

typedef struct node Node;
struct node
{
   Node *left;
   Node *right;
   Node *parent;
   int balance;
   int freq;
   char *word;
      
};
Node *new_node(char *word, int world_len);
void insert(Node *root, Node *new_node);
void avl_balance(Node *tree);
int string_order(char* str1, char* str2);
int height(Node *node);
int balance_factor(Node *node);
Node *rotateLeft(Node* B, Node *C);
Node *rotateRight(Node* B, Node *A);
Node *rotateLeftRight(Node* A, Node* B);
Node *rotateRightLeft(Node *C, Node* B);
#endif
