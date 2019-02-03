#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void readWeights(int *result){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("in.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int i=0;
    while ((read = getline(&line, &len, fp)) != -1) {
       // printf("%s\n",line);
        result[i]=atoi(line);
        i++;
    }
    for(int i=0;i<25;i++){
     //  printf("%d\n",result[i]);
    }

    fclose(fp);
    if (line)
        free(line);
}


