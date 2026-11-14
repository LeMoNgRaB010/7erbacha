#include "../pushswap.h"

void swap_a(Node *head) 
{
    if ( !head ||  head->len < 2)
        return;
    t_list *tmp = pop(head);
    t_list *tmp2 =pop(head);
    push(head,tmp);
    push(head,tmp2);
   ft_putstr_fd("sa\n", 1);

}

void swap_b(Node *head)
{
    if ( !head || head->len < 2)
        return ;
    t_list *tmp = pop(head);
    t_list *tmp2 =pop(head);
    push(head,tmp);
    push(head,tmp2);
    ft_putstr_fd("sb\n", 1);
}

void swap_ss(Node *head_a, Node *head_b)
{
    swap_a(head_a);
    swap_b(head_b);
}

int push_a(Node *head_a, Node *head_b)
{
    t_list *node;

    node=pop(head_b);
    if (!node)
        return (0);
    push(head_a, node);
    ft_putstr_fd("pa\n", 1);
    return (1);
}

int push_b(Node* head_a,Node *head_b){

    t_list *node;

    node=pop(head_a);
    if (!node)
        return (0);
    push(head_b, node);
    ft_putstr_fd("pb\n",1);
    return (1);
}