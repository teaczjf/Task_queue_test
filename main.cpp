#include <stdio.h>
#include "test.h"
#include "test2.h"
#include <iostream>
#include "my_easylogging.h"
#include "my_tak_queue.h"

// #define HDDD
int main()
{
    easylogginginit(); //日志初始化

    AsyncExecQueue *my_queue = new AsyncExecQueue();

    //使用智能指针
    shared_ptr<Task>
        A = make_shared<Task>("A");
    shared_ptr<Task> B = make_shared<Task>("B");
    shared_ptr<Task> C = make_shared<Task>("C");

    //启动任务队列
    my_queue->start();

    //将任务放入任务队列
    my_queue->push(A);
    my_queue->push(B);
    my_queue->push(C);

    //等待所有任务执行完毕
    while (my_queue->size() > 0)
    {
        std::chrono::milliseconds dura(1);
        std::this_thread::sleep_for(dura);
    }

    return 0;
}
