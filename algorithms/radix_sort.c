#include "../pushswap.h" 

void radix_sort(Node *head_a, Node *head_b,int shift)
{
    
   // assign_index(head_a); // O(N^2) l7wwa ya wlidi 
    int i;
    t_list *curr;
    int size= head_a->len;  
 
    i =0;
    while(i < size)
    {
        curr = second_peek(head_a);
        if(curr->index & 1 << shift){
            rotate_a(head_a, head_b);
        }else{   
            push_b(head_a, head_b);
        }
         i++;   
    }
    shift++;
    while(head_b->len)
        push_a(head_a, head_b);
    if(disorder_metric(head_a) != 0.0f)
        radix_sort(head_a, head_b, shift);


 
}