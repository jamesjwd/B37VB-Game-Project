//James Dickson Game Project.
//* This code was taken from an online source.
#include <stdio.h>
#include <stdlib.h> //* Library for the srand() function.
#include <time.h> //*Library for the time() function.
#include <conio.h> //* Library for the getch() function.
#include <string.h> //* Library for the strcmp() function.

//Variables: 
int total_score = 0; //This is the total score across all rounds.
int score_win = 1; //The point(s) you gain for each roll.
int bonus_score_win = 5;//The bonus point gained for getting blackjack.
int blackjack = 21;
int round_number = 1; //Initial round number.
int difference; // How far is the player from 21?
char answer[3]; //An array that stores the users input for the yes/no condition.

int main() {
  printf("\nHello, welcome to my game.\n"
  "This game is similar to the card game Black Jack (also known as 21).\n\n"
  "Instructions:\n"
  "In this game you roll a 6 sided dice.\n"
  "With each roll you gain 1 point.\n"
  "You can then choose whether to continue to roll to try to gain more points\n"
  "Or you can choose to stop rolling which will end the round.\n"
  "Your aim is to get your total as close to 21 as possible.\n"
  "If you get your total to 21 you gain 5 points.\n"
  "If continue to roll and it causes you to surpass 21, you lose and will have to restart completely.\n"
  "Try to see how many points you can get in the 3 rounds you are given.\n\n");
  
printf("Press SPACE to start the game.\n\n");
getch(); //*User must input a space to continue.

for (round_number = 1; round_number <= 3; round_number++) //Allows the code to run loop 3 times.
{
    int total_dice_roll = 0; //This is the sum of dice rolls in the current round.
    int round_score = 0; //This is the total score across the current round.

    printf("ROUND %d IS STARTING!!!\n", round_number);

  do {

  printf("Press SPACE to roll the dice...\n\n");
  getch(); //*User must input a space to continue.

  srand(time(0)); //*Generating a random 
  int dice_roll = ((rand() % 6) + 1); //* Generating a random number between 1-6
  round_score += score_win;//Update the player's score for the round by incrementing it by 1 for rolling the dice
  total_score += score_win; //Update the player's total score by incrementing it by 1 for rolling the dice
  printf("You rolled a %d!\n",dice_roll);
  
  total_dice_roll += dice_roll; //Update the number the player is currently on by incrementing by the number they just rolled
  difference = blackjack - total_dice_roll; //Calculating how far the play is from

  if (difference > 0) { //The player has not reached 21 yet
    printf("You are now on %d and are only %d away from blackjack!\n\n", total_dice_roll, difference);
    printf("Do you wish to roll again? ('yes' or 'no')\n\n");
    scanf("%s", answer); //Stores the users input under the variable 'answer'

    if (strcmp(answer, "no") == 0) { //*This function compares the string that the player inputted and "no". 
                                     //If these are the same then it will return 0 and the condition will evaluate to true and the round will end.
        printf("Your points gained over that round was %d.\n", round_score);
        printf("Your total points is now %d.\n\n", total_score);
        printf("Moving on to the next round...\n\n");
    }
  }
  else {
    printf("You are now on %d!\n", total_dice_roll);
  }
  } while ((strcmp(answer, "no") != 0) && (total_dice_roll < blackjack)); //Continue the round provided the player's answer is yes

if (total_dice_roll > blackjack) { //The player has overshot 21
    printf("Oh no, you overshot 21. You lose!\n\n");
    printf("Your score for that round was %d.\n", round_score);
    printf("Your total points is now %d.\n\n", total_score);
    break;
    }

if (total_dice_roll == blackjack) { //The player got blackjack!
    printf("Congratulations, you got blackjack!\nYou will recieve an extra 5 points!\n\n");
    total_score += bonus_score_win; //Update the total score by incrementing it by 5
    round_score += bonus_score_win;//Update the score for the round by incrementing it by 5
    printf("Your score for that round was %d.\n", round_score);
    printf("Your total points is now %d.\n\n", total_score);
}
  }

printf("Thank you for playing! Your final score was %d.\nPlay again and see if you can beat your last score!",total_score);

return 0;
}
