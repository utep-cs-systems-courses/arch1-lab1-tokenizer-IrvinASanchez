#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char str[100];
  char i;
  char **tokens;
  char *list;
  List *history = init_history();

  printf("Welcome! \n");
  
  while(1){
    printf("1. Enter 's' to begin typing a sentance. \n2. Enter '!' followed by a number to display a certain sentance from history. \n3. Enter '!h' to display all recorded sentences so far. \n4. Enter 'q' to exit.\n");
    
    fgets(str, 100, stdin);
    i = str[0];

    switch(i){
    case 's':
      printf("Please enter a sentance:\n$");
      fgets(str, 100, stdin);
      add_history(history, str);
      tokens = tokenize(str);
      printf("\n");
      print_tokens(tokens);
      free_tokens(tokens);
      break;

    case '!':
      if(str[1] != 'h'){
	list = get_history(history, atoi(str+1));
	tokens = tokenize(list);
	printf("\n");
	print_tokens(tokens);
	free_tokens(tokens);
	break;
      }
      print_history(history);
      break;

    case 'q':
      printf("Have a great day! :) \n");
      free_history(history);
      return 0;

    default:
      printf("Sorry, that isn't a valid option, please try again. \n");
      break;
    }
  }
}
