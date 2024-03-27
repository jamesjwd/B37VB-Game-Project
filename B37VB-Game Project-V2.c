//* This code was taken from an online source
#include <stdio.h>
#include <stdlib.h> //*
#include <time.h> //*

//Variables:
int total_score = 0; //This is the total score across all rounds
int round_score = 0; //This is the total score across the current round
int score_win = 1; //the point you gain for each roll
int bonus_score_win = 5;//The bonus point gained for getting blackjack
int blackjack = 21;
char answer; //Yes or No
int round_number = 1; //initial round number
int total_dice_roll = 0; //This is the sum of dice rolls in the current round

int main() {
  printf("Hello, welcome to my game.\n"
  "This game is similar to the card game Black Jack (also known as 21).\n"
  "In this game you roll a 6 sided dice.\n"
  "With each roll you gain 1 point.\n"
  "You can then choose whether to continue to roll to try to gain more points\n"
  "Or you can choose to stop rolling which will end the round.\n"
  "Your aim is to get your total as close to 21 as possible.\n"
  "If you get your total to 21 you gain 5 points.\n"
  "If continue to roll and it causes you to surpass 21, you lose and will have to restart completely.\n"
  "Try to see how many points you can get in the 3 rounds you are given.\n\n");
  
printf("Press SPACE to start the game.\n\n");
getch();

for (round_number = 1; round_number <= 3; round_number++)
{
  printf("Press SPACE to start round %d.\n\n", round_number);
  getch();

  int total_dice_roll = 0; //This is the sum of dice rolls in the current round

  srand(time(0)); //*
  int dice_roll = ((rand() % 6) + 1); //* Generating a random number between 1-6
  printf("You rolled a %d!\n\n",dice_roll);
  
  total_dice_roll = total_dice_roll + dice_roll; //updating the current number the player is on

  if (total_dice_roll == blackjack) { //Did the player reach 21? Yes, End round and add their round points to their total score.

    round_score = round_score + bonus_score_win ; //gains bonus points for blackjack
    total_score = total_score + round_score; //updating total score

    printf("You got Blackjack, you earn 5 bonus points!\n" 
    "Your total score for that round was %d.\n"
    "Your total score across all rounds is now %d.\n"
    "You will now start the next round.\n\n", round_score, total_score); 

    break;
  }

  else if (total_dice_roll > blackjack) { //Did the player surpass 21? Yes, They lose, print final score and end game.
    printf("You have surpassed 21 therefor you lose.\n Game Over!\n");
    printf("Your final total score was %d\n\n", total_score);

    return 0;
  }

  else { //The player is yet to reach 21? Do they wish to continue rolling?
    round_score = round_score + score_win; //gains a point
    printf("Your now on %d.\n Would you like to roll again? (Y/N)\n",total_dice_roll); //The round is still playing out. New loop to see if they wish to continue.
    scanf("%c", answer);

    if (answer == "Y") { //If they wish to continue round, exit loop, let them roll again.
      break;
    }

    else if (answer == "N"); { //If they wish to end round, exit both loops.
    printf("Your total number of points for that round was %d\n", round_score);
    printf("Your total score across all rounds is currently %d\n\n", total_score);
    break; 
    }

  break;
  }

  return 0;

} 
printf("Thank you for playing! Your final score was %d.\nPlay again and see if you can beat it!",total_score);
}