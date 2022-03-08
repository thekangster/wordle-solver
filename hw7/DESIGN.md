
# homework 7: Hash tables, I/O and strings

This is the design document for homework 7

# how the program works

This program will allow us to see a represenation of a simple database of our customers and the information we know about them. This database also has an interface that gives us the ability to read a database file from the disk, add customers, delete customers, and save the database back to the file.

The program should read customers.tsv and store the customers into the hash table. Then, it will prompt the user to enter any of the supported commands.

`add`: the program will additionally prompt the user for an email address, a display name, a shoe size, and a favorite food. This user (with their associated data) will then be added to the hash table. If that email address is already present in the has table, then replace the data that was already in the hash table with the new entry.

`lookup`: prompt the user for an email address, then go find that entry in the hash table! If the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found. Then display all the information we have about that user in a nicely formatted way.

`delete`: prompt the user for an email address, then go find that entry in the hash table (and delete it from the linked list in the bucket). Again, if the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found.

`list`: display every user in the database, in whatever order is convenient. Format each user the same way we do in lookup.

`save`: write the current state of the database back to customers.tsv.

`quit`: clean up all of our memory and exit the program.

# pseudocode
```
struct CustomerInfo
  string email
  string name
  int shoe_size
  string fav_food

struct CustomerNode
  string key
  CustomerInfo val
  CustomerNode pointer to next

main:
  open customers.tsv
  read each line
  remove newline character
  split the file's strings by tab characters
  set CustomerInfo email to the first string
  set CustomerInfo name to the second string
  set CustomerInfo shoe_size to the third int
  set CustomerInfo fav_food to the fourth string

  set CustomerNode key to CustomerInfo email
  set CustomerNode val to CustomerInfo

  get user input for a command
    if command is quit
      break

    else if command is save
      open customers.tsv to write
      for each key in CustomerNode
        add the customer info to a line
        print each line

    else if command is add
      scan email, name, shoe size, favorite food
      add all the info to CustomerInfo
      CustomerNode[email] = CustomerInfo

    else if command is lookup
      scan the email
      if email is a key in CustomerNode
        print their info
      else
        print user is not found

    else if command is delete
      scan an email
      delete CustomerNode[email]
      if not in CustomerNode
        print user not found

    else if command is list
      print each CustomerNode's info

    else
      print unkown command
```

# how to run it

In order to compile this program we will need the Makefile, c source files, and header files.

To build all the programs, run:

`$ make all`

To run the program:

`$ ./hw7`


