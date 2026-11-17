
#include "pushswap.h"
#include<stdio.h>



/*t_list *stack_init(int argc, char **argv, int *len);

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
void selection_sort(Node *head_a, Node *head_b);*/
// void assign_index(Node *head_a) // o(N^2)
// {
//     if (!head_a)
//         return ;

// t_list *curr;
// t_list *curr2;

// curr = head_a->stack;
// curr2 = head_a->stack;
// int index;

// while(curr)
// {
//     index = 0;
//     curr2 = head_a->stack;
//     while(curr2)
//     {
//         if( (int)curr->content > (int)curr2->content)
//             index++;

//         curr2 = curr2->next;
//     }
//     curr->index = index;
//     curr = curr->next;
// }

// }

// t_list *second_peek(Node *head)
// {
//     if(!head)
//         return NULL ;

// return head->stack;

// }

// void bucket_sort(Node *head_a, Node *head_b)
// {
//     t_list *curr;
//     int peekval;
    
    
//    // curr = head_a->stack;
//      int i =0;
//     while(i < 20)
//     {
//            curr = second_peek(head_a) ;
//         if(curr->index < 20)
//         {
//          push_b(head_a, head_b);
//          i++;
//         }else{

//             rotate_a(head_a, head_b);
//         }



//     }



// }


// 100 5
// 500 11 


/// need a funtion that return number of chunks i should uses



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

//rotate_a(head_a, head_b);
 //print_stack(head_a); 
//print_stack(head_a);
//printf("the disorder metric %f", disorder_metric(head_a));
   
// selection_sort(head_a, head_b);
//  printf("after selection sort\n");
//     print_stack(head_a);

assign_index(head_a);

//  t_list *curr;

//  curr = head_a->stack;
// while(curr){

//    printf("the number %d index->%d\n", curr->content, curr->index);
//     curr = curr->next;
// }
//selection_sort(head_a, head_b);
head_b->len = 0;
bucket_sort(head_a, head_b);
 printf("after  buckket sort\n");
    print_stack(head_b);
//printf("the disorder metric %f", disorder_metric(head_a));
    return 0;
}

