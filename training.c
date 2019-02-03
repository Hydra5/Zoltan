#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<sys/types.h>

static int binSearch(char *strs[], int size, char *key);
static void readEdgesWeights(char *result[], int *nums);
int main(){
    char *str ="fareed";
    char *strs [59868];
    int nums[59868];
    readEdgesWeights(strs,nums);
    //for(int i =0; i< 59868;i++)
    //printf("%s -> %d\n", strs[i], nums[i]);
    printf("%d\n", binSearch(strs,59868,"12 -- 27583"));
    //printf("%d\n",strcmp("1","11"));
}


static int binSearch(char *strs[], int size, char *key){
    int low = 0;
    int high = size -1;
    int mid;
    int cmpVal;
    while(low <= high) {
        mid = (low + high) /2;
        cmpVal = strcmp(key, strs[mid]);
        if( cmpVal== 0){
            return mid;
        }
        else if(cmpVal < 0){
            high = mid - 1; 
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

static void readEdgesWeights(char *keys[],int *nums){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int vals[8];

    fp = fopen("inout/zoltan_weighted_egds.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    int i=0;
    char *token;
    while ( (read = getline(&line, &len, fp)) != -1) {
        strtok(line,"\n");
        token = strtok(line, ";");
        keys[i] = (char *)malloc(strlen(token));
            strcpy(keys[i], token);
            token = strtok(NULL, ";");
            nums[i++] = atoi(token);        
    }

    fclose(fp);
    if (line)
        free(line);
}