/*
  Author: Elijah Sprung
  Date: 01/26/2021
  Class: CSC 1720-03
  Code Location: ~/esprung/csc1720/prog_1/prog_1_sprung_A.cpp

  About: 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "counter_type.h"

using namespace std;

// Function prototypes.6
int count_chars(string text);
int count_vowels(string text);
int count_sentences(string text);
void most_words(string text, int sentences);

/*
  Main function that runs the entire program.
  pre-conditions: None.
  post-conditions: Returns 0.
*/

int main()
{
  string file_name;

  string all_text;
  int num_chars, num_vowels, num_sentences;

  cout << "Please enter the name of the file that you wish to read from." << endl;
  cout << "This file must contain only plain text." << endl;
  cout << "An example of a correct file name is Seuss.txt" << endl;
  cin >> file_name;
  
  fstream text;
  file_name = file_name;
  text.open(file_name);
  if (text.fail())
  {
    cerr << "Error: Could not open the file" << endl;
    exit(1);
  }

  ostringstream output;
  output << text.rdbuf();
  all_text = output.str();

  num_chars = count_chars(all_text);
  num_vowels = count_vowels(all_text);
  num_sentences = count_sentences(all_text);

  cout << "Number of chars: " << num_chars << endl;
  cout << "Number of vowels: " << num_vowels << endl;
  cout << "Number of sentences: " << num_sentences << endl;

  most_words(all_text, num_sentences);

  text.close();
  return 0;
}

/*
  Function to count the characters in a string.
  pre-conditions: A string must be passed to the function.
  post-condition: The number of characters will be returned as an integer.
*/

int count_chars(string text)
{
  counter_type count;

  count.initialize_counter();
  for (int i = 0; i < text.length(); i++)
  {
    count.increment_counter();
  }

  return count.get_counter();
}

/*
  Function to count the vowels in a string.
  pre-conditions: A string must be passed.
  post-conditions: The number of characters will be returned as an integer.
*/

int count_vowels(string text)
{
  counter_type count;

  count.initialize_counter();
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == 'a' || text[i] == 'A' || text[i] == 'e' || text[i] == 'E' || text[i] == 'i' || text[i] == 'I' || text[i] == 'o' || text[i] == 'O' || text[i] == 'u' || text[i] == 'U')
    {
      count.increment_counter();
    }
  }

  return count.get_counter();
}

/*
  Function to count the spaces in a string.
  pre-conditions: A string must be passed.
  post-conditions: The number of spaces will be returned as an integer.
*/

int count_spaces(string text)
{
  counter_type count;

  count.initialize_counter();
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == ' ')
    {
      count.increment_counter();
    }
  }

  return count.get_counter() + 1;
}

/*
  Function to count the number of sentences in a text document.
  pre-conditions: A text document must be passed as a string.
  post-conditions: The number of sentences will be returned as an integer.
*/

int count_sentences(string text)
{
  counter_type count;

  count.initialize_counter();
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == '.')
    {
      count.increment_counter();
    }
  }

  return count.get_counter();
}

/*
  Function to find a sentence with the most words and count how many words are
    in it.
  pre-conditions: A string with multiple sentences must be passed along with
    an integer that tells the number of sentences.
  post-conditions: The largest sentence and its amount of words will be printed
    out.
*/

void most_words(string text, int sentences)
{
  int words = 0, sentence = 0, j = 0, words_holder;
  string holder;
  bool stop;
  
  for (int i = 0; i < sentences; i++)
  {
    holder = "";
    stop = false;
    j += 1;

    while (stop == false)
    {
      holder.push_back(text[j]);

      if (text[j] == '.')
      {
        stop = true;
      }

      j++;
    }
    words_holder = count_spaces(holder);

    if (words_holder > words)
    {
      words = words_holder;
      sentence = i;
    }

  }

  cout << "Sentence with the most words: #" << sentence + 1 << endl;
  cout << "Number of words in the longest sentence: " << words << endl;
}