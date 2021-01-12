#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
  Small function for our threads to run.  Does nothing.
*/
void *do_nothing(void *ptr)
{
  sleep(10);
  return NULL;
}

int main()
{
  pthread_t do_nothing_thread;
  
  /* 
    Create a thread which executes do_nothing() 
  */
  if(pthread_create(&do_nothing_thread, NULL, do_nothing, NULL )) 
  {
    perror("Error creating thread: ");
    exit( EXIT_FAILURE ); 
  }
  
  if(pthread_join(do_nothing_thread, NULL)) 
  {
    perror("Problem with pthread_join: ");
  }
  return 0;
}
