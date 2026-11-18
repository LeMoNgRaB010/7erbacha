#include "../pushswap.h"

void rotate_a(Node *head_a, Node *head_b) /// optimized
{
    t_list *node ;
    t_list *curr;
    int n =0;
    int n2 = 0;

    node = pop(head_a); // 0(1)a w9
    n = head_a->len;
    node->next = NULL; 
    curr = ft_lstlast(head_a->stack); // O(N); mkyn la satck la 9lawi
   curr->next =node;
    head_a->len++;  
    ft_putstr_fd("ra\n", 1);

}

void rotate_b(Node *head_a, Node *head_b) /// optimized
{
    t_list *node ;
    t_list *curr;
    int n =0;
    int n2 = 0;

    node = pop(head_b); // 0(1)a w9
    n = head_b->len;
    node->next = NULL; 
    curr = ft_lstlast(head_b->stack); // O(N); 
   curr->next =node;
    head_b->len++;  
    ft_putstr_fd("rb\n", 1);

}

void rotate_rr(Node *head_a, Node *head_b){
     rotate_a(head_a, head_b);
      rotate_b(head_a, head_b);
} 
void reverse_rotate_a(Node *head_a, Node *head_b){

    t_list *node;
    int n ;
    int n2;      /// hadi 9aleb khasna ndiro rabha f koulchi
    
    n2 = 0;
    n = head_a->len;
    while(n !=1)
    {
        push_b(head_a, head_b);
        n2++;
      n--;
    } 
    node = pop(head_a);
    //n = head_b->len;
    while(n2 !=0)
    {
        push_a(head_a, head_b);
        n2--;
    }
    push(head_a,node);
        ft_putstr_fd("rra\n", 1);
}

void reverse_rotate_b(Node *head_a, Node *head_b){

    t_list *node;
    int n ;
    int n2;      /// hadi 9aleb khasna ndiro rabha f koulchi
    
    n2 = 0;
    n = head_b->len;
    while(n !=1)
    {
        push_a(head_a, head_b);
        n2++;
      n--;
    } 
    node = pop(head_b);
    //n = head_b->len;
    while(n2 !=0)
    {
        push_b(head_a, head_b);
        n2--;
    }
    push(head_b,node);
}
/// norminette at7wini
void reverse_rotate_rrr(Node *head_a, Node *head_b){
    reverse_rotate_a(head_a,head_b);
    reverse_rotate_b(head_a, head_b);
}
