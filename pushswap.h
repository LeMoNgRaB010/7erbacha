#ifndef PUSHSWAP_H
#define PUSHSWAP_H
#include "libft/libft.h" 
#include<stdio.h>
typedef struct Node{
    int len;
    t_list *stack;
}Node;
// stack op
t_list *stack_init(int argc, char **argv, int *len);
t_list *pop(Node *head);
int peek(Node *head, int *content);
void push(Node *head, t_list *node);
void print_stack(Node *head);
float disorder_metric(Node *head);
/////

/// algo_op
void swap_a(Node *head);
void swap_b(Node *head);
void swap_ss(Node *head_a, Node *head_b);
int push_a(Node *head_a, Node *head_b);
int push_b(Node* head_a,Node *head_b);
/////

// algo rotations
void rotate_a(Node *head_a, Node *head_b);
void rotate_b(Node *head_a, Node *head_b);
void rotate_rr(Node *head_a, Node *head_b);
void reverse_rotate_a(Node *head_a, Node *head_b);
void reverse_rotate_b(Node *head_a, Node *head_b);
void reverse_rotate_rrr(Node *head_a, Node *head_b); //balek norminette
///

// simple algo
void selection_sort(Node *head_a, Node *head_b);

void assign_index(Node *head_a);
 //void bucket_sort(Node *head_a, Node *head_b);
void deviseinto_chunks(Node *head_a, Node *head_b);
void bucket_sort(Node *head_a, Node *head_b );
t_list *second_peek(Node *head);
void radix_sort(Node *head_a, Node *head_b,int shift);
#endif