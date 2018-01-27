/*Written for God by his grace*/
#include "data_structure.h"
#include "checkit.h"

void test_insert_0()
{
   Node *node1;
   char s1[] = "hello";
   node1 = new_node(s1,5);
   insert(NULL, node1);
   checkit_int(node1->freq, 1);
}

void test_insert_1()
{
   Node *node1;
   Node *node2;
   char s1[] = "hello";
   char s2[] = "yep";
   node1 = new_node(s1, 5);
   node2 = new_node(s2, 3);
   insert(NULL, node1);
   insert(node1, node2);
   checkit_int(node1->freq,1);
}

void test_insert_2()
{
   Node *node0;
   Node *node1;
   Node *node2;
   Node *node3;
   Node *node4;
   char s0[] = "Help";
   char s1[] = "I";
   char s2[] = "Need";
   char s3[] = "Somebody";
   node0 = new_node(s0,4);
   node1 = new_node(s1,1);
   node2 = new_node(s2,4);
   node3 = new_node(s3,8);
   node4 = new_node(s3,8);
   node0->left = node1;
   node0->right = node2;
   node2->right = node3;
   insert(node0, node4);
   checkit_int(node3->freq,2);

}

void test_insert_3()
{
   /*Tree order 
 *      node0
 *   node1 node2
 *     node4  node3
 *          */
   Node *node0;
   Node *node1;
   Node *node2;
   Node *node3;
   Node *node4;
   char s0[] = "Help";
   char s1[] = "I";
   char s2[] = "Need";
   char s3[] = "Somebody";
   char s4[] = "Heeelp";
   node0 = new_node(s0,4);
   node1 = new_node(s1,1);
   node2 = new_node(s2,4);
   node3 = new_node(s3,8);
   node4 = new_node(s4,8);
   node0->left = node1;
   node0->right = node2;
   node2->right = node3;
   insert(node0, node4);
   checkit_int(node4->freq,1);
   checkit_int(node1->right == node4, 0); 
}

void test_insert()
{
   test_insert_0();
   test_insert_1();
   test_insert_2();
   test_insert_3();
}


void test_rotateRight_0()
{
   Node *A;
   Node *B;
   Node *C;
   int cmp, cmp1, cmp2, cmp3;
   char s0[] = "A";
   char s1[] = "B";
   char s2[] = "C";
   A = new_node(s0,1);
   B = new_node(s1,1); 
   C = new_node(s2,1);
   insert(C,B);
   insert(B,A);
   B = rotateRight(B,A);
   cmp = strcmp(B->left->word, s0);
   cmp1 = strcmp(B->right->word, s2);
   cmp2 = strcmp(B->left->parent->word, s1);
   cmp3 = strcmp(B->right->parent->word, s1);
   checkit_int(cmp,0);
   checkit_int(cmp1,0);
   checkit_int(cmp2,0);
   checkit_int(cmp3,0);
}
void test_rotateLeft_0()
{
   Node *A;
   Node *B;
   Node *C;
   int cmp, cmp1, cmp2, cmp3;
   char s0[] = "A";
   char s1[] = "B";
   char s2[] = "C";
   A = new_node(s0,1);
   B = new_node(s1,1); 
   C = new_node(s2,1);
   insert(A,B);
   insert(B,C);
   B = rotateLeft(B,C);
   cmp = strcmp(B->left->word, s0);
   cmp1 = strcmp(B->right->word, s2);
   cmp2 = strcmp(B->left->parent->word, s1);
   cmp3 = strcmp(B->right->parent->word,s1);
   checkit_int(cmp,0);
   checkit_int(cmp1,0);
   checkit_int(cmp2,0);
   checkit_int(cmp3,0);
}
 
void test_rotateRightLeft_0()
{
   Node *A;
   Node *B;
   Node *C;
   int cmp, cmp1, cmp2, cmp3;
   char s0[] = "A";
   char s1[] = "B";
   char s2[] = "C";
   A = new_node(s0,1);
   B = new_node(s1,1); 
   C = new_node(s2,1);
   insert(A,C);
   insert(C,B);
   B = rotateRightLeft(C,B);
   cmp = strcmp(B->left->word, s0);
   cmp1 = strcmp(B->right->word, s2);
   cmp2 = strcmp(B->left->parent->word, s1);
   cmp3 = strcmp(B->right->parent->word, s1);
   checkit_int(cmp,0);
   checkit_int(cmp1,0);
   checkit_int(cmp2,0);
   checkit_int(cmp3,0);
}

void test_rotateLeftRight_0()
{
   Node *A;
   Node *B;
   Node *C;
   int cmp, cmp1, cmp2, cmp3;
   char s0[] = "A";
   char s1[] = "B";
   char s2[] = "C";
   A = new_node(s0,1);
   B = new_node(s1,1); 
   C = new_node(s2,1);
   insert(C,A);
   insert(A,B);
   B = rotateLeftRight(A,B);
   cmp = strcmp(B->left->word, s0);
   cmp1 = strcmp(B->right->word, s2);
   cmp2 = strcmp(B->left->parent->word, s1);
   cmp3 = strcmp(B->right->parent->word, s1);
   checkit_int(cmp,0);
   checkit_int(cmp1,0);
   checkit_int(cmp2,0);
   checkit_int(cmp3,0);
}


void test_rotate()
{
   test_rotateRight_0();
   test_rotateLeft_0();
   test_rotateRightLeft_0();
   test_rotateLeftRight_0();
}

void test_height_0()
{
  Node *A;
  char s0[] = "A";
  A = new_node(s0,1);
  insert(NULL, A);
  checkit_int(height(A),0);
}

void test_height_1()
{
   Node *A;
   Node *B;
   char s0[] = "a";
   char s1[] = "b";
   A = new_node(s0,1);
   B = new_node(s1,1);
   insert(NULL,A);
   insert(A,B);
   checkit_int(height(A),1);
   checkit_int(height(B),0);
}

void test_balance_factor_0()
{
   Node *A;
   Node *B;
   Node *C;
   char s0[] = "a";
   char s1[] = "b";
   char s2[] = "c";
   A = new_node(s0,1);
   B = new_node(s1,1);
   C = new_node(s2,1);
   insert(NULL,A);
   insert(A,B);
   insert(B,C);
   checkit_int(balance_factor(A), 2);
   checkit_int(balance_factor(B), 1);
   checkit_int(balance_factor(C), 0);

}


void test_balance_factor()
{
   test_balance_factor_0();
}


void test_height()
{
   test_height_0();
   test_height_1();
}

int main()
{
   test_insert();
   test_rotate();
   test_height();
   test_balance_factor();
   return 0;
}
