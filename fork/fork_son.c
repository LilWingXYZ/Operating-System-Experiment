# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{
   int number;
   if ((number = fork())<0)
   {  printf("Son Create Wrong!\n");
       return;
   }
  else if (number==0)
  {   printf("I am Son!\n");
      return;
  }
  else
  {  printf("I am Dad!\n");
  }
}
