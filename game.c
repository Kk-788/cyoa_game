#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct State {
        int optA;
        int optB;
        char optALine[100];
        char optBLine[100];
};

int promptAndGetChoice(struct State currentState) {
        char choice;
        while (1) {
                printf("Enter your choice: ");
                scanf(" %c", &choice);
                // scanf(" %c");
                if (choice == 'a') {
                        return currentState.optA;
                }
                if (choice == 'b') {
                        return currentState.optB;
                }
                printf("Invalid selection. Choose 'a' or 'b'.\n");
        }
}

/*void printFile(int n) {
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
}*/

int getOptionFromLine(char* line) {
        int optionBeginning = -1;
        for (int i = 0; i < strlen(line); i++) {
                if (line[i] == '-' && line[i + 1] == '>') {
                        optionBeginning = i + 3;
                        break;
                }
        }
        char* slice = &line[optionBeginning];
        int option = strtol(slice, NULL, 10);

        // printf("===%d\n", option);

        if (option <= 0) option = -1;
        return option;
}

struct State loadState(int n) {
        struct State state;
        char path[20];

        // open file
        sprintf(path, "../story/%d.txt", n);
        FILE* file = fopen(path, "r");
        if (file == NULL) {
                printf("File not found.\n");
                state.optA = state.optB = -1;
                return state;
        }

        strcpy(state.optALine, "");
        strcpy(state.optBLine, "");

        // print text
        char line[200];
        while (fgets(line, 200, file)) {
                // check if a line is the line presenting Option A
                if (strncmp(line, "a) ", 3) == 0) {
                        break;
                }
                printf("%s", line);
        }

        state.optA = getOptionFromLine(line);
        if (state.optA == -1) {
                return state;
        }
        // printf("Scanned option A: %d\n", state.optA);
        printf("%s", line);

        fgets(line, sizeof(line), file);

        state.optB = getOptionFromLine(line);
        // printf("Scanned option B: %d\n", state.optB);
        printf("%s", line);

        fclose(file);
        return state;
}

int main() {
        int page = 1;
        while (1) {
                struct State state = loadState(page);

                // printf("Loaded option A: %d\n", state.optA);
                // printf("Loaded option B: %d\n", state.optB);

                if (state.optA < 1 || state.optB < 1) break;

                page = promptAndGetChoice(state);

        }
        printf("-----------\n");
}

