#include "../minishell.h"

void test_splitted(char **line) {
	size_t i;
	t_cmdlist *splitted;
	t_cmdlist *temp;

	i = 0;
	splitted = split_sh(*line);
	if (!splitted) {
		perror("readline:");
		exit(EXIT_FAILURE);
	}
	temp = splitted;
	while (splitted) {
		printf("--------\n");
		printf("%s\n", splitted->word);
		splitted = splitted->next;
		i++;
	}
	free_cmd(temp);
	free(*line);
	exit((int) i);
}