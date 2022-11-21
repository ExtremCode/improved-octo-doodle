#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_SIZE 1024

int main (int argc, char * argv[])
{
    int descriptors[2]; //оба дескриптора канала; 0 ? для чтения, 1 ? для записи
    pid_t pid;
    pipe(descriptors); //возврат дескрипторов файлов для чтения и данных из канала
    // и записи данных в канал

    pid = fork(); //вызов функции ?раздвоения? процесса на родительский и дочерний код раздваивается

    if ( pid > 0 ) //родительский процесс
    {
        char symb[] = "Hello there!\n";
        int length = sizeof(symb);
        close(descriptors[0]); //закрытие дескриптора для чтения
        write(descriptors[1], symb, length + 1); //запись строки в файл, по дескриптору для записи
        close(descriptors[1]); //разрыв связи с дескриптором для записи
    }
    else if(pid == 0)//дочерний процесс
    {
        char buf[BUF_SIZE];
        int len;
        close(descriptors[1]); //закрытие дескриптора для записи
        while ((len = read(descriptors[0], buf, BUF_SIZE)) > 0){
            printf("%s", buf);
            close(descriptors[0]); //разрыв связи с дескриптором чтения
        }
    }
    else{
        return 1;
    }

    return 0;
}
