#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c)
{
    if (s == NULL) 
    {
        return NULL;
    }

    int count_word = mx_count_words(s, c);
    
    char **result = (char **)malloc((count_word + 1) * sizeof(char *));
    if (result == NULL) 
    {
        return NULL;
    }

    int index = 0;
    int start_position = 0;

   
    while (s[start_position] == c) 
    {
        start_position++;
    }

    while (s[start_position]!= '\0') 
    {
        int end_position = start_position;

       
        while (s[end_position]!= '\0' && s[end_position] != c) 
        {
            end_position++;
        }

       
        if (end_position > start_position) 
        {
            int word_len = end_position - start_position;
            result[index] = mx_strnew(word_len);
            if (result[index] == NULL) 
            {
                
                for (int i = 0; i< index;i++) 
                {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }

            mx_strncpy(result[index],s + start_position, word_len);
            result[index][word_len] = '\0';
            index++;
        }

        
        start_position =end_position;

        
        while (s[start_position]== c) 
        {
            start_position++;
        }
    }

    result[index] =NULL; 

    return result;
}
