#include "libft/libft.h" 

typedef struct Node{
    int len;
    t_list *stack;
}Node;



t_list *stack_init(int argc, char **argv, int *len); // need a parser for bad input 
void peek(t_list *head,int *content);
//t_list *stack_b(int argc);
void  *pop(t_list **head, int *len);
void push(t_list **head, int content, int *len);
void swap_a(t_list **stack_a, int *len);
void push_b(t_list **stack_b, int content, int *len);
void swap_ss(t_list **stack_a, t_list **stack_b, int *len_a, int *len_b);
int main(int argc, char **argv)
{

    Node *head_a =malloc(sizeof(Node));
    Node *head_b =malloc(sizeof(Node));
    head_b->len =0;
    head_b->stack=NULL;    
    head_a->len=0;
    head_a->stack= stack_init(argc,argv, &head_a->len);
    //&head_a->len = 0;
  //  t_list *stack_b =stack_b(argc);

   int n = 0;
   peek(head_a->stack, &n);
    printf("the last otem on the stack: %d\n",n);

 swap_a(&head_a->stack, &head_a->len);
   peek(head_a->stack, &n);
printf("the last otem on the stack: %d\n",n);
  printf("the len of the stack %d\n", head_a->len);

  pop(&head_a->stack, &head_a->len);
  printf("the len of the stack %d\n", head_a->len);
  peek(head_a->stack, &n);
  push_b(&head_b->stack, n, &head_b->len);
  peek(head_b->stack, &n);
   printf("the len of the stack b peek %d\n", n);
    peek(head_b->stack, &n);  
   push_b(&head_b->stack, n, &head_b->len);

    return  0;
}



t_list *stack_init(int argc, char **argv, int *len)
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





//stack 3oppirations

void peek(t_list *head, int *content)
{
    if(!head)
        *content = NULL;
    *content = head->content;

}

// void print_stack(t_list *head)
// {
//     while(head){

//         printf("%d" , head->content);
//         head =head->next;
//     }
// }

void del(void *content)
{

 content=NULL;
}

void  *pop(t_list **head, int *len)
{
    t_list *tmp= (*head)->next;
    ft_lstdelone(*head, del);
    *head = tmp;
    (*len)--;
    //return head;

}

void push(t_list **head, int content, int *len)
{
     (*len)++; 
     ft_lstadd_front(head,ft_lstnew(content));

}

void swap_a(t_list **stack_a ,int *len){ /// i shoudl add argument count  but just testing
      
    int tmp,tmp2;
    if (*len < 2)
        return;
    peek(*stack_a, &tmp);
    pop(stack_a, len);
    peek(*stack_a, &tmp2);
    pop(stack_a, len);
    push(stack_a, tmp, len);
    push(stack_a, tmp2,len);
}

void swap_b(t_list **stack_b ,int *len){ // swap_b ilka kan stack b ba3dak 
      
    int tmp,tmp2;
    if (*len < 2)
        return;
    peek(*stack_b, &tmp);
    pop(stack_b, len);
    peek(*stack_b, &tmp2);
    pop(stack_b, len);
    push(stack_b, tmp, len);
    push(stack_b, tmp2,len);
}

void swap_ss(t_list **stack_a, t_list **stack_b, int *len_a, int *len_b)
{
    swap_a(stack_a, len_a);
    swap_b(stack_b, len_b);
}
void push_a(t_list **stack_a, int content, int *len)
{
    push(stack_a, content,len);
}
void push_b(t_list **stack_b, int content, int *len)
{
    push(stack_b,content ,len);
}

/*void rotate_a(t_list *stack_a)
{



}*/