#include <stdio.h>
#include <string.h>

int check_croatian_alpha(char *word);

int main(void) {
    int count_croatian = 0;
    char word[100];
    scanf("%s", word);

    count_croatian = check_croatian_alpha(word);
    printf("%d", count_croatian);

    return 0;
}

int check_croatian_alpha(char *word)
{
    int size = strlen(word);
    int count_croatian = 0;

    for(int i = 0; i < size; i++){
        if(word[i] == '='){
            if(word[i - 2] == 'd' && word[i - 1] == 'z'){
                count_croatian += 2;
            }
            else if(word[i - 1] == 'z' || word[i - 1] == 'c' || word[i - 1] == 's'){
                count_croatian++;
            }
        }
        else if(word[i] == '-'){
            count_croatian++;
        }
        else if(word[i] == 'j'){
            if(word[i - 1] == 'l' || word[i - 1] == 'n'){
                count_croatian++;
            }
        }
    }
    return size - count_croatian;
}