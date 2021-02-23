# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{
   int i;
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
		 lockf(1,1,0);	 
	 	 for(i=0;i<10;i++) 
         printf("I am Grandson!(pid=%d)\n",getpid());
         lockf(1,0,0);
         return;
      }
      else
     {     
	 	   lockf(1,1,0);	 
	 	   for(i=0;i<10;i++) 
	 	   printf("I am Son!(pid=%d)\n",getpid());
	 	   lockf(1,0,0);
           return;
     }
  }
  else
  { 
  	lockf(1,1,0);
	for(i=0;i<10;i++) 
  	printf("I am Dad!\n");
  	lockf(1,0,0);
  }
}

