/*
    Names: Elijah Sprung, Blake Robinson, Parker Azul, McHale Trotter, and Dylan Hudson
    Date: 05/05/2022
    Course: CSC-2710-01
    Description: Essentially creating a CTRL-F function, which finds a word in a string of text and returns its position in the text.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// Struct to hold both the original word and its hash for searching.
struct word
{
    string str;
    int hash;
};

// Global variables for lists that are manipulated.
vector<word> words(100000);
vector<list<word>> hash1(100000);

// Function declaration for our load function.
string loadString(const string& path);

// Function declaration for the parsing function.
void parse(string text);

// Function declaration for the hashing function.
void hasher();

// Function declaration for the bucket function.
void bucket();

// Main function where all the code is run.
int main()
{
    // Asking for file name for input.
    string input_file;
    cout << "What text document would you like to open? (hint: it is text.txt)" << endl;
    cin >> input_file;

    // Attempt to open given file name.
    string text = loadString(input_file);

    // Parse through the text, hash it, and put it into the bucket as needed.
    parse(text);
    hasher();
    bucket();

    // Ask for word in the text and input.
    string input;
    cout << "what word ya want bucko: ";
    cin >> input;

    // Variables for hashing.
    int hashval = 0;
    bool found = false;

    // Figure out what total ASCII value of input.
    for (int i = 0; i < input.length(); i++)
    {
        hashval += (int)input[i];
    }

    // Finds if the word exists in the hash of the text.
    for (int w = 0; w <= hash1[hashval].size(); w++)
    {
        if (hash1[hashval].front().str == input)
        {
            cout << "word found in text"<< endl;
            found = true;
            break;
        }
        else
        {
            hash1[hashval].pop_front();
        }
    }
    
    // Finds the exact location and what is before or after the word for help.
    if (found)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (input == words[i].str && (i - 1 >= 0) && (i + 1 <= words.size()))
            {
                cout << "it appears between " << words[i - 1].str << " and " << words[i + 1].str << " and it is the " << i + 1 << "th word in the text." << endl;
            }
            else if (input == words[i].str && (i - 1 < 0) && (i + 1 <= words.size()))
            {
                cout << "it appears before " << words[i + 1].str << " and it is the " << i + 1 << "th word in the text." << endl;
            }
            else if (input == words[i].str && (i - 1 >= 0) && (i + 1 > words.size()))
            {
                cout << "it appears after " << words[i - 1].str << " and it is the " << i + 1 << "th word in the text." << endl;
            }
        }
    }
    else
    {
        cout << "not found, check capilization";
    }
}

// Function to take a text file name, open that file, and read in all of the text in that file as a single string.
string loadString(const string& path)
{
    ifstream inFile(path);

    if (!inFile.is_open())
    {
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }

    return string((istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
}

// Function that ignores single punctuation in order to read in the string from the text file as separate words.
void parse(string text)
{
    //string compares = " .!?;,()[]{}";
    int i = 0;

    // Loop to only insert letters.
    for (int j = 0; j < text.length(); j++)
    {
        //if (text[j] != compares[0] && text[j] != compares[1])
        if ((text[j] > 64 && text[j] < 91) || (text[j] > 96 && text[j] < 123))
        {
            words[i].str += text[j];
        }
        else
        {
            i++;
        }
    }
}

// Function to convert letters to their ascii values and add them to the list.
void hasher()
{
    for (int z = 0; z < words.size(); z++)
    {
        int total = 0;

        for (int w = 0; w < words[z].str.length(); w++)
        {
            total += (int)words[z].str[w];
        }

        words[z].hash = total;
    }
}

// Function to place the hash into the correct bucket in the list.
void bucket()
{
    
    for (int i = 0; i < words.size(); i++)
    {
        //cout << "ran ";
        int num = words[i].hash;
        hash1[num].push_back(words[i]);
    }
}
