#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
  int val;
  struct nodes* next;
} node;

typedef struct tree_node
{
  int val;
  struct tree_node *left;
  struct tree_node *right;
} TreeNode;

int pop(node** head);
int push(node **head, int val);
int append(node *head, int val);
void traverse(node *head);
void pre_order(TreeNode *head);

void linked_list();
void binary_tree();

int main() {
  linked_list();
  binary_tree();

  return 0;
}

int pop(node** head) {
  if (*head == NULL) {
    return -1;
  }

  node* temp = (*head)->next;
  int retval = (*head)->val;
  free(*head);
  *head = temp;

  printf("pop %d\n", retval);
  return retval;
}

int push(node** head, int val) {
  node* temp;
  node* new_node = (node *)malloc(sizeof(node));

  new_node->val = val;
  new_node->next = *head;

  *head = new_node;

  printf("push %d\n", val);
  return val;
}

int append(node *head, int val) {
  if (head == NULL) {
    return -1;
  }

  while(head->next != NULL) {
    head = head->next;
  }

  node *new_node = (node *)malloc(sizeof(node));
  new_node->val = val;

  head->next = new_node;

  printf("append %d\n", val);
  return val;
}

void traverse(node *head) {
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
  node *head = (node *)malloc(sizeof(node));
  head->val = 1;

  node *new_node = (node *)malloc(sizeof(node));
  head->next = new_node;
  new_node->val = 8;

  node **p_head = (node **)malloc(sizeof(node));
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
