#include "types.h"
#include "stat.h"
#include "user.h"
 
int mutex = 1;
int full = 0;
int empty = 10, x = 0;

void producer()
{
    --mutex;
 
    ++full;
    --empty;
 
    x++;
    printf(1, "\nProducer produces"
           "item %d",
           x);
 
    ++mutex;
}

void producer_run()
{
    if ((mutex == 1) && (empty != 0)) {
        producer();
    } else {
        printf(1, "Buffer is full!");
    }
}
 
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf(1, "\nConsumer consumes "
           "item %d",
           x);
    x--;
 
    ++mutex;
}

void consumer_run()
{
    if ((mutex == 1) && (full != 0)) {
        consumer();
    }
    else {
        printf(1, "Buffer is empty!");
    }
}
 

int main() {
    int tid = thread_creator(producer_run, 0);
    thread_join(tid);

    int tid2 = thread_creator(consumer_run, 0);
    thread_join(tid2);

    printf(1, "\n");

    exit();
}