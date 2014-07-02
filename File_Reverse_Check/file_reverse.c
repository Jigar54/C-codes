//OS assignment question 1
/*input format:- argv[1] input file
  argv[2] output file
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int fr,pos;
	int fd;
	fr=open(argv[1], O_RDONLY );
	mkdir("Output",0700);		//making directory
	chdir("Output");	
	fd=creat(argv[2],0600);			//creating the new file
	long ctr,tmp;
	char *ch;
	pos=lseek(fr,0,SEEK_END);
	while(1)				//reading character by character and copying it in another file in reverse order
	{
		if (pos==-1)
			break;
		read(fr,&ch,1);
		write(fd,&ch,1);
		pos--;
		lseek(fr,pos,SEEK_SET);
	}
	return 0;
}

