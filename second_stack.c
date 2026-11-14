#include "libft/libft.h" 
#include<stdio.h>

typedef struct Node{
    int len;
    t_list *stack;
}Node;

t_list *stack_init(int argc, char **argv, int *len);

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
void selection_sort(Node *head_a, Node *head_b);

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

void swap_a(Node *head)
{
    if ( !head ||  head->len < 2)
        return;
    t_list *tmp = pop(head);
    t_list *tmp2 =pop(head);
    push(head,tmp);
    push(head,tmp2);
   // return 1;

}
int swap_b(Node *head)
{
    if ( head->len < 1)
        return(0);
    t_list *tmp = pop(head);
    t_list *tmp2 =pop(head);
    push(head,tmp);
    push(head,tmp2);
    return 1;
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

void rotate_a(Node *head_a, Node *head_b) /// optimized
{
    t_list *node ;
    t_list *curr;
    int n =0;
    int n2 = 0;

    node = pop(head_a);
    n = head_a->len;
    node->next = NULL; 
    curr = ft_lstlast(head_a->stack); // O(N);
    curr->next =node;
    head_a->len++;  
    ft_putstr_fd("ra\n", 1);

}



void rotate_b(Node *head_a, Node *head_b) // i still didint testit copied rotate a wich works 
{
    t_list *node ;
    t_list *curr;
    int n =0;
    int n2 = 0;

    node = pop(head_b);
    n = head_b->len;
    while(n != 0)
    {
     if(push_a(head_a, head_b))
        printf("pushed b len : %d\n ", n);
    n2++;
     n--;        
    }
    push(head_b, node);
    //n = head_a->len;
    while(n2 != 0)
    {
     if(push_b(head_a, head_b))
        printf("pushed b len : %d\n ", n);
     n2--;        
    }

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
void reverse_rotate_rrr(Node *head_a, Node *head_b){
    reverse_rotate_a(head_a,head_b);
    reverse_rotate_b(head_a, head_b);
}

void print_stack(Node *head){
  
    t_list *curr = head->stack;
    while(curr)
    {
        printf("the node :%d\n", curr->content);
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