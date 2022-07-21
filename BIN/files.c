#include <stdio.h>
#include <string.h>
#include "files.h"
//#include "logger.h"
char *read_text_from_file(char *FILENAME)
{
    static char buf[256] = "";
    FILE *file;
    int flag_first = 1;

    file = fopen(FILENAME, "r");
    printf("POINTER = %p\n", file);

    if (file != NULL)
    {
        static char temp[256];
        while (fscanf(file, "%s", temp) != EOF)
        {
            if (flag_first)
            {
                strcpy(buf, temp);
                strcat(buf, "\n");
                flag_first = 0;
            }
            else
            {
                strcat(buf, temp);
                strcat(buf, "\n");
            }
        }
    }

    printf("TEXT = %s\n", buf);
    fclose(file);
    return buf;
}

int write_file(char msg[256], char filename[128])
{ 

    FILE *pLog;
    char buf[256] = "server_";
    strcat(buf,filename);
    pLog = fopen(buf, "w+");
    //write_log("file opened to write");
    if (pLog == NULL)
    {
      // write_log("file opened to write");
        return 1;
    }

    char str[312];
    bzero(str, 312);

    strcpy(str, msg);
    strcat(str, "\n");

    fputs(str, pLog);

    fclose(pLog);

    return 0;
}
