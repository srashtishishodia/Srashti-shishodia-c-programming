#include <stdio.h>

struct Item {
    int id;
    char name[30];
    int qty;
};

int main() {
    struct Item items[50];
    int n = 0, choice, i, searchId, found;

    do {
        printf("\n1.Add  2.Display  3.Search  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID, Name, Quantity: ");
                scanf("%d %s %d", &items[n].id, items[n].name, &items[n].qty);
                n++;
                break;

            case 2:
                printf("\n Items \n");
                for(i = 0; i < n; i++) {
                    printf("ID:%d Name:%s Qty:%d\n",
                           items[i].id, items[i].name, items[i].qty);
                }
                break;

            case 3:
                found = 0;
                printf("Enter ID to search: ");
                scanf("%d", &searchId);

                for(i = 0; i < n; i++) {
                    if(items[i].id == searchId) {
                        printf("Found: %s, Qty:%d\n",
                               items[i].name, items[i].qty);
                        found = 1;
                    }
                }

                if(!found)
                    printf("Item not found\n");
                break;
        }

    } while(choice != 4);

    return 0;
}