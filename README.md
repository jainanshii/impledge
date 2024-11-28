Steps to execute the program :
In Command Prompt :
For Compilation g++ -o coumpounded_words compoundedwords.cpp
For Running compounded_words

Overview of the program 
    -Read Input from the files using ifstream
    -Pushing the words to the vector and trie.
    -Then processing each word in help function by finding that any node in the word is terminal node or not.
    -And then find the longest compounded word and second compounded word.
    -Calculationn of processing time of the program

Intuition:
The program can be solved by Recursion , Memoization and Trie . Trie can be used as it is efficient in searching the prefix in any word . It takes O(l) time to insert the word in the trie aand then searching word can be easy. 
The intuition was to insert the words into trie and then processing it by checking each substring if it presents in the trie or not. it can be checked by taking substring and checking whether the last node is the terminal 
node or not.

class TrieNode() is used to create or initialise the node to insert into trie it it consists of character , 26 children , is terminal to denote the end of word.
class Trie() is the main trie class which creates trie using trienode it consists of insert (word) into trie by traversing each character in the word and then find the index of character using ascii value , and add node to trie.
trie consists of help(Word,index,count) index is the index of character from where word has to be traversed , count is the number of substrings. It works by traversing string until terminal node is found, when terminal node is found we increment 
count and start from root node only to find the substring which can be found in trie.

There is a function solve which takes filepath as arguement . Pushing words to trie and vector then traversing each word and processing by passing to help function if it returns true then we compare the strings to find longest 
and second longest string in the file.
