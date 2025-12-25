#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int checkWord(int r,int c,int k,char *word, int dx[], int dy[],char matrix[100][100], int R, int C){
    int length;
    length = strlen(word);
    for(int steps = 0; steps < length; steps++ ){
        int nextR = r + steps*dx[k];
        int nextC = c + steps*dy[k];
        if (nextR >= R || nextC >= C || nextR < 0 || nextC < 0){
            return false;
            break;
        }

        if (word[steps] != matrix[nextR][nextC]){
            return false;
            break;
        }
    } return true;
}

int main()

{
    int R, C;   // matrix input
    scanf("%d %d", &R, &C);
    
    char matrix[100][100];

    for (int i = 0; i < R ; i++){
        for (int j = 0; j < C; j++ ){
            scanf(" %c", &matrix[i][j]);
            
        }
    }

    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

    char word[100];

    while(scanf("%s", word) == 1){
        if (word[0] == '#'){
            break;
        } 
         else{
            bool found = false;
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    for(int k = 0; k < 8; k++){
                        if(checkWord(i, j, k, word, dx, dy, matrix, R, C)){
                            printf("%s %d %d %d %d\n", word, i, j, dx[k], dy[k]);
                            found = true;
                        }

                        if (found) {break;}
                    } if(found) {break;}
                } if(found) {break;}
            } if(!found){printf("%s -1\n", word);}
        }
    }


/*
    for (int i = 0; i < R ; i++){
        for (int j = 0; j < C; j++ ){
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
*/


}