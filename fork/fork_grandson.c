# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{
   int number1;
   int number2;
   if ((number1 = fork())<0)
   {  printf("Son Create Wrong!\n");
       return;
   }
  else if (number1==0)
  {   
      if ((number2 = fork())<0)
      {  printf("Grandson Create Wrong!\n");
         return;
      }
      else if (number2==0)
     {   

         printf("I am Grandson!\n");
         return;
      }
      else
     {     printf("I am Son!\n");
           return;
     }
  }
  else
  {  printf("I am Dad!\n");
  }
}

