#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces"
           "item %d",
           x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes "
           "item %d",
           x);
    x--;
    ++mutex;
}

int main()
{
    int n;
    printf("\nPress 1 for Producer"
           "\nPress 2 for Consumer"
           "\nPress 3 for Exit");

    while (1)
    {

        printf("\nEnter your choice:");
        scanf("%d", &n);

        if (n > 3)
        {
            printf("\n Invalid choice");
        }
        else
        {
            // Switch Cases
            switch (n)
            {
            case 1:
                if ((mutex == 1) && (empty != 0))
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full!");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                {
                    consumer();
                }
                else
                {
                    printf("Buffer is empty!");
                }
                break;
            case 3:
                printf("Exited successfully");
                exit(0);
                break;
            }
        }
    }
}
