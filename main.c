// Jonathan Chin
// 1/1/2017
// Beyond Guard - Antivirus in C

#include <stdio.h>

#include <database/connect.h>
#include <scanner/scan.h>
#include <util/md5.h>
#include <util/process.h>
#include <unittest/testMD5.h>

int main (int argc, char **argv)
{
    getProcessList();
    int result = connectDB();
    if (result){
        printf("Failed to connect database, aborting...\n");
        return 1; // Can't connect to database
    }
    if (argc != 2){
        perror("Please supply a path to a folder or file.\n");
        return 1;
    }else{
        int pass = scanDirectory(argv[1]);
        if(pass){
            printf("Failed scanning directory for argument %s\n", argv[1]);
        }
    }
    int testResult = testMD5();
    if(testResult){
        printf("Failed unit test");
    }
    closeDB();

    return 0;
}
