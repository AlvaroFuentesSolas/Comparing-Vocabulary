# Comparing-Vocabulary


In this assignment, you shall compare the vocabulary of two large text files by finding the 50
first different words from one file that do not occur in the second file. The program shall be
implemented in C language. A continuous string of characters a..z and A..Z, with possible
apostrophes ’, is considered a word. You can also include characters å,ä, ö, Å,Ä, and Ö if you
wish, but this is not obligatory. Words with uppercase and lowercase letters are considered
equal. For example, in the text
Herman Melville’s book Moby Dick starts, as we all know, with the sentence ”Call me Ishmael”.
the words are
herman, melville’s, book, moby, dick, starts, as, we, all, know, with, the, sentence, call, me, and
ishmael
The name of the text files can be either given as command-line arguments or as input from the user.
The program prints from the first file the 50 first different words that do not occur in the second
file. The words are printed in the order that they occur in the first file.
Because the second file can be very large, you need a suitable data structure to store its words.
This can be, for instance, a hash table or a binary search tree.
Measure the running times of your program with the test files. Also, estimate the time
complexity of your program, when the size of the input is the number of words in the text file.



YOU CAN ALSO FIND IN THE REPOSITORY SOME SOLUTIONS WITH SOME POSSIBLE MIXED FILES --> output_....
