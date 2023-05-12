#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60

struct line{
  char word[22];
  struct line *next;
};
int line_len = 0;
int num_words = 0;

struct line *lines = NULL;
struct line *lines_end = NULL;

void clear_line(void)
{
  struct line *temp = lines;
  struct line *dlt = NULL;
  while(temp != NULL){
    dlt = temp;
    temp = temp->next;
    free(dlt);
  }
  lines = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {
    {
      int len = strlen(lines_end->word);
      lines_end->word[len] = ' ';
      lines_end->word[len + 1] = '\0';
    }
    line_len++;
  }
  struct line *new_node = (struct line*) malloc(sizeof(struct line));
  new_node->next = NULL;
  strcpy(new_node->word, word);
  if(lines == NULL){
    lines = new_node;
    lines_end = lines;
  }
  else{
    lines_end->next = new_node;
    lines_end = new_node;
  }
  line_len += strlen(word);
  num_words++;
}
 
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, j;
  struct line *temp = lines;
 
  extra_spaces = MAX_LINE_LEN - line_len;
  for (; temp != NULL ; temp = temp->next){
    printf("%s", temp->word);
    if(strcmp(temp->word, " "))
    if(temp->next != NULL) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  struct line *temp = lines;
  if (line_len > 0)
    for (; temp != NULL; temp = temp->next){
      printf("%s", temp->word);
    }
}