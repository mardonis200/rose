#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

char fileName[40] = "";

int main() {
  
  int cwrite;
  int fd;
  int iws;
  int badcount = 0;
  char pwbuf[255];

  sprintf(fileName,"tfile_%d",getpid());

  for( iws = 0; iws < 254; iws++ ) {
    pwbuf[iws] = 'A' + (iws % 26);
  }
  pwbuf[255] = '\n';

  if( (fd = open(fileName, O_RDWR | O_CREAT, 0777)) == -1) {
    fprintf(stderr,"Can't open tempfile\n");
    abort();
  }

  for (iws = 254; iws > 0; iws--) {
    if( (cwrite = write(fd, pwbuf, iws) ) != iws ) {
      badcount++;
    }
  }

  if( badcount != 0 ) {
    fprintf(stderr, "write() failed to return proper count\n");
    abort();
  }

  return 0;
}
