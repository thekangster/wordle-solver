
# homework 7: Hash tables, I/O and strings

This is the design document for homework 7

# how the program works

This program will allow us to see a represenation of a simple database of our customers and the information we know about them. This database also has an interface that gives us the ability to read a database file from the disk, add customers, delete customers, and save the database back to the file.

The program should read customers.tsv and store the customers into the hash table. Then, it will prompt the user to enter any of the supported commands.

`add`: the program will additionally prompt the user for an email address, a display name, a shoe size, and a favorite food. This user (with their associated data) will then be added to the hash table. If that email address is already present in the has table, then replace the data that was already in the hash table with the new entry.

# pseudocode

struct 
  string email
  string name
  int shoe_size
  string fav_food

# how to run it

In order to compile this program we will need the Makefile, c source files, and header files.

To build all the programs, run:

`$ make all`

To run the program:

`$ ./hw7`


