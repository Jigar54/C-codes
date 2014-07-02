//OS assignment question 2
/*Input format:-argv[1] is the source file name 
  argv[2] is the destination file name
 */

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int fr,ans;
	int fd;
	struct stat sb;
	if (stat("Output",&sb) == 0)						//check whether directory exists or not
	{
		if (S_ISDIR(sb.st_mode))
		{
			fr=open(argv[1], O_RDONLY);
			chdir("Output");
			ans=access(argv[2],F_OK);					//checking whether file exists or not
			if(ans==0)
			{
				char arr1[]="Check whether file created or not: Yes\n";	
				write(1,arr1,sizeof(arr1)-1);				//to print in stdout without using printf
			}
			else
			{
				char arr2[]="Check whether file created or not: No\n";
				write(1,arr2,sizeof(arr2)-1);
			}
			fd=open(argv[2], O_RDONLY);					//system call to open file
			int tmp;
			int ctr,ctr1;
			tmp=0;
			char ch;
			char ch1;
			ctr=lseek(fr,0,SEEK_END);					//to move the file pointer	
			ctr1=ctr;
			ctr--;
			while(1)							//check whether file is reversed or not
			{
				read(fr,&ch,1);
				read(fd,&ch1,1);
				if (ch==ch1)
				{
					tmp++;
				}
				lseek(fr,ctr,SEEK_SET);
				if (ctr==-1)
					break;
				ctr--;
			}
			if (ctr1==tmp)
			{
				char arr3[]="Check whether file reversed or not: Yes\n";
				write(1,arr3,sizeof(arr3)-1);
			}
			else 
			{
				char arr4[]="Check whether file reversed or not: No\n";
				write(1,arr4,sizeof(arr4)-1);
			}
			if (access(argv[2],R_OK | W_OK)!=0)				//checking users read and write permissions!
			{	
				char arr5[]="Check whether user access only: No\n";
				write(1,arr5,sizeof(arr5)-1);
			}
			else
			{
				char arr6[]="Check whether user access only: Yes\n";
				write(1,arr6,sizeof(arr6)-1);
			}	
		}
	}
	else 									//if directory doesnt exist
	{
		char arr2[]="Check whether file created or not: No\n";
		write(1,arr2,sizeof(arr2)-1);
		char arr4[]="Check whether file reversed or not: No\n";
		write(1,arr4,sizeof(arr4)-1);
		char arr5[]="Check whether user access only: No\n";
		write(1,arr5,sizeof(arr5)-1);
	}
	return 0;
}

