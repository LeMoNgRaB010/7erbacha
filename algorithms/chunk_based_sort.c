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


 void bucket_sort(Node *head_a, Node *head_b)
{
    t_list *curr;
    int peekval;
    // 
    // 
   // curr = head_a->stack;
   printf("the the sqauer root len %d\n", ft_sqrt(head_a->len));
     int i =0;
     int jj = ft_sqrt(head_a->len);
     int j = jj;
     int n =  head_a->len;
    while(j){
    
    //i = 0; 
    int x =0;
    printf("the jj wich is the val of squar n %d\n", jj);
    while(i < (n/j))
    {
        x = n /j;
        printf("teh cunk range n / j %d\n", x);
           curr = second_peek(head_a) ;
        if(curr->index < n / j)
        {
         push_b(head_a, head_b);
          i++;
        }else{

            reverse_rotate_a(head_a, head_b);
        }


    }
      j--;
    }
   /*while(head_b->len)
    {
      
        push_a(head_a, head_b);

    }*/

}