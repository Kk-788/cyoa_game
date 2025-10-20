#include <stdio.h>

struct State {
        int opt1;
        int opt2;
};

int getNextState(struct State currentState) {
        char choice;
        while (1) {
                printf("Enter your choice: ");
                scanf("%c", &choice);
                if (choice == 'a') {
                        return currentState.opt1;
                }
                if (choice == 'b') {
                        return currentState.opt2;
                }
                printf("Invalid selection. Choose 'a' or 'b'.\n");
        }
}

void printFile(int n) {
        // create file path
        char path[10];
        sprintf(path, "../story/%d.txt", n);
        printf("%s", path);

        // open file
        FILE* file = fopen(path, "r");
        if (file == NULL) {
                printf("File not found.\n");
                return;
        }

        char line[200];
        while (fgets(line, 200, file)) {
                // TODO: em dashes turn into ΓÇö (encoding error?)
                printf("%s", line);
        }
        fclose(file);
}


int main() {
        struct State currentState = {2, 3};
        int page = getNextState(currentState);
        printf("%d\n", page);
        printFile(1);
}