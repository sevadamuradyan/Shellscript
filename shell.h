#include <iostream>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>


#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 100
#define TOK_DELIM " "

char * readLine();
char** splitLine(char*);
int execute(char**);
void inf_loop();
