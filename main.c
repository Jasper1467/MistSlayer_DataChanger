#include "des.h"

#include <stdio.h>
#include <string.h>

#define MISTSLAYER_KEY ("DG6sd51d") // I'm in the mainframe
// iv = d58D4g2D

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <operation> <file>\n", argv[0]);
        return -1;
    }

    char *operation = argv[1];
    char *file = argv[2];

    FILE *f = fopen(file, "wb");
    if (!f)
    {
        printf("Could not open file %s\n", file);
        return -1;
    }

    char buffer[4096];
    fread(buffer, sizeof(buffer), sizeof(buffer), f);
    fclose(f);

    key_set set;
    generate_sub_keys(MISTSLAYER_KEY, &set);

    char processed[4096];

    if (strcmp(operation, "enc") == 0)
        process_message(buffer, processed, &set, ENCRYPTION_MODE);
    else if (strcmp(operation, "dec") == 0)
        process_message(buffer, processed, &set, DECRYPTION_MODE);
    else
    {
        printf("Usage: %s <operation> <file>\n", argv[0]);
        return -1;
    }

    fwrite(processed, 1, sizeof(processed), f);

    fclose(f);

    return 0;
}