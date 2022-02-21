#include <stdio.h>
#include "malloc.h"
#include "history.h"
#include "tokenizer.h"

// initialize history
List *init_history(){
  List *list = malloc(sizeof(List));
  (*list).root = malloc(sizeof(Item));
  return list;
}

// return length of string
int str_length(char *str){
  short len = 0;
  int i;
  for(i = 0; *(str+i) != '\0'; i++){
    len++;
  }
  return len;
}

// add string to history
void add_history(List *list, char *str){
  Item *newStr = malloc(sizeof(Item));
  (*newStr).str = copy_str(str, str_length(str));
  if((*(*list).root).str == NULL){ // check if head is empty
    (*newStr).id = 1;
    (*list).root = newStr;
  }
  // find the next spot
  else{
    int position = 2; // variable to keep track of next insert position
    Item *temp = (*list).root;
    while((*temp).next){
      temp = (*temp).next;
      position++;
    }
    (*newStr).id = position;
    (*temp).next = newStr;
  }
}

// returns stored strings from given id position
char *get_history(List *list, int id){
  Item *temp = (*list).root;
  if((*temp).str == NULL){ // check if history is empty
    printf("History is empty, try typing some sentances first. \n");
    return "";
  }
  while(temp != NULL){
    if((*temp).id == id){
      return (*temp).str;
    }
    temp = (*temp).next;
  }
  printf("There is no history saved at that inputted id.");
  return "";
}

// prints all strings stored in history
void print_history(List *list){
  Item *temp = (*list).root;
  if(temp == NULL){
    printf("History is empty. \n");
  }
  else{
    while(temp != NULL){
      printf("%d: %s", (*temp).id, (*temp).str);
      temp = (*temp).next;
    }
    printf("\n");
  }
}

// free memory of history
void free_history(List *list){
  Item *temp;
  Item *head = (*list).root;
  while(head){
     temp = head;
     head = (*head).next;
     free(temp);
   }
  free(list);
}
