#include "libft/libft.h" 
#include "pushswap.h"
#include<stdio.h>



/*t_list *stack_init(int argc, char **argv, int *len);

t_list *pop(Node *head);
int peek(Node *head, int *content);
void swap_a(Node *head);
void push(Node *head, t_list *node);
void rotate_a(Node *head_a, Node *head_b);
void rotate_b(Node *head_a, Node *head_b);
int push_b(Node* head_a,Node *head_b);
void print_stack(Node *head); /// debugggg
void reverse_rotate_a(Node *head_a, Node *head_b);
float disorder_metric(Node *head);
void selection_sort(Node *head_a, Node *head_b);*/

int main(int argc, char **argv)
{
    Node *head_a= malloc(sizeof(Node));
    Node *head_b =malloc(sizeof(Node));

    if(!head_a)
        return 0;
     head_a->stack = stack_init(argc,argv,&head_a->len);
   int n =0;
   //peek(head_a,&n);
    //printf("teh fisrt node : %d", n);
 printf("before\n");
    print_stack(head_a);
//everse_rotate_a(head_a,head_b);
printf("after rotation\n");
//rotate_a(head_a, head_b);
 //print_stack(head_a); 
//print_stack(head_a);
//printf("the disorder metric %f", disorder_metric(head_a));
   
selection_sort(head_a, head_b);
 printf("after selection sort\n");
    print_stack(head_a);
//printf("the disorder metric %f", disorder_metric(head_a));
    return 0;
}

