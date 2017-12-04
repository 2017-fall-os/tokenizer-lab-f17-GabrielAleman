#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "mytoc.h"

int wordCounter(char * string,char delim){//works
  int counter = 0;
  int looper = 0;
  if((string[looper]!='\n') && string[looper] != '\0' && string[looper] != delim){//needed to add first word ifs its the first on string
    counter++;
  }
  while(string[looper]!='\n' && string[looper]!='\0'){
      if(string[looper] == delim){
      int temp = looper + 1;
      if(string[temp] != '\n' && string[temp]!= '\0' && string[temp] != delim){//checks for multiple spaces
	counter++;
      }
    }
    looper++;
  }
  return counter;
}

char ** mytoc(char * string,char delim){
  char ** wordArray;
  int words = wordCounter(string,delim);
  wordArray = malloc(words*sizeof(char *)+1);
  wordArray = lengthOfWord(string,wordArray,delim);
  return wordArray;
}

void freeMem(char * string, char ** wordArray,char delim){
  int words = wordCounter(string,delim);
  int counter = 0;
   while(counter != words){
     printf("mem free %x %s\n",wordArray[counter],wordArray[counter]);
    free(wordArray[counter]);
    counter++;
    }
   printf("mem free %x\n",wordArray);
  free(wordArray);
}

char ** lengthOfWord (char * string,char ** wordArray,char delim){//allocates memory for each word and places the word in the memeory
  int length = 0;
  int loop = 0;
  int wordStart = 0;
  int inserter = 0;
  
  while(string[loop] != '\n' && string[loop] != '\0'){
    if(string[loop] != delim && string[loop]!='"'){
      length++;
    }
    else{
      if(length != 0){
	int temploop = 0;
	wordArray[inserter] = malloc(length+1);
	while(temploop != length){
	  
	  wordArray[inserter][temploop] = string[wordStart];
	  temploop++;
	  wordStart++;
	}
	wordArray[inserter][temploop] = '\0';
	inserter++;
      }
      
      wordStart = loop+1;
      length = 0;
    }
    if(length != 0 && string[loop+1] == '\n' || string[loop+1] == '\0'){
      int temploop = 0;
      wordArray[inserter] = malloc(length+1);
      while(temploop != length){
	wordArray[inserter][temploop] = string[wordStart];
	temploop++;
	wordStart++;
      }
      wordArray[inserter][temploop] = '\0';
      inserter++;     
    }
    loop++;
  }
  
  return wordArray;
}

 

void printArray(char * string, char ** wordArray,char delim){
  int words = wordCounter(string,delim);
  int counter = 0;
  while(counter != words){
    printf("%s mem location = %x\n",wordArray[counter],wordArray[counter]);
    counter++;
  }
}

