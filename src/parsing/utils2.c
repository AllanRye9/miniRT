#include"../include/miniRT.h"


char *ft_strtrim_free(char *s1, char *set)
{
    char *line;

    line = NULL;
    if (!s1)
        return (free(s1), NULL);
    line = ft_strtrim(s1, set);
    free(s1);
    return (line);
}

void free_2d_array(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return ;
    while(arr[i] != NULL)
    {
        free(arr[i]);
    }
    free(arr);
}

int count_words(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(line[i])
    {
        while(is_whitespace(line[i]) && line[i] != '\0')
            i++;
        if (line[i] == '\0')
            break;
        count++;
        while(!is_whitespace(line[i]) && line[i] != '\0')
            i++;
    }
    return (count);
}

char *create_string(char *line, int start, int end)
{
    char *res;

    res = (char *)malloc(sizeof(char) * (end - start) + 1);
    if (!res)
        return (free(res), NULL);
    ft_strlcpy(res, &line[start], (end - start) + 1);
    return (res);
}

char **ft_split_whitespace(char *line)
{
    char    **arr;
    int     i;
    int     word_start;
    int     index;

    arr = (char **)malloc(sizeof(char*) * (count_words(line) + 1));
    if (!arr)
        return (NULL);
    i = 0;
    word_start = 0;
    index = 0;
    while(line[i])
    {
        while (is_whitespace(line[i]) && line[i] != '\0')
            i++;
        if (line[i] == '\0')
            break;
		word_start = i;
        while (!is_whitespace(line[i]) && line[i] != '\0')
            i++;
        arr[index] = create_string(line, word_start, i - 1);
		if (arr[index] == NULL)
		{
			while (index > 0)
				free(arr[--index]);
			free(arr);
			return (NULL);
		}
		index++;
    }
	arr[index] = NULL;
	return (arr);
}
