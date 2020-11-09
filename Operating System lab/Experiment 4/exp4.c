#include <stdio.h>
#include <stdlib.h>
int main()
{
    typedef int semaphore;
    semaphore sread = 0, swrite = 0;
    int ch, r = 0;
    printf("\nReader Writer");
    do
    {
        printf("\nMenu");
        printf("\n\t1.Read from file");
        printf("\n\t2.Write to file");
        printf("\n\t3.Exit the reader");
        printf("\n\t4.Exit the Writer");
        printf("\n\t5.Exit");
        printf("\n Enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (swrite == 0)
            {
                sread = 1;
                r += 1;
                printf("\nReader %d reads", r);
            }
            else
            {
                printf("\n Not possible");
            }
            break;
        case 2:
            if (sread == 0 && swrite == 0)
            {
                swrite = 1;
                printf("\nWriter in progress");
            }
            else if (swrite == 1)
            {
                printf("\nWRiter writes the files");
            }
            else if (sread == 1)
            {
                printf("\nCannot write while treader reads the file");
            }
            break;
        case 3:
            if (r != 0)
            {
                printf("\nThe reader %d closes the file", r);
                r -= 1;
                if (r == 0)
                    sread = 0;
            }
            else if (r == 0)
            {
                printf("\n Currently no reader access the file");
                sread = 0;
            }
            break;
        case 4:
            if (swrite == 1)
            {
                printf("\nWriter closes the file");
                swrite = 0;
            }
            else
                printf("\n There is no writer in the file");
            break;
        case 5:
            exit(0);
        }

    } while (ch < 6);

    return 0;
}
