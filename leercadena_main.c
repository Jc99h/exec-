/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "LeerCadena.h"

int main(int argc, char *argv[]) 
{
  int cual=0;
  char *str[argc];
  
  for(cual; cual<argc; cual++)
  {
    str[cual]=argv[cual+1];
    if(cual+1==argc)
    {
      str[cual+1]=NULL;
    }
  }

  pid_t pid;
  pid = fork();
  if (pid < 0) {
    perror("No se pudo crear un proceso\n");
    exit(1);
  } else if (pid == 0) {
    execvp(str[0], str);
    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);
  } else {
    wait(NULL);
  }
  return 0;
}