#include "shell.h"

char* readLine()
{
 int bufferSize = BUFFER_SIZE;
 int i = 0;
 char* buffer =(char*) malloc(sizeof(char) * BUFFER_SIZE);
 int c;
 if(!buffer)
 {
  std::cout<<"Not allocated the memory\n";
  exit(EXIT_FAILURE);
 }
 while(true)
  {
  c = getchar();
  if(c == EOF || c == '\n')
  {
   buffer[i] = '\0';
      return buffer;
  }

 else
  buffer[i] = c;
 ++i;
 if(i >= bufferSize)
  {
   bufferSize +=1024;
   buffer = (char*) realloc(buffer,bufferSize);
   if(!buffer)
    {
     std::cout<<"Not allocated the memory";
     exit(EXIT_FAILURE);
    }
  }
 }

}
char** splitLine(char* line)
{
 if(line == NULL)
 {
  std::cout<<"eror";
  return NULL;
 }
 int tokSize = TOK_BUFFER_SIZE,position = 0;
 char tokens =(char) malloc( sizeof(char*)* tokSize);
 char* token;
 if(!tokens)
  {
   std::cout<<"Not allocated the memory";
   exit(EXIT_FAILURE);
  }
  token = strtok(NULL,TOK_DELIM);
  while(token != NULL)
  {
   tokens[position] = token;
   position++;
   if(position >= tokSize)
   {
    tokSize+= 100;
    tokens = (char**) realloc(tokens,tokSize* sizeof(char*));
   if(!tokens)
   {
    std::cout<<"Not allocated the memory";
    exit(EXIT_FAILURE);
   }
  }
   token = strtok(NULL,TOK_DELIM);
 }
 tokens[position] = NULL;
 return tokens;
}
int execute(char** args)
{
 pid_t cpid;
 if(strcmp(args[0],"exit") == 0)
  return 0;
cpid = fork();
if(cpid == 0)
 {
  if(execvp(args[0],args)< 0)
  {
   std::cout<<"commande not fount %s\n",args[0]);
   exit(EXIT_FAILURE);
  }
 }
else if(cpid < 0)
{
 std::cout<<"forking eror";
}
else
 wait(&cpid);
return 1;
}
void inf_loop()
{
 char* line;
 char** args;
 int status = 1;
 do
 {std::cout<<">";
 line = readLine();
 args = splitLine(line);
 status = execute(args);
 free(line);
 free(args);
}
while(status);
}