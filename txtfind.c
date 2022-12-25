#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define MAXLINES 250
// check if the two strings are similar with at most n differences
// S=check_string T=string given by the user
int similiar(char *s, char *t, int n)
{
    if (strlen(s) - strlen(t) > n)
    {
        return 0;
    }
    int i = 0, j = 0;
    int count = 0;
    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            count++;
        }
    }
    if (count <= n)
    {
        return 1;
    }
    return 0;
}
// check if there is any substring of str2 inside str1 with at most n differences
int substring(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (str1[i] != '\0' && str2[j] != '\0')
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j = 0;
        }
    }
    if (str2[j] == '\0')
    {
        return 1;
    }
    return 0;
}
// print the lines that contain the string -- IF CHOSEN BY THE USER "a"
void print_lines(char *str)
{
    char line[LINE];
    while (fgets(line, LINE, stdin) != NULL)
    {
        if (substring(line, str) == 1)
        {
            printf("%s", line);
        }
    }
}
// print the words that are similar to the string -- IF CHOSEN BY THE USER "b"
void print_similar_words(char *str)
{
    char line[LINE];
    while (fgets(line, LINE, stdin) != NULL)
    {
        for (char *check_word = strtok(line, " \t\r\n\v\f"); check_word != NULL; check_word = strtok(NULL, " \t\r\n\v\f"))
        {
            if (similiar(check_word, str, 1) == 1)
            {
                printf("%s\n", check_word);
            }
        }
    }
}
int main()
{
    char str[LINE];
    fgets(str, LINE, stdin);
    char *token = strtok(str, " ");   // token is the first string
    char *token2 = strtok(NULL, " "); // token is the second string - the char
    char ch = token2[0];              // finding the char at the end of the string
    if (ch == 'a')
    {
        print_lines(token);
    }
    else if (ch == 'b')
    {
        print_similar_words(token);
    }
    return 0;
}