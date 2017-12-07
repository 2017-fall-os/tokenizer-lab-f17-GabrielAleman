#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mytoc.h"
#include "test.h"

int main(){
  char ** array;
  char temp [100];
  char string1 [] = "Hello my dog's name is Darwin\n";
  char string2 [] = "   Hello  World    \n";
  char string3 [] = "\n";
  char string4 [] = "         \n";
  char string5 [] = " HelloWorld\n";
  array = mytoc(string1,' ');
  printArray(string1,array,' ');
  freeMem(string1,array,' ');
  printf("\n");
  
  array = mytoc(string2,' ');
  printArray(string2,array,' ');
  freeMem(string2,array,' ');
  printf("\n");
  
  array = mytoc(string3,' ');
  printArray(string3,array,' ');
  freeMem(string3,array,' ');
  printf("\n");
  
  array = mytoc(string4,' ');
  printArray(string4,array,' ');
  freeMem(string4,array,' ');
  printf("\n");
  
  array = mytoc(string5,' ');
  printArray(string5,array,' ');
  freeMem(string5,array,' ');
  
}


    
     
