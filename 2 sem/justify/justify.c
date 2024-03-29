#include <stdio.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void){

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    char word[MAX_WORD_LEN+2];
    int word_len;
    clear_line();
    while (1) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            debug;
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN){
            debug;
            word[MAX_WORD_LEN] = '*';
        }
        if (word_len + 1 > space_remaining()) {
            // debug;
            write_line();
            clear_line();
        }
        add_word(word);
    }


    return 0;
    
}