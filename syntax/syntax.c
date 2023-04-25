#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} Node;

typedef struct tree_node
{
  int val;
  struct tree_node *left;
  struct tree_node *right;
} TreeNode;

int pop(Node** head);
int push(Node **head, int val);
int append(Node *head, int val);
void traverse(Node *head);
void pre_order(TreeNode *head);

void linked_list();
void binary_tree();

typedef struct mystruct {
  int i;
  float f;
  char c;
} MyStruct;

typedef union myunion {
  int i;
  float f;
  char c;
} MyUnion;

void union_vs_struct();

int main() {
  linked_list();
  binary_tree();
  union_vs_struct();

  return 0;
}

int pop(Node** head) {
  if (*head == NULL) {
    return -1;
  }

  Node* temp = (*head)->next;
  int retval = (*head)->val;
  free(*head);
  *head = temp;

  printf("pop %d\n", retval);
  return retval;
}

int push(Node** head, int val) {
  Node* temp;
  Node* new_node = (Node *)malloc(sizeof(Node));

  new_node->val = val;
  new_node->next = *head;

  *head = new_node;

  printf("push %d\n", val);
  return val;
}

int append(Node *head, int val) {
  if (head == NULL) {
    return -1;
  }

  while(head->next != NULL) {
    head = head->next;
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->val = val;

  head->next = new_node;

  printf("append %d\n", val);
  return val;
}

void traverse(Node *head) {
  while (head != NULL) {
    if (head->next == NULL) {
      printf("%d\n", head->val);
    } else {
      printf("%d->", head->val);
    }

    head = head->next;
  }
}

void pre_order(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  pre_order(root->left);
  printf("%d ", root->val);
  pre_order(root->right);
}

void linked_list() {
  Node *head = (Node *)malloc(sizeof(Node));
  head->val = 1;

  Node *new_node = (Node *)malloc(sizeof(Node));
  head->next = new_node;
  new_node->val = 8;

  Node **p_head = (Node **)malloc(sizeof(Node));
  *p_head = head;
  traverse(*p_head);

  pop(p_head);
  traverse(*p_head);

  push(p_head, 2);
  traverse(*p_head);

  push(p_head, 5);
  traverse(*p_head);

  append(*p_head, 9);
  traverse(*p_head);

  printf("\n");
}

void binary_tree() {
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->val = 1;
  TreeNode *node_right = (TreeNode *)malloc(sizeof(TreeNode));
  node_right->val = 2;
  TreeNode *node_left = (TreeNode *)malloc(sizeof(TreeNode));
  node_left->val = 3;

  root->right = node_right;
  root->left = node_left;
  node_left->left = (TreeNode *)malloc(sizeof(TreeNode));
  node_left->left->val = 9;

  pre_order(root);

  printf("\n");
}

void union_vs_struct() {
  printf("struct size: %lu\n", sizeof(MyStruct));
  printf("union size: %lu\n", sizeof(MyUnion));

  MyStruct *my_struct;
  my_struct->i = 1;
  my_struct->f = 1.23;
  my_struct->c = 'J';

  MyUnion *my_union;
  my_union->i = 1;
  my_union->f = 1.23;
  my_union->c = 'J';

  printf("my_struct -- i: %d, f: %f, c: %c\n", my_struct->i, my_struct->f, my_struct->c);
  printf("my_union -- i: %d, f: %f, c: %c\n", my_union->i, my_union->f, my_union->c);
}
