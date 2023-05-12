#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60

// char line[MAX_LINE_LEN+1];
struct line{
    char *words;
    int char_cnt;
    struct line *next;
};
int line_len = 0;
int num_words = 0;
struct line *lines = NULL;

void clear_line(void)
{
    if(lines == NULL) return;
    struct line *temp = lines;
    struct line *prev;
    debug;
    for(; temp != NULL; temp = temp->next){
      debug;
      prev = temp;
      free(prev);
    }
    lines->next = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
  {
    struct line *temp = lines;
    struct line *prev;
    if(lines != NULL) watch_int(lines->char_cnt);
    for(; temp != NULL; temp = temp->next){
      prev = temp; // find position
    }
    temp = (struct line*) malloc(sizeof(struct line));
    strcpy(temp->words, word);
    watch_string(temp->words);
    if (num_words > 0){
      debug;
      watch_int(temp->char_cnt);
      prev->words = (char*) realloc(prev->words, (sizeof(char) * (prev->char_cnt + 1)));
      debug;
      prev->words[strlen(word) - 1] = ' ';
    }
    watch_string(temp->words);
    temp->char_cnt = strlen(temp->words);
    watch_int(temp->char_cnt);
    temp->next = NULL;
    if(prev != NULL) prev->next = temp;
    line_len += strlen(word);
    num_words++;
  }
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
  for (; temp != NULL; temp = temp->next) {
    if ((temp->words)[temp->char_cnt - 1] != ' ')
      printf("%s", temp->words);
    else {
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
  for (; temp != NULL; temp = temp->next)
    printf("%s", temp->words);
}

// int main(){
//   if(line == NULL){
//     printf("hi");
//   }
//   return 0;
// }