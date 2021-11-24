#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coeff;
    int expo;
    struct Node *link;
};
typedef struct Node node;
void main()
{
    node *head1,*head2,*head3;
    node *read_poly(node *);
    node *add_poly(node *,node *,node*);
    void display(node *);
    node *attach(int,int,node *);
    
    head1=(node *)malloc(sizeof(node));
    head2=(node *)malloc(sizeof(node));
    head3=(node *)malloc(sizeof(node));
    
    head1->link=head1;
    head2->link=head2;
    head3->link=head3;

    printf("Enter the first poly\n");
     head1=read_poly(head1);
    printf("Enter the second poly\n");
     head2=read_poly(head2);
    head3=add_poly(head1,head2,head3);

    printf("displaying the first poly\n");
      display(head1);
    printf("displaying the second poly\n");
      display(head2);
    printf("displaying the resultant poly\n");
      display(head3);     
}
node *read_poly(node *head)
 {
     int coeff,expo,i=1;
     node *attach(int,int,node *);
     printf("Type -111 to stop the pgm\n");
     while(1)
     {
            printf("Enter %d term\n",i++);
            printf("Coeff :");
             scanf("%d",&coeff);
            if(coeff==-111)
             break; 
            printf("Expo :");
             scanf("%d",&expo);
            head=attach(coeff,expo,head);
      }
     return head; 
}
node *attach(int coeff,int expo,node *head)
{
    node *nw,*cur;
    nw=(node *)malloc(sizeof(node));
    nw->coeff=coeff;
    nw->expo=expo;
    
    cur=head->link;
    while(cur->link!=head)
       cur=cur->link;
    cur->link=nw;
    nw->link=head;   
  return head;  
}           
node *add_poly(node *head1,node *head2,node *head3)
{
   int coeff;
   node *a,*b;
   int compare(int,int);
   a=head1->link;
   b=head2->link;
    while(a!=head1 && b!=head2)
    {
      switch(compare(a->expo,b->expo))
       {
         case 0:
            coeff = a->coeff + b->coeff;
            if(coeff!=0)
              head3=attach(coeff,a->expo,head3);
            a=a->link;
            b=b->link;
          case 1:
             head3=attach(a->coeff,a->expo,head3);
             a=a->link;
          default:
             head3=attach(b->coeff,b->expo,head3);
             b=b->link;
       }
    }
    while(a!=head1)
    {
      head3=attach(a->coeff,a->expo,head3);
      a=a->link;
    }  
    while(b!=head2)
    {
      head3=attach(b->coeff,b->expo,head3);
      b=b->link;
    }                
    return head3;
} 
int compare(int a,int b)
{
  if(a==b)
    return 0;
  else if(a>b)
     return 1;
  else 
     return -1;   
}
void display(node *head)
{
  node *temp;
  if(head->link==head)
   {
     printf("List is not created\n");
     return;
   }  
   temp=head->link;
  while(temp!=head)
  {
    if(temp->coeff<0)
      printf("%2d x^ %2d",temp->coeff,temp->expo);
    else
      printf("+%2d x^ %2d",temp->coeff,temp->expo);  
    temp=temp->link;
  }
  printf("\n");
} 



 


