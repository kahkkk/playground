#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int streq(char *str1, char *str2)
{
    for (; *str1 != 0 && *str2 != 0; str1++, str2++) {
        if (*str1 != *str2) return 0;
    }

    return *str1 == 0 && *str2 == 0;
}

int whowin(char *left, char *right)
{
    if (streq(left, right)) return 0;

    if (streq(left, "rock"))
    {
        if (streq(right, "paper")) return 1;
        else if (streq(right, "scissors")) return -1;
    }
    else if (streq(left, "paper"))
    {
        if (streq(right, "scissors")) return 1;
        else if (streq(right, "rock")) return -1;
    }
    else if (streq(left, "scissors"))
    {
        if (streq(right, "rock")) return 1;
        else if (streq(right, "paper")) return -1;
    }
}

int main(int argc, char **argv)
{
    int winner;
    char *player;
    char *bot;
    char *plays[3] = { "rock", "paper", "scissors" };

    if (argc < 2)
    {
        puts("usage: rps <rock | paper | scissors>");
        return 0;
    }

    player = argv[1];

    // set random seed
    srand(time(NULL));
    bot = plays[rand() % 3];

    printf("(Jogador) %s x %s (Bot)\n", player, bot);

    winner = whowin(player, bot);
    if (winner == 0) puts("Tie!");
    else if (winner == -1) puts("Player wins!");
    else if (winner == 1) puts("Bot wins!");

    // switch (bot)
    // {
    //     // rock
    //     case 0:
    //     {
    //         puts("rock");

    //         if (streq(player, "paper")) puts("Player won!");
    //         else if (streq(player, "scissors")) puts("Bot won!");
    //         else if (streq(player, "rock")) puts("Tie!");
    //         break;
    //     }
    //     // paper
    //     case 1:
    //     {
    //         puts("paper");

    //         if (streq(player, "paper")) puts("Tie");
    //         else if (streq(player, "scissors")) puts("Player won!");
    //         else if (streq(player, "rock")) puts("Bot won!");
    //         break;
    //     }
    //     // scissors
    //     case 2:
    //     {
    //         puts("scissors");

    //         if (streq(player, "paper")) puts("Bot won!");
    //         else if (streq(player, "scissors")) puts("Tie!");
    //         else if (streq(player, "rock")) puts("Player won!");
    //         break;
    //     }
    // }

    return 0;
}