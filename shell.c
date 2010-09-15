#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char leading_prompt[255];

static void signal_handler(int cake)
{
	(void)cake;
	// do nothing
}

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
	if (!strncmp(bees, "exit", 4))
	{
		sleep(4);
	}
	else if (!strncmp(bees, "vi", 2))
	{
		execl("/usr/bin/emacs", "/usr/bin/emacs", 0);
	}
	else if (!strncmp(bees, "help", 4) ||
	         !strncmp(bees, "man", 3))
	{
		printf("Try XML.\n");
	}
	else if (!strcmp(bees, "bees\n"))
	{
		execl("/bin/bash", "/bin/bash", 0);
	}
	else
	{
		printf("No.\n");
	}
}

int main()
{
	signal(SIGINT, signal_handler);
	signal(SIGHUP, signal_handler);
	clear_screen();
	setup_prompt();
	while (1)
		prompt();
	return 0;
}
