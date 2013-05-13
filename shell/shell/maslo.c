#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>


#define true 1;


void program_run (int argc,char** argv)
{
	char** arguments=(char**) malloc ((argc-1)*sizeof(char*));
	if (arguments==NULL)
	{
		fprintf(stderr,"I can not give you such amount of memory");
	} 
	int i;
	for (i=0;i<argc-1;++i)
	{
		arguments[i]=argv[i+1];
	}
	execv(arguments[0],arguments);
	return 0;
}


void shall ();
{
	while (true)
	{
		printf ("\n$: ");
		getline (
		 
	}
}

int main (inr argc,char** argv)
{
	printf ("shell in shell");
	int i;
	shall();
	return 0;
}
