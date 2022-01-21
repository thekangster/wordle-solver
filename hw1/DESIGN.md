
# design document  

This is the DESIGN.md file for hw1: input, loops, numbers, and pigs  

## how the program works

This program implements a simplified version of the dice game Pass the Pigs. To abstract the pig in the game, we will need to represent its positions (Side, Razorback, Trotter, Snouter, Jowler). We do this by creating an alias for the positions then enumerating through them. Therefore, we are able to represent the probabilities for the positions in an array. We also use arrays to hold the value of the different roll positions, player's points, and phrases to print indicating what position a player rolled. To represent rolling the pig, we use a pseudo random number generator to make the program reproducible. The program will prompt the user to select the number of players and a random seed. Then the program will play out the game until a player wins. 

## pseudocode

```
typedef with alias of "Positions" and enumerate  
initialize array of size 7 with all positions and respective probabilities  

initialize input variable to 0    
prompt user to input number of players    
if input < 2 || input > 10  
    set input to 2  
    print to stderr "Invalid number of players. Using 2 instead.\n"    

initialize seed variable      
prompt user to input random seed  
if the seed < 0 || seed > UINT_MAX    
    set seed to 2022    
    print to stderr "Invalid random seed. Using 2022 instead.\n"    

set min variable = 0  
set max variable = 6   

initialize roll variable int  
initialize player_points array of integers of size [input]  
initialize pos_points array of integers of size [7] {0, 0, 10, 10, 15, 5, 5}  
initialize pos_phrase array of strings of size [num_strings][max_length] [7][4] {"pig rolled on side", "pig rolled on side", "pig lands on back", "pig lands upright", "pig lands on snout", "pig lands on ear", "pig lands on ear"}  

srandom(unsigned int seed)  
for (player = 0; player < input; player++)      
    print "%names[player] rolls the pig..."  
    while roll is not 0 or 1  
        if player_points[player] >= 100   
            print to stdout "%names[player] wins with %player_points[player] points!"  
            goto end  
        set roll to min + (random() % (max - min))   
        player_points[player] += pos_points[roll]  
        print "%pos_phrase"

    set roll to None  
    if player == input - 1  
        set player = 0  

end:  
```
