#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h>
void char_at_a_time( const char * str ) { 
  while( *str!= '\0' ) { 
    putchar( *str++ );   // Write a char and increment the pointer
    fflush( stdout );    // Print out immediately (no buffering)
    usleep(50); 
  } 
} 
int main() { 
  if( fork() == 0 ) 
    char_at_a_time( "............." ); 
  else
    char_at_a_time( "|||||||||||||" ); 
}