/*Written for God by his grace*/
#include "checkit.h"
#include "data_structure.h"
void avl_balanco(Node *new_node)
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

void test_avl_balance_0()
{
   Node *A, *B,*C;
   char s0[] = "A";
   char s1[] = "B";
   char s2[] = "C";
   A = new_node(s0,1);
   B = new_node(s1,1);
   C = new_node(s2,1);
   avl_balance(A);
   checkit_int(A->balance, 0);
   insert(A,B);
   avl_balance(B);
   checkit_int(B->balance,0);
   checkit_int(A->balance,1);
   insert(B,C);
   avl_balance(C);
   checkit_int(C->balance,0);
   checkit_int(B->balance,0);
   checkit_int(A->balance,0);
   checkit_int(strcmp(B->left->word, s1), 0);
   checkit_int(strcmp(B->right->word, s2), 0);
   checkit_int(strcmp(A->parent->word,s0), 0);
   checkit_int(strcmp(B->parent->word,s0), 0);
}

void test_avl_balance()
{
   test_avl_balance_0();
}

int  main()
{
  test_avl_balance();
  return 0;
}
