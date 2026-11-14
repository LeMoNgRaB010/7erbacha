#include "../pushswap.h"

void selection_sort(Node *head_a, Node *head_b)
{
    //while(disorder_metric(head) != 0.0f)
   
    t_list *curr =NULL;
    int n =0;
    int peekval = 0;
  
   while(head_a->len > 1) // O(N)
   {
     curr = head_a->stack;
        n = curr->content ;
    while(curr) // o(N) /// i shoudl create a helper function that return the smalest khorza
    {
        if(n > (int)curr->content)
            n = curr->content;
        curr = curr->next;
    }
       peek(head_a,&peekval); // O(1);
    while(peekval != n)  // O(N)
    { 
        rotate_a(head_a, head_b); // O(N)
        peek(head_a, &peekval); //O(1)
        //printf("teh peek val %d\n", peekval);
    }
     push_b(head_a, head_b);
   }
   int n2 = head_b->len;
   while(n2--) //O(N)
   {
    push_a(head_a,head_b);
   }
    
}