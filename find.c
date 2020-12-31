#include <string.h>
#include <stdio.h>
#define LINE 256
#define WORD 30
#define TEXT 250    //maximun lines


int getFirstLine( char s[]){
    char c;
    int i=0;
    while((scanf("%c", &c)==1) && (c !='\n')){
        s[i] = c;
        ++i;
    }
    return i;
}

int getLine( char text[], char line[]){
    int i=0; 
    while(text[i]!= '\n'){
        line[i]=text[i];
        ++i;
    }
    line[i] = '\0';
    return i;
}

int getWord( char s[], char word[]){
    int i=0;
    while((s[i]!='\n')&&(s[i]!='\t')&&(s[i]!=' ')&&(s[i]!='\r')){
        word[i] = s[i];
        ++i;
    }

    if (word[i-1]=='\n'){
        printf("problem..!");
    }
    word[i] = '\0';
    return i;
}


int isEqualStringN(char s1[], char s2[], int n) {
	for (int i=0; i<n; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}
int substring(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i <= len2-len1; i++) {
        if (isEqualStringN(s1, s2+i, len1)) {
            return 1;     //true
        }
    }
    return 0;     //false
}

//return 1 if and only if s1 is similar to s2 by delete not more than one char:
int similar(char* s1, char* s2){
    if (strlen(s2)-strlen(s1)>1){
        return 0;   //  false
    }
    int count=0;
    for (int i=0, j=0; i<strlen(s1) && j<strlen(s2);){
        if (s1[i]==s2[j]){
            ++i;
            ++j;
        }
        else{
            if (count==0){
                ++j;
                count=1;
        }
            else{
                return 0;       //false
            }  
        }
    }
    return 1;       //true

}


void print_line (char str[]){
    //read the text:
    char text [LINE*(TEXT-2)];
    char c;
    int i=0;
    for(; scanf("%c", &c)==1; ++i){
        text[i] = c;
    }
    text[++i]='\0';         //?????????????????  

    //print the correct lines:
    int j=0;
    char line[LINE];
    while(text[j]){     // mean: text[j]!='\0'
        j += getLine(text+j, line)+1;
        if (substring(str, line)){
            printf("%s", line);
        }
    }

}

void print_similar_words(char str[]){
    //read the text:
    char text [LINE*(TEXT-2)];
    char c;
    int i=0;
    for(; scanf("%c", &c)==1; ++i){
        text[i] = c;
    }
    text[i]='\0';

    //print the correct words:
    int j=0;
    char line[LINE];
    char word[WORD];
    while(text[j]){   
        j += getLine(text+j, line)+1;
        int k=0;
        while (line[k]){
            k += getWord(line+k, word)+1;
            if (similar(str, word)){
                printf("%s\n", word);
            }
        }
    }
}

int main(){
    char firstLine[LINE];
    getFirstLine(firstLine);
    char firstWord[WORD];
    int index = getWord(firstLine, firstWord)+1;
    char str[WORD];
    strcpy(str,firstWord);

    char funStr[1];
    getWord(firstLine+index, funStr);
    char fun = funStr[0];

    if (fun =='a'){
        print_line(str);
    }
    if (fun == 'b'){
        print_similar_words(str);
    }

    return 0;
}

