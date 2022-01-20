
# DESIGN DOCUMENT - hw1: input, loops, numbers, and pigs

This program implements a simplified version of the dice game Pass the Pigs. To abstract the pig in the game, we will need to represent its positions (Side, Razorback, Trotter, Snouter, Jowler). We do this by creating an alias for the positions then enumerating through them. Therefore, we are able to represent the probabilities for the positions in an array. To represent rolling the pig, we use a pseudo random number generator to make the program reproducible.

# PSEUDOCODE

`typedef with alias of "Positions" and enumerate  `
initialize array of size 7 with all positions and respective probabilities

initialize input variable to 0  
prompt user to input number of players  
if input is not an integer between 2 and 10  
&nbsp;&nbsp;print to stderr "Invalid number of players. Using 2 instead.\n"  

initialize seed variable to 0  
prompt user to input random seed  
if the seed is not valid  
&nbsp;&nbsp;set seed to 2022  
&nbsp;&nbsp;print to stderr "Invalid random seed. Using 2022 instead.\n"  

