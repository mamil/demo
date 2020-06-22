#include <iostream>
#include <string.h>

#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // create socket
    struct sockaddr_in servaddr;

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(9999);
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        std::cout << "bind error";
        return -1;
    }

    // epoll
    int epollfd;
    struct epoll_event events[1024];
    int ret;
    char buf[1024];
    memset(buf, 0, 1024);
    //创建一个描述符
    epollfd = epoll_create(1024);
    //添加监听描述符事件
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listenfd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev);

    for (;;)
    {
        //获取已经准备好的描述符事件
        ret = epoll_wait(epollfd, events, 1024, -1);
        if (ret == -1)
        {
            perror("epoll_pwait");
            return -1;
        }

        for (int n = 0; n < ret; ++n)
        {
            if (events[n].data.fd == listenfd)
            {
                //主监听socket有新连接
                struct sockaddr_in cliaddr;
                socklen_t cliaddrlen;
                int clientfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddrlen);
                if (clientfd == -1)
                {
                    perror("accept");
                    return -1;
                }
                else
                {
                    std::cout << "accept a new client: " << inet_ntoa(cliaddr.sin_addr) << " port:" << cliaddr.sin_port;
                    struct epoll_event ev;
                    ev.events = EPOLLIN;
                    ev.data.fd = clientfd;
                    epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &ev);
                }
            }
            else
            {
                //已建立连接的可读写句柄
                
            }
        }
    }
    close(epollfd);

    return 0;
}
