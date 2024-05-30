/*
* Program Name: client.cpp
* Author: Elijah Sprung
* Date: 12/07/2023
* Location: ~/csc4310/client
* Description: A client-side network program written in C++ that uses the ncurses library for terminal-based user interfaces and
*	       signal-driven I/O for server reads. It connects to a server, sends messages input by the user, and prints messages
*              received from the server.
* Compilation Line: g++ client.cpp -o client -lncurses
* Execution Line: ./client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ncurses.h>
#include <signal.h>
#include <fcntl.h>

#define PORT 8080
#define LOCALHOST "127.0.0.1"
#define MESSAGE_LENGTH 1024

// structure to hold the socket descriptor and message window
typedef struct {
    int socket_descriptor;
    WINDOW *message_window;
} ClientData;

// signal handler for SIGIO
void sigio_handler(int signo, siginfo_t *si, void *ucontext)
{
    // get the ClientData structure for this client
    ClientData *client_data = (ClientData *)si->si_value.sival_ptr;

    char buffer[MESSAGE_LENGTH];
    
    // read the incoming message
    read(client_data->socket_descriptor, buffer, MESSAGE_LENGTH);
    
    // print the message to the message window
    wprintw(client_data->message_window, "Server: %s\n", buffer);
    wrefresh(client_data->message_window);
}

int main()
{
    struct sockaddr_in server_address;
    char message_buffer[MESSAGE_LENGTH] = {0};

    // allocate memory for the client data
    ClientData *client_data = (ClientData *)malloc(sizeof(ClientData));

    // create socket
    if ((client_data->socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, LOCALHOST, &server_address.sin_addr)<=0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(client_data->socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // set the socket to non-blocking mode and enable signal-driven I/O
    int flags = fcntl(client_data->socket_descriptor, F_GETFL);
    fcntl(client_data->socket_descriptor, F_SETFL, flags | O_NONBLOCK | O_ASYNC);

    // set the process to receive SIGIO signals from the socket
    fcntl(client_data->socket_descriptor, F_SETOWN, getpid());

    // install the signal handler for SIGIO
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigio_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGIO, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // initialize ncurses
    initscr();
    cbreak();
    noecho();

    // create windows
    WINDOW *input_window = newwin(1, COLS, LINES - 1, 0);
    client_data->message_window = newwin(LINES - 1, COLS, 0, 0);
    scrollok(client_data->message_window, TRUE);

    // send messages
    while(1)
    {
        mvwgetnstr(input_window, 0, 0, message_buffer, MESSAGE_LENGTH);
        send(client_data->socket_descriptor, message_buffer, strlen(message_buffer), 0);
        memset(message_buffer, 0, sizeof(message_buffer));
    }

    // deinitialize ncurses
    endwin();

    // free the client data
    free(client_data);

    return 0;
}