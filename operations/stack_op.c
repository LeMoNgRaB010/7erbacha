#include "../pushswap.h"

t_list *stack_init(int argc, char **argv, int *len) // stack initialisation still need to add aparser i guess
 {
    int i = 0;
    int j =1;

    t_list *newnode =NULL;
    t_list *head = NULL;
    while (i < argc - 1)
    {
        newnode=ft_lstnew(ft_atoi(argv[j]));
        ft_lstadd_front(&head,newnode);
        (*len)++;
        i++;
        j++;
    }
   

    return head;

}

int peek(Node *head, int *content) 
{
    if(!head || !head->stack)
        return (0);
    *content =head->stack->content;
    return (1);

}



t_list *pop(Node *head){
    t_list *node;
    
    if (!head->stack)
        return (NULL);
    node= head->stack;
    head->len--;
    head->stack = head->stack->next;
    node->next= NULL; 
 return (node);
}

void push(Node *head, t_list *node)
{
    if(!head)
        return ;
    node->next = head->stack;
    head->stack = node;
    head->len++;
}


void print_stack(Node *head){ // for debugg purpuses
  
    t_list *curr = head->stack;
    while(curr)
    {
        printf("the node index :%d  node content %d\n", curr->index,curr->content);
        curr = curr->next;
    }

}

float disorder_metric(Node *head)
{
    int mistakes;
    int totalpair;
    int n;

    n = 0;
    t_list *curr;
    t_list *curr2;
    
    mistakes =0;
    totalpair = 0;
    if (!head || !head->stack || head->len < 2)
        return (0.0f);
    
    curr = head->stack;
    //n = curr->len;
    curr2 = curr->next;
    while(curr ){
          curr2=curr->next;
        while(curr2)
        {
            totalpair++;
            if(curr->content > curr2->content )
                mistakes++;
           curr2=curr2->next;
        }
        curr=curr->next;
    }

 return ((float)mistakes / totalpair);

}
