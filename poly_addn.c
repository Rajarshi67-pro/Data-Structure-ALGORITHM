#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
    int coeff;
    int exp;
    struct polynomial* next;
}poly;
poly* insert(poly *s,poly *temp)
{
     poly *ptr;
     if(s==NULL)
     s=temp;
     else
     {
        ptr=s;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=temp;
     }
     return s;
}
void display(poly *s)
{
    poly *ptr=s;
    while(ptr->next!=NULL)
    {
       printf("%dx^%d + ",ptr->coeff,ptr->exp);
       ptr=ptr->next;
    }
    printf(" %dx^%d \n",ptr->coeff,ptr->exp);
}
poly* add(poly *s1,poly *s2,poly *s3)
{
      poly *temp;
      while(s1!=NULL && s2!=NULL)
      {
          temp=(poly *)malloc(sizeof(poly));
          if(s1->exp>s2->exp)
          {
               temp=(poly *)malloc(sizeof(poly));
               temp->exp=s1->exp;
               temp->coeff=s1->coeff;
               temp->next=NULL;
               s3=insert(s3,temp);
               s1=s1->next;
               //free(temp);
          }
          else if(s1->exp<s2->exp)
          {
               temp=(poly *)malloc(sizeof(poly));
               temp->exp=s2->exp;
               temp->coeff=s2->coeff;
               temp->next=NULL;
               s3=insert(s3,temp);
               s2=s2->next;
               //free(temp);
          }
          else
          {
               temp=(poly *)malloc(sizeof(poly));
               temp->exp=s2->exp;
               temp->coeff=s2->coeff+s1->coeff;
               temp->next=NULL;
               s3=insert(s3,temp);
               s2=s2->next;
               s1=s1->next;
               //free(temp);
          }
      }
      if(s1==NULL)
        s3=insert(s3,s2);
      else
        s3=insert(s3,s1);
      return s3;
}
int main()
{
   poly *s1,*s2,*temp,*s3;
   s1=NULL;
   s2=NULL;
   s3=NULL;
   int n,m,i;
   printf("Enter Number of Elements in first expression : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       temp=(poly *)malloc(sizeof(poly));
       printf("Enter coefficient : ");
       scanf("%d",&temp->coeff);
       printf("Enter Exponent : ");
       scanf("%d",&temp->exp);
       s1=insert(s1,temp);
   }
   printf("Enter Number of Elements in second expression : ");
   scanf("%d",&m);
   for(i=0;i<m;i++)
   {
       temp=(poly *)malloc(sizeof(poly));
       printf("Enter coefficient : ");
       scanf("%d",&temp->coeff);
       printf("Enter Exponent : ");
       scanf("%d",&temp->exp);
       s2=insert(s2,temp);
     }   
   printf("First expression : ");
   display(s1);
   printf("Second expression : ");
   display(s2);
   s3=add(s1,s2,s3);
   printf("Polynomial after adding : ");
   display(s3);
   return 0;
}
      
    
