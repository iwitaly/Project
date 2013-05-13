//
//  main.c
//  shell
//
//  Created by Виталий Давыдов on 13.05.13.
//  Copyright (c) 2013 Виталий Давыдов. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char command[200];
char fullPath[300] = "/bin/";
char currentPath[500];

void usersInputToTheString(char *str) {
    gets(str);
    while (str == NULL || strlen(str) == 0) {
        printf("input another string\n");
    }
}

int main(int argc, const char * argv[])
{
    printf("%s", argv[0]);
    while (1) {
        scanf("%s", command);
        
        strcat(fullPath, command);
        
        printf("%s\n", fullPath);
        if (!fork()) {
            execl(fullPath, command, NULL);
            
            perror("");
        }
        else {
            strcpy(fullPath, "/bin/");
            fullPath[strlen("/bin/")] = '\0';
            strcpy(command, "");
        }
    }
    return 0;
}