#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h> 
#include<string.h>
int main()
{
        int pid;
        char str[50]="is sending a message to parent!";
        char buf[1000];
        int filedes[2];
        int r,w;
        pipe(filedes);
        if((pid=fork())<0)
        {
                printf("Son fail creat!\n");
                return 0;
        }
        else if (pid==0)
        {
        	printf ("Tn the son's process!\n");
        	
        	close(filedes[0]);//关闭读端
        	w=write(filedes[1],str,strlen(str));//写数据
			
			return 0;
		}
        else
        {
        		printf("In the father's process!\n");
        		close(filedes[1]);//关闭写端
  				r=read(filedes[0],buf,sizeof(buf));//读数据
                if(r>0)
                printf("%d bytes of data received from child:\n%s\n",r,buf);
                return 0;
        }
        return 0;     
}
