#ifndef ARGV_SPLIT_H
#define ARGV_SPLIT_H

int count_argc(const char *str);
void argv_free(char ***argv);
char **argv_split(const char *str, int *argcp);

#endif // ARGV_SPLIT_H
