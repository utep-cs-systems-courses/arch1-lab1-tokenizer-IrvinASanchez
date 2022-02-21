#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// return pointer to space character after word
char *word_terminator(char *word){
  int i = 0;
  while(*(word + i)){
    if(space_char(*(word + i))){
	  return word + i;
      }
      i++;
  }
  return word + i;	
}

// return pointer to start of word
char *word_start(char *str){
  int i = 0;
  while(*(str+i)){
    if(non_space_char(*(str + i))){
	  return str+i;
      }
	i++;
  }
  return str + i;
}

// return the number of words in the string
int count_words(char *str){
  char *temp = str;
  temp = word_start(temp);
  int i = 0;
  int count = 0;
  while(non_space_char(*temp)){
    if (*temp == '\0'){
      return count;
    }
    count++;
    temp = word_terminator(temp);
    temp = word_start(temp);
  }
  return count;
}

int space_char(char c){
  return (( c == ' ' || c == '\t') && c != '\0'); // checks if c is space or tab 
}

int non_space_char(char c){
  return (c != ' ' && c != '\t' && c != '\0'); // checks if c is not a space or tab or new line
}

// return copied string from user input
char *copy_str(char *inStr, short len){
  char *copyStr = malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i < len; i++){
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;
}

//return the length of a word
int word_length(char *str){
  char *tempS = word_start(str);
  char *tempE = word_terminator(tempS);
  int len = 0;
  len = tempE - tempS;
  return len;
}

// return double pointer of tokenized string
char **tokenize(char *str){
  int words = count_words(str);
  char **tokens = malloc((words+1) * sizeof(char *));
  int i;
  int len;
  for(i = 0; i < words; i++){
    str = word_start(str);// find start of word
    len = word_length(str);// get the length
    tokens[i] = copy_str(str, len);// copy word to tokens
    str = word_terminator(str);// move pointer to word terminator
  }
  tokens[i] = '\0'; // end with terminator
  return tokens;
}

// prints tokens from double pointer tokenized string
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    printf("Token[%d] = %s\n", i, tokens[i]);
    i++;   
  }
}

// free token memory
void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
