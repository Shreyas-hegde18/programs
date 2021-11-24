#include<stdio.h>
int count=0;
void main()
{
     int n;
     void tower(int,char,char,char);
      printf("Enter the no of discs:\n");
          scanf("%d",&n);
      tower(n,'A','B','C');
      printf("Total no disc moves: %d\n",count);
}
void tower(int n,char source,char temp,char desti)
{
    if(n==1)
    {
         printf("Move disc 1 from %c to %c\n",source,desti);
         count++;
         return;
    }
    //move n-1 discs from A to B using C as temproary peg
    tower(n-1,source,desti,temp);
     printf("Move disc %d from %c to %c\n",n,source,desti);
     count++;
    //move n-1 discs from B to C 
    tower(n-1,temp,source,desti);  
}

            