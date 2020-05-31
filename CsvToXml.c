#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//first gcc 2017510045 
// after ./a.out contacts.csv output.xml -separator1 -opsys2 -h ////and like that . 


char *replaceWord(const char *s, const char *oldW,const char *newW)//this function for replace word 
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

int main(int argc, char *argv[]) //int  argc,char*argv[]
{
   if(argv[5]==NULL)// for -h is not entered.
   {
       argv[5]="";
   }
    


    char separator[] = ",";
    char endOfLine[]="\n";
     // for choose  separator . 
    if (strcmp("-separator1", argv[3])==0)//,
        strcpy(separator, ",");
    else if (strcmp("-separator2", argv[3])==0)//tab
        strcpy(separator, "\t");
    else if (strcmp("-separator3", argv[3])==0)//;
        strcpy(separator, ";");

        if (strcmp("-opsys1", argv[4])==0) // for windows 
        {   
            strcpy(endOfLine, "\r\n");
            if(strcmp("-h", argv[5])==0){
        printf("%s","-----------------Hello------------------- \r\n This porgram provide read csv and applied information to  xml properly \r\n 1- first gcc 2017510045 \r\nafter ./a.out csv name  output file name (xml ) \r\n -separator1 split csv with ',' \r\n -separator2 split csv with 'tab'\r\n -separator3 split csv with ';'  \r\n\r\n-opsys1 change end of the line // for windows \r\n-opsys2 change end of the line // for Macos and linux\r\n-opsys3 change end of the line // for macos  under 9.0 ");       
        }
        }
        else if (strcmp("-opsys2", argv[4])==0)//macos and linüx (it is work properly on mac os 10)
        {strcpy(endOfLine, "\n");
        if(strcmp("-h", argv[5])==0){
        printf("%s","-----------------Hello------------------- \n This porgram provide read csv and applied information to  xml properly \n 1- first gcc 2017510045 \nafter ./a.out csv name  output file name (xml ) \n -separator1 split csv with ',' \n -separator2 split csv with 'tab'\n -separator3 split csv with ';'  \n\n-opsys1 change end of the line // for windows \n-opsys2 change end of the line // for Macos and linux\n-opsys3 change end of the line // for macos  under 9.0 ");       
        }
        }
        else if (strcmp("-opsys3", argv[4])==0)//macos  under 9.0 (I write this code on macos 10 and it is not work properly )
         {strcpy(endOfLine, "\r");
         if(strcmp("-h", argv[5])==0){
        printf("%s","-----------------Hello------------------- \r This porgram provide read csv and applied information to  xml properly \r 1- first gcc 2017510045 \rafter ./a.out csv name  output file name (xml ) \r -separator1 split csv with ',' \r-separator2 split csv with 'tab'\r -separator3 split csv with ';'  \r\r-opsys1 change end of the line // for windows \r-opsys2 change end of the line // for Macos and linux\r-opsys3 change end of the line // for macos  under 9.0 ");       
        }
         }
    
    FILE *creatXml;

    /*first file which will be  written  are created. */
    creatXml = fopen(argv[2], "w");

    /*first file was readed.*/
    FILE *fp = fopen(argv[1], "r");
    char buf2[1024];
    char *buf = NULL;

    if (!fp)
    {
        printf("Can't open file");//if File is not find . 
        printf(endOfLine);
        return 1;
    }

    int check = 0;
    int row_id = 0;// row counter. 
    fputs("<contacts>", creatXml);
    fputs(endOfLine, creatXml);
    while (fgets(buf2, 1024, fp))
    {
        // for ,, 
        if (strcmp("-separator1", argv[3])==0)
        {
            buf = replaceWord(buf2, separator, ", ");// for seperator 1 . 
        }
        else
        {
            buf = replaceWord(buf2, separator, separator);// for another seperator.
        }
        

        char *token = strtok(buf, separator);

        if (check == 0)// for first row. 
        {

            check++;
        }

        else
        {
            row_id += 1;

            fputs("<row id=”", creatXml);
            fprintf(creatXml, "%d", row_id);
            fputs("”>", creatXml);
              
            int i = 0;
            // arguments are written on xml. 
            while (token != NULL)
            {

                fputs(endOfLine, creatXml);
                // fputs(row_id,creatXml);

                if (i == 0)
                {
                    
                    fputs("<first_name>", creatXml);
                    fputs(token, creatXml);

                    fputs("</first_name>", creatXml);
                    
                    i++;
                }
                else if (i == 1)
                {

                    fputs("<last_name>", creatXml);
                    fputs(token, creatXml);
                    fputs("</last_name>", creatXml);
                   
                    i++;
                }
                else if (i == 2)
                {
                    fputs("<email>", creatXml);
                    fputs(token, creatXml);
                    fputs("</email>", creatXml);
                    
                    i++;
                }
                else if (i == 3)
                {
                    fputs("<phone_number>", creatXml);
                    fputs(token, creatXml);
                    fputs("</phone_number>", creatXml);
                    
                    i++;
                }
                else if (i == 4)
                {
                    fputs("<address>", creatXml);
                    fputs(token, creatXml);
                    fputs("</address>", creatXml);
                    
                    i++;
                }

                token = strtok(NULL, separator);
            }

            fputs(endOfLine, creatXml);
            fputs("</row>", creatXml);
            fputs(endOfLine, creatXml);
        }
    }
    fputs("</contacts>", creatXml);

    fclose(fp);
   
    return 0;
}
