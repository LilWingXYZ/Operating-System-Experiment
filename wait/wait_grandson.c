# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
   pid_t number1;
   pid_t number2;
   int status1,i1;
   int status2,i2;
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

         printf("I am Grandson! pid = %d\n",getpid());
         exit(250);
      }
      else
     {    
           sleep(1);
	 	   printf("I am Son! pid = %d. wait for grandson...\n",getpid());
	 	   number2 = wait(&status2);
  		   i2=WEXITSTATUS(status2);
  		   printf("grandson's pid = %d. exit status=%d\n",number2,i2);
           exit(520);
     }
  }
  else
  { 
  	sleep(1); 
  	printf("I am Dad! wait for son...\n");
  	number1 = wait(&status1);
  	i1=WEXITSTATUS(status1);
  	printf("son's pid = %d. exit status=%d\n",number1,i1);
  }
}

