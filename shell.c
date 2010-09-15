#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char leading_prompt[255];

static void clear_screen()
{
	printf("%c[1;1H%c[J", 27, 27);
}

static void setup_prompt()
{
	char hostname[255];
	gethostname(hostname, sizeof(hostname));
	strcpy(leading_prompt, hostname);
	strcat(leading_prompt, ":~ ");
	strcat(leading_prompt, getenv("USER"));
	strcat(leading_prompt, "$");
}

static void prompt()
{
	char bees[1024];
	printf("%s ", leading_prompt);
	fgets(bees, sizeof(bees), stdin);
}

static void deny()
{
	printf("No.\n");
}

static void ask_for_stuff()
{
	prompt();
	deny();
}

int main()
{
	clear_screen();
	setup_prompt();
	while (1)
		ask_for_stuff();
	return 0;
}


