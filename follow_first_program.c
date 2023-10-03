#include <stdio.h>
#include <string.h>
#include <ctype.h>

void first(char buffer[]);
char p[10][20];
int n_p;

void first(char buffer[]) {
    char options[5][10],flag[4]={'\0'};
    int starter=0;
    memset(options, '\0', sizeof(options));
    int i=0, j=0, k = 0;
    for(i=0;i<strlen(buffer);i++)
        if(buffer[i]!='-')
            flag[i]=buffer[i];
        else if(buffer[i]=='-'){
            flag[i]=='\0';
            starter=i+2;
            break;
        }
    //decompose all options of production in a 2d array
    for (i=starter; i < strlen(buffer); i++) {
        if (buffer[i] != '|') {
            options[j][k] = buffer[i];
            k++;
        } else {
            options[j][k] = '\0';
            j++;
            k = 0;
        }
    }
   //printf("J value=%d\n", j);
for (i = 0; i <= j; i++) {
    //printf("%s", options[i]);
    //printf("%c",options[i][0]);
    if(isupper(options[i][0])) {
        for (int l = 0; l <= n_p; l++) {
            //printf("Inside ifupper block");
            // Assuming p[l][0] is the non-terminal to be expanded
            if (p[l][0] == options[i][0]) {
                //printf("Going for expansion %s ", p[l]);
                // Consider passing appropriate arguments to first
                first(p[l]);
            }
        }
    }
    // Check if it's a terminal
    else if (!isupper(options[i][0])) {
        //printf("Inside !ifupper block");
        if (strcmp(options[i], "#") != 0)
            printf("%c,", options[i][0]);
        else {
            printf("%c", options[i][0]);
        }
    }
}

    
    
}

int main() {
    int i;
    printf("Enter the number of productions: ");
    scanf("%d", &n_p);
    for (i = 0; i < n_p; i++) {
        printf("Enter %d production: ", i + 1);
        scanf("%s", p[i]);
    }
    //call left factoring for each production using loop
    for (i = 0; i < n_p; i++){
        printf("First of %c: {",p[i][0]);
        first(p[i]);
        printf("}\n");
    }
    return 0;
}