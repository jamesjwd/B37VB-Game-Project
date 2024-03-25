#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variables:
int total_score = 0;
int score_win = 1; //the point you gain for each roll
int bonus_score_win = 5;//The bonus point gained for getting blackjack
int blackjack = 21;
char answer; //Yes or No
int round_number = 0;

int main() {
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
  int total_dice_roll = 0; //This is the sum of dice rolls in the current round

  srand(time(0));
  int dice_roll = ((rand() % 6) + 1); //generating a random number between 1-6
  printf("You rolled a %d!\n",dice_roll);
  
  total_dice_roll = total_dice_roll + dice_roll;
  if (total_dice_roll = blackjack) {
    total_score = total_score + bonus_score_win ;
    printf("You got Blackjack, you earn 5 bonus points!\n You will now start the next round."); //They win. Move on to next round.
    break;
  }
  else if (total_dice_roll > blackjack) {
    printf("You have surpassed 21 therefor you lose.\n Game Over!"); //They over-shot 21. They lose. End Game.
    return 0;
  }
  else {
    total_score = total_score + score_win;
    printf("Your now on %d. \n Would you like to roll again? (Y/N)",total_dice_roll); //The round is still playing out. New loop to see if they wish to continue.
    scanf("%c", answer);
    if (answer = "Y") {
      
    }
  }
  }
  return 0;
} 