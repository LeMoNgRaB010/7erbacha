#include "libft/libft.h" 

typedef struct Node{
    int len;
    t_list *stack;
}Node;

t_list *stack_init(int argc, char **argv, int *len);

t_list *pop(Node *head);

int main(int argc, char **argv)
{
    Node *head= malloc(sizeof(Node));
    if(!head)
        return 0;
    head->stack = stack_init(argc,argv,&head->len);
 t_list *tmp =pop(head);
    printf("the content of the pop %d\n",tmp->content );

    return 0;
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

int peek(Node *head, int *content)
{
    if(!head || !head->stack)
        return (0);
    *content = &head->stack->content;
    return (1);

}

t_list *pop(Node *head){
    t_list *node;
    
    if (!head->stack)
        return (NULL);
    node= head->stack;
    head->len--;
    head->stack = head->stack->next; 
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