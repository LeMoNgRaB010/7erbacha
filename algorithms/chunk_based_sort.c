#include "../pushswap.h"
void assign_index(Node *head_a) // o(N^2)
{
    if (!head_a)
        return ;

t_list *curr;
t_list *curr2;

curr = head_a->stack;
curr2 = head_a->stack;
int index;

while(curr)
{
    index = 0;
    curr2 = head_a->stack;
    while(curr2)
    {
        if( (int)curr->content > (int)curr2->content)
            index++;

        curr2 = curr2->next;
    }
    curr->index = index;
    curr = curr->next;
}
}
int ft_sqrt(int n)
{
    int i = 0;
    while (i * i <= n)
        i++;
    return (i - 1);
}
t_list *second_peek(Node *head)
{
    if(!head)
        return NULL ;

return head->stack;

}

int pos_top(Node *head, int idx)
{
    int j;
    t_list *curr;

    j = 0;
    curr = head->stack;
    while (curr)
    {
        
    if(curr->index < idx )
        break;
    j++;
     curr= curr->next;
    }
 return (j);
}

int pos_bottom(Node *head, int idx)
{
    int j;
    int cost;
    t_list *curr;

    j = 0;
    cost = 0;
    curr = head->stack;
    while(curr)
    {
        if (curr->index < idx )
            cost = j;
        j++;
        curr = curr->next;
    }
    return (j - cost);
}

int exact_pos(Node *head, int idx)
{
    int i;
    t_list *curr;

    i =0;
    curr = head->stack;
    while(curr)
    {
        if(curr->index == idx )
            break;
        i++;
        curr = curr->next;
    }

    return (i);
}


void deviseinto_chunks(Node *head_a, Node *head_b)
{ 
    int chunk_s;
    int j; // number of chunks start from 1
    t_list *curr;
    int i;

    chunk_s = ft_sqrt(head_a->len);
    j = 1;
    i = 0; /// number of nodes pushed intehre chunks 
    curr = head_a->stack;
    while(head_a->len)
    {
        while(i < (j * chunk_s) && head_a->len)
        {
            curr = second_peek(head_a);
            if(curr->index < j * chunk_s)
            {
                
                push_b(head_a, head_b);
                i++;
            }else
            {
            if(pos_top(head_a, j*chunk_s) <= pos_bottom(head_a, j*chunk_s))
                rotate_a(head_a, head_b);
            else
                 reverse_rotate_a(head_a, head_b);
            }


        }
 
     j++;
    }
}

void bucket_sort(Node *head_a, Node *head_b )
{
   int n;
    t_list *curr;
    int pos;
    
    //int j = head_b->len / ft_sqrt(head_b->len);
deviseinto_chunks(head_a,head_b);
    n = head_b->len-1;   
    while(head_b->len)
    {
        pos = exact_pos(head_b, n);
        curr = second_peek(head_b);
      if(curr->index == n)
      {
        push_a(head_a, head_b);
        n--;
      }else{
   
        if(pos <= head_b->len-pos)
         rotate_b(head_a,head_b);
        else
        reverse_rotate_b(head_a, head_b);
      }
    }

    



}