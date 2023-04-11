# Cyberprotect task

This is a repo with an application task for Cyberprotect.

### Algorithm

The program takes the list of words - dictionary. Then it devides every word to substrings of 3 letters, then counts the number of times this every substring occured in the dictionary - *weight*. Then the words are sorted by the weight, which counts as the lowest of the substrings weight.


### Compiling 

To comple use:
        
    make

### Using

In the program folder there must be a file named "in_words.txt", which contains words

The output of the program is a file "out_task.txt", contains sorted list of words.

To run use:

    ./words 

To use alternative method of counting weight use:

    ./words -n