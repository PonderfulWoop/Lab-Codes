#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StringMatch(char s[], char match[]){
    int n_s = strlen(s);
    int n_match = strlen(match);
    int k = 0;
    for(int i = 0; i<=(n_s-n_match); i++){
        if(s[i] == match[k]){
            int temp = i;
            while(k < n_match && s[i] == match[k]){
                i++;
                k++;
            }
            if(k == n_match)
                return temp;
            else
                k = 0;
        }
    }
    return -1;
}

int main(){
    int n;
    char s[255], match[255];
    printf("Enter String:\n");
    gets(s);
    s[strlen(s) - 1] = '\0';
    
    printf("Enter String to match:\n");
    gets(match);

    match[strlen(match) - 1] = '\0';

    int res = StringMatch(s, match);
    if(res > 0)
        printf("Match successful; At: %d\n", res);
    else
        printf("Match Unsuccessful\n");
}