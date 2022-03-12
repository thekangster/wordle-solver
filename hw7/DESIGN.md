
# homework 7: Hash tables, I/O and strings

This is the design document for homework 7

# how the program works

This program will allow us to see a represenation of a simple database of our customers and the information we know about them. This database also has an interface that gives us the ability to read a database file from the disk, add customers, delete customers, and save the database back to the file.

My implementation of this will utilize a businessdb.c file that will hold the main file. My hw7.c file will hold my hashtable implementation, including their functions and linkedlist functions. hw7.h will include linkedlist node struct and function declarations.

The program should read customers.tsv and store the customers into the hash table. Then, it will prompt the user to enter any of the supported commands.

`add`: the program will additionally prompt the user for an email address, a display name, a shoe size, and a favorite food. This user (with their associated data) will then be added to the hash table. If that email address is already present in the has table, then replace the data that was already in the hash table with the new entry.

`lookup`: prompt the user for an email address, then go find that entry in the hash table! If the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found. Then display all the information we have about that user in a nicely formatted way.

`delete`: prompt the user for an email address, then go find that entry in the hash table (and delete it from the linked list in the bucket). Again, if the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found.

`list`: display every user in the database, in whatever order is convenient. Format each user the same way we do in lookup.

`save`: write the current state of the database back to customers.tsv.

`quit`: clean up all of our memory and exit the program.

# pseudocode (Customer Node struct)
```
struct CustomerNode
  email
  name
  shoe_size
  fav_food
  pointer to next

main:
  create NULL initialized buckets array of size NUM_BUCKETS
  create temporary variables for email, name, shoesize, and fav food
  
  create line buffer

  open customers.tsv for read
  if there is no file
    print error

  get first line
    scan the first line and save each tab-separated value to the temp variables
      add the values to the hashtable
  close the file
  
  while true
    get a command from user
      if command is quit
        delete the hashtable
        break
      
      else if the command is add
        ask for email, name, shoe size, favorite food
        add the values to hashtable

      else if the command is save
        write all the values in the hashtable to customers.tsv

      else if the command is lookup
        ask for email
        print the value of the email in the hashtable

      else if the command is delete
        ask for email
        delete the customer in the hashtable
      
      else if the command is list
        go through the hashtable and list the keys and values
```

# how to run it

In order to compile this program we will need the Makefile, c source files, and header files.

To build all the programs, run:

`$ make all`

To run the program:

`$ ./businessdb`

To remove binary files, run:

`$ make clean`

