// Description: Send signal to child process.
// In sample, click 'q' will send signal to child process to exit.
// 2015.04.27
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// getch() function in Linux.
int Getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    pid_t fpid;

    char *shmaddr;
    struct shmid_ds buf;
    int shmid = shmget(1234, sizeof(char), IPC_CREAT | 0600);

    // initial the shared memory.
    shmaddr = (char* ) shmat(shmid, 0, 0);
    shmaddr[0] = 0;

    fpid = fork();
    if (fpid < 0) {
    } else if (fpid == 0) {
        // Do your job in child process.
        int i = 0;

        // sample
        for (i = 0; i < 99999999; ++i) {
            printf("%d,", i);

            shmaddr = (char* )shmat(shmid, 0, SHM_RDONLY);
            if (shmaddr[0] == 1) {
                break;
            }
            shmdt(shmaddr);
            shmctl(shmid, IPC_RMID, NULL);
        }
    } else {
        // listen to your stdin, and send signal to child process to stop.
        char ch;

        // sample. click 'q' to send exit signal.
        while ((ch = Getch()) != 'q') { printf("%d", ch); };

        shmaddr = (char* ) shmat(shmid, 0, 0);
        shmaddr[0] = 1;
        shmdt(shmaddr);
    }

    return 0;
}

