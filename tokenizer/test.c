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
  int loop = 1;
  char delim  [1];
  char notice [] = "pick Delim\n";
  write(1,notice,11);
  read(0,delim,1);
  
  char string []= "type 'exit'to exit\n";
  write(1,string,19);
  while(loop){
    char a []= "$";
    write(1,a,2);
    read(0,temp,100);
    loop = compareString(temp);
    array = mytoc(temp,delim[0]);
    printArray(temp,array,delim[0]);
    freeMem(temp, array,delim[0]);
  }
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

int compareString(char * string){
  int loop = 0;
  int compare = 0;
  char terminator [] = "exit";
  while(string[loop] != '\n' && loop < 4){
    if(string[loop] == terminator[loop]){
      compare++;
    }
    loop++;
  }
  if(compare == 4){
    return 0;
  }
  else{
    return 1;
  }
}
    
     
