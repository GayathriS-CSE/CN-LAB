#include <stdio.h>
#include <string.h>

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;

    printf("Enter the bucket size:\n");
    scanf("%d", &cap);

    printf("Enter the processing rate:\n");
    scanf("%d", &process);

    printf("Enter the number of seconds you want to simulate:\n");
    scanf("%d", &nsec);

    for (i = 0; i < nsec; i++) {
        printf("Enter the size of the packet entering at %d sec:\n", i + 1);
        scanf("%d", &inp[i]);
    }

    printf("\nSecond | Packet received | Packet sent | Packet left | Dropped\n");
    printf("--------------------------------------------------------------------\n");

    for (i = 0; i < nsec; i++) {
        count += inp[i];

        if (count > cap) {
            drop = count - cap;
            count = cap;
        } else {
            drop = 0;
        }

        mini = min(count, process);
        count -= mini;

        printf("%d", i + 1);
        printf("\t%d", inp[i]);
        printf("\t\t%d", mini);
        printf("\t\t%d", count);
        printf("\t\t%d\n", drop);

        drop = 0;
    }

    // If any packets are left in the bucket after all input seconds
    for (; count != 0; i++) {
        // Process the remaining packets
        mini = min(count, process);
        count -= mini;

        printf("%d", i + 1);
        printf("\t0");  // No incoming packets after the simulation time
        printf("\t\t%d", mini);
        printf("\t\t%d", count);
        printf("\t\t0\n");  // No more dropped packets

        drop = 0;  // No further drops
    }

    return 0;
}

