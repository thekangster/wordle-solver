
# Design Document - hw1: input, loops, numbers, and pigs

This program implements a simplified version of the dice game Pass the Pigs. To abstract the pig in the game, we will need to represent its positions (Side, Razorback, Trotter, Snouter, Jowler). We do this by creating an alias for the positions then enumerating through them. Therefore, we are able to represent the probabilities for the positions in an array. To represent rolling the pig, we use a pseudo random number generator to make the program reproducible.

# Pseudocode


typedef with alias of "Positions" and enumerate  
initialize array of size 7 with all positions and respective probabilities  

initialize input variable to 0    
prompt user to input number of players    
if input < 2 || input > 10  
&nbsp;&nbsp;&nbsp;&nbsp;set input to 2  
&nbsp;&nbsp;&nbsp;&nbsp;print to stderr "Invalid number of players. Using 2 instead.\n"    
else scan input  

initialize seed variable to 0    
prompt user to input random seed   
if the seed < 0 || seed > UINT_MAX    
&nbsp;&nbsp;&nbsp;&nbsp;set seed to 2022    
&nbsp;&nbsp;&nbsp;&nbsp;print to stderr "Invalid random seed. Using 2022 instead.\n"    
else scan seed  

set min variable = 0  
set max variable = 6   

initialize roll variable int  
initialize player_points array of integers of size [input]  
initialize pos_points array of integers of size [7] {0, 0, 10, 10, 15, 5, 5}  
initialize pos_phrase array of strings of size [7] {"pig rolled on side", "pig rolled on side", "pig lands on back", "pig lands upright", "pig lands on snout", "pig lands on ear", "pig lands on ear"}  

srandom(seed)
for (player = 0; player < input; player++)  

&nbsp;&nbsp;&nbsp;&nbsp;print "%names[player] rolls the pig..."  
&nbsp;&nbsp;&nbsp;&nbsp;while roll is not 0 or 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if player_points[player] >= 100   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print to stdout "%names[player] wins with %player_points[player] points!"  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;break loop  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set roll to min + (random() % (max - min))   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;player_points[player] += pos_points[roll]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print "%pos_phrase"  
&nbsp;&nbsp;&nbsp;&nbsp;print "%player lands on side\n"  
&nbsp;&nbsp;&nbsp;&nbsp;set roll to None  


