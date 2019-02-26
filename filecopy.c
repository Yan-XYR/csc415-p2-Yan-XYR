#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //

int
main(int argc, char const *argv[])
{   
    char input_file_name[30], output_file_name[30], buf[BUFF_MAX];
    int bytes_copied = 0;
    int open_file, write_file;
    ssize_t bytes_to_read;    

    printf("Welcome to the File Copy Program by Yanrui Xu!\n");
    //prompts the user for input file name
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", input_file_name);
    //prompts the user for output file name
    printf("Enter the name to the file to copy to:\n");
    scanf("%s", output_file_name);

    open_file = open(input_file_name, O_RDONLY); //opens input file
    if(open_file < 0){
        perror("Error:");
        exit(1);
    }

    write_file = open(output_file_name, O_WRONLY | O_CREAT | O_EXCL, 777); //creates output file
    if(write_file < 0){
        perror("Error:");
        exit(1);
    }

    while(bytes_to_read = read(open_file, buf, BUFF_MAX) > 0){
        write(write_file, buf, bytes_to_read);
        bytes_copied++;
    }

    //return result
    printf("File Copy Successful, %d bytes copied", bytes_copied);
    close(open_file);
    close(write_file);    

    return 0;
}
