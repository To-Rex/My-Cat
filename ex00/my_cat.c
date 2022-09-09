#include <fcntl.h>	// for open() 
#include <stdio.h>	// for perror() 
#include <unistd.h>	// for read(), write(), close() 

int main( int argc, char *argv[] )
{
	int	i, fd, ch;	// declare local variables

	for (i = 1; i < argc; i++)
		{
		fd = open( argv[i], O_RDONLY );
		if ( fd < 0 ) { perror( argv[i] ); continue; }
		while ( read( fd, &ch, 1 ) == 1 ) 
			write( STDOUT_FILENO, &ch, 1 );
		close( fd );
		}
}