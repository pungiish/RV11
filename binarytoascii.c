#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[])
{
	int buff[8192]; // Buffer for reading into from a file.
	char *out = NULL;
	char *in = NULL;
	char *out_handle = NULL;
	char *in_handle = NULL;
	size_t elements_read;
	int st_argumentov = argc;
	int c;
	int index;
while ((c = getopt (argc, argv, "i:I:o:O:")) != -1)
    switch (c)
      {
      case 'o':
       	out = optarg;
        break;
      case 'i':
        in = optarg;
        break;
      case 'O':
        out_handle = optarg;
        break;
      case 'I':
        in_handle = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

		char curr_f[50];
		char append[50];
		strcpy(curr_f, "./");
		strcpy(append,out);
		strcat(curr_f,append);
		printf("%s\n",curr_f);

  printf ("out = %s, in = %s, out_h = %s, in_h = %s\n",
          out, in, out_handle, in_handle);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

	int fd = open(in,O_RDONLY);
	elements_read = read(fd,buff,(int)sizeof(buff));
	close(fd);
	printf("stevilo elementov v datoteki: %lu\n",elements_read);
	creat(curr_f,S_IRWXU);
	int fc = open(out,O_WRONLY);	
	
	for(int i=0;i<elements_read;i++)
	{
		printf("%i\n",buff[i]);
		write(fc,buff[i],strlen(buff[i])); // Use strlen instead of sizeof. Sizeof include null terminator.

	}
	if(out != NULL)
	{
		close(fc);
	}
	return 0;
}


