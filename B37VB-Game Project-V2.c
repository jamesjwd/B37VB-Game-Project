//James Dickson Game Project
//* This code was taken from an online source
#include <stdio.h>
#include <stdlib.h> //*
#include <time.h> //*
#include <conio.h> //*

//Variables: 
int total_score = 0; //This is the total score across all rounds
int round_score = 0; //This is the total score across the current round
int score_win = 1; //The point(s) you gain for each roll
int bonus_score_win = 5;//The bonus point gained for getting blackjack
int blackjack = 21;
char answer[3]; //Yes or No
int round_number = 1; //initial round number
int difference; // How far is the player from 21?

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
getch(); //*

for (round_number = 1; round_number <= 3; round_number++)
{
    int total_dice_roll = 0; //This is the sum of dice rolls in the current round

  printf("ROUND %d IS STARTING!!!\n", round_number);

  do {

  printf("Press SPACE to roll the dice...\n\n");
  getch(); //*

  srand(time(0)); //*
  int dice_roll = ((rand() % 6) + 1); //* Generating a random number between 1-6
  total_score = total_score + score_win;
  printf("You rolled a %d!\n",dice_roll);
  
  total_dice_roll = total_dice_roll + dice_roll;
  difference = blackjack - total_dice_roll;

  if (difference >= 0) {
    printf("You are now on %d and are only %d away from blackjack!\n\n", total_dice_roll, difference);
    printf("Do you wish to roll again?\n");
    scanf("%s",answer);
  }
  else {
    printf("You are now on %d!\n", total_dice_roll);
  }
  } while (total_dice_roll < blackjack);

if (total_dice_roll == blackjack) {
    printf("Congratulations, You landed on 21!\nYou will recieve an extra 5 points!\n\n");
    total_score = total_score + bonus_score_win;
}
else {
    printf("Oh no, you overshot 21. You lose!\nYour total points accross all rounds was %d!\n\n", total_score);
    break;
}

  }

printf("Thank you for playing! Your final score was %d.\nPlay again and see if you can beat your last score!",total_score);

}
