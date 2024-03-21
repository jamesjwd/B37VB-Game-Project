#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variables:
int total_score = 0;
int score_win = 1;
int total_number = 0; //This is the sum of dice rolls in the current round
int dice_roll;
int blackjack = 21;
char answer [3]; //Yes or No
int round_number = 0;

int main() 
{
  printf("Hello, welcome to my game.\n"
  "This game is similar to the card game Black Jack or also known as 21.\n"
  "In this game you roll a 6 sided dice and with each number you roll is summed together.\n"
  "Your aim is to get your total as close to 21 as possible.\n"
  "For each roll you gain 1 point.\n"
  "If you get your total to 21 you gain 5 points.\n"
  "If decide to roll and it pushes your total to over 21, you lose and will have to restart.\n"
  "Try to see how many points you can get in the 5 rounds you are given.\n");
  
for (round_number = 1; round_number <= 3; round_number++)
{
  srand(time(0));
  int dice_roll = ((rand() % 6) + 1); //generating a random number between 1-6
  printf("You rolled a %d!",dice_roll);
  
  total_number = total_number + dice_roll;

  printf("Your score is %d", total_number);
  printf("Would you like to roll the dice again? (yes or no)");
  scanf("%s", answer);
  if (answer = "yes");
}
  return 0;
}