#include "shrink.h"
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;

// function to return integer indexed in the dictionary,
// returns -1 if not in dictionary
int lookup(const char* word, const char** dictionary) {

  int it = 0;

  while(!dictionary[it]) {
    if(!strcmp(word, dictionary[it]))
      return it;

    it++;
  }

  return -1;
}

// function to compress word by looking it up in dictionary
void encode(const char* word, char* compressed, const char** dictionary) {

  // check if number is first character
  if(isdigit(word[0])) {
    strcpy(compressed, "!");    // copy "!" string
    strcat(compressed, word);   // append word
  }

  int result = lookup(word, dictionary);
  char val[2 + 1];   // "00" + '\0'

  if(result > 0) {
    if (result < 10) {
      val[0] = '0';
      val[1] = result + '0';
    } else {
      // val[0] = result % 10 + '0';
      // val[1] = (result - result % 10)/10 + '0';
      itoa(result, val, 10);
      // testing itoa
    }

    val[2] = '\0';
    strcpy(compressed, val);

  } else {
    strcpy(compressed, word);
  }
}
