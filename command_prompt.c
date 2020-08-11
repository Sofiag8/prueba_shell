#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void prompt_print(void)
{
        char *line;
        int status;

        do {
                printf("$ ");
                status = print_arguments(line);

                free(line);
        }
        while (status);
}
int print_arguments(int argc __attribute__((unused)), char *envp[])
{
        while (*envp)
        {
                printf("%s\n", *envp++);
        }
        return (0);
}

int main(int argc, char **argv)
{
        prompt_print();
        return EXIT_SUCCESS;
}
