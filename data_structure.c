/*Written for God by his grace.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_structure.h" 
Node * new_node(char* word, int word_len)
{
  Node *node;
  char *node_word;
  node = (Node*) malloc(sizeof(Node));
  node_word = (char*)malloc(sizeof(char)*word_len);
  strcpy(node_word, word);
  node->left = NULL;
  node->right = NULL;
  node->balance = 0;
  node->freq = 1;
  node->word = node_word;
  node->parent = NULL;
  return node;
}

void insert(Node *root, Node *new_node)
{
   Node *parent;
   Node *current;   
   if(root == NULL)
   {
      root = new_node;
      return;
   }
   else 
   {
      current = root;
      
      while(1)
      {
         parent = current;
         
         /*Go to the left*/
         if(strcmp(parent->word, new_node->word) > 0)
         {  
	    current = current->left;
            /*insert to the left*/
            
            if(current == NULL)
            {
               parent->left = new_node;
               new_node->parent = parent;
               return;
            }   
         }/*go to the right node*/
         else if(strcmp(parent->word, new_node->word) != 0 && strcmp(parent->word, new_node->word) < 1)
         {
            current = current->right;
            
            /* insert to the right*/
            if(current == NULL)
            {
               parent->right = new_node;
               new_node->parent = parent;
               return;
            }
         }
         else
         {
            if(strcmp(current->word, new_node->word) == 0)
            {
               current->freq += 1; 
               return;
            }
         } 
      }   
   }
}
void avl_balance(Node *new_node)
{
   /*No mallocs are needed for this function because 
   *there are no new Nodes created*/
   Node *X_node;
   Node *G;
   Node *N;
   for(X_node = new_node->parent; X_node != NULL; X_node = new_node-> parent)
   {
      if(new_node == X_node->right)
      {
         if(X_node->balance > 0)
         {
             G = X_node->parent;
             if(new_node->balance < 0)
             {
                N = rotateRightLeft(X_node, new_node);
             }
             else
             {
                N  = rotateLeft(X_node, new_node);
             }
         } 
         else
         {
            if(X_node->balance < 0)
            {
               X_node->balance = 0;
               break;
            }
            X_node->balance = 1;
            new_node = X_node;
            continue;
         } 
      }
      else 
      {
         if(X_node->balance < 0)
         {
            G  = X_node->parent;
            if(new_node->balance > 0)
            {
               N = rotateLeftRight(X_node, new_node);
            }
            else
            {
               N = rotateRight(X_node, new_node);
            }
         }
         else
         {
            if(X_node->balance > 0)
            {
               X_node->balance = 0;
               break;
            }
            X_node->balance = -1;
            new_node = X_node;
            continue;
         }
      }
      N->parent = G;
      if(G != NULL)
      {
         if(X_node == G->left)
         {
            G->left = N;
         }
         else
         {
            G->right = N;
         }
      }
      else
      {
         N->parent = NULL;
      }
   }
}

/*B is higher on the tree than A*/
Node *rotateRight(Node *B, Node *A)
{
   Node *C = B->parent;
   B->right = C;
   B->parent = NULL;
   C->parent = B;
   C->left = NULL;
   return B;
}

/*A is higher than C*/
Node *rotateLeft(Node *B, Node *C)
{
   Node *A = B->parent;
   B->left = A;
   A->parent = B;
   B->parent = NULL;
   A->right = NULL;
   return B;   
}

/*A is higher on the tree than B*/
Node *rotateLeftRight(Node *A, Node *B)
{
   Node *C = A->parent;
   C->left = B;
   B->parent = C;
   B->left = A;
   A->parent = B;
   A->right = NULL;
   return rotateRight(B,A);   
}
/*C is higher on the tree than B*/
Node *rotateRightLeft(Node *C, Node *B)
{
   Node *A = C->parent;
   A->right =B;
   B->parent = A;
   B->right = C;
   C->parent = B;
   C->left = NULL;
   return rotateLeft(B,C);
   
}

/*returns 0 if the 2nd string is in alphabetical order earlier than the second*/
int string_order(char *str1, char *str2)
{
   int i, len, eq;
   eq = 0;
   len = strlen(str1);
   if(len > strlen(str2))
   {
      len = strlen(str2);
   }
   for(i=0;i< len; i++)
   {
      if(tolower(str1[i]) > tolower(str2[i]))
      {
         return 0;
      }
      else if(tolower(str1[i]) < tolower(str2[i]))
      {
         return 1;
      }
      else
      {
        eq += 1;
      }
   }
   if(eq == i)
   {
      return 2;
   }
   return 0;   
}

/*Compute Height of a node*/
int height(Node *node)
{  
   int lefth;
   int righth;
   if(node == NULL)
   {
      return -1;
   }   
   lefth = height(node->left);
   righth = height(node->right);
   if(lefth > righth)
   {
      return lefth + 1;
   }
   else
   {
      return righth + 1;
   }
}

int balance_factor(Node *node)
{
   return height(node->right) - height(node->left);
}


