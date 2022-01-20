
# Design Document - hw1: input, loops, numbers, and pigs

This program implements a simplified version of the dice game Pass the Pigs. To abstract the pig in the game, we will need to represent its positions (Side, Razorback, Trotter, Snouter, Jowler). We do this by creating an alias for the positions then enumerating through them. Therefore, we are able to represent the probabilities for the positions in an array. To represent rolling the pig, we use a pseudo random number generator to make the program reproducible.

# Pseudocode

`typedef with alias of "Positions" and enumerate`  
`initialize array of size 7 with all positions and respective probabilities`  

`initialize input variable to 0`    
`prompt user to input number of players`    
`if input is < 2 || > 10`  
&nbsp;&nbsp;&nbsp;&nbsp;`set input to 2`
&nbsp;&nbsp;&nbsp;&nbsp;`print to stderr "Invalid number of players. Using 2 instead.\n"`    

`initialize seed variable to 0`    
`prompt user to input random seed`   
`if the seed is > 0 && > UINT_MAX`    
&nbsp;&nbsp;&nbsp;&nbsp;`set seed to 2022`    
&nbsp;&nbsp;&nbsp;&nbsp;`print to stderr "Invalid random seed. Using 2022 instead.\n"`    
`set min variable = 0`  
`set max variable = 6`  
`srandom(seed)`  

`initialize roll variable`  
`initialize player_points array of integers of size [input]`  
`initialize pos_points array of integers of size [7] {0, 0, 10, 10, 15, 5, 5}`  

`for (player = 0; player < input; player++)`  
&nbsp;&nbsp;&nbsp;&nbsp;`while roll is not 0 or 1`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`set roll to min + (random() % (max - min))`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`player_points[player] += pos_points[roll]`
&nbsp;&nbsp;&nbsp;&nbsp;`print "%player rolls the pig... pig rolled %pig[roll]"`  

`for (i = 0; i < input; i++)`  
&nbsp;&nbsp;&nbsp;&nbsp;`create list of integers of size i(number of players)`  

