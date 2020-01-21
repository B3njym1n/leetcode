#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bar {
    unsigned hash;
    void *value;
    struct bar *next;
};

struct foo {
    unsigned hash;
    void *value;
};

struct map_node {
    unsigned hash;
    void *value;
    struct map_node *next;
};

typedef struct map_node map_node;

static unsigned map_hash(const char *str) {
    unsigned hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) ^ *str++;
    }
    return hash;
}

int main()
{
    //char *str = "wwg1wga";
    char *str = "wwg1wgawwg1wgawwg1wga";
    int ssize = strlen(str) + 1;
    int vsize = sizeof(int);
    printf("ssize: %d\n", ssize);
    printf("sizeof void*: %ld\n", sizeof(void*));
    int value = 123;
    // int offset = ssize + ((sizeof(void*) - ssize) % sizeof(void*));
    int offset = ssize + ((sizeof(void*) - ssize) % sizeof(void*));
    printf("offset is %d\n", offset); 
    map_node *node;
    node = malloc(sizeof(*node) + offset + vsize);
    memcpy(node + 1, str, ssize);
    unsigned hash = map_hash(str);
    printf("hash: %d\n", hash);
    node->hash = hash;
    node->value = ((char*) (node + 1)) + offset;
    memcpy(node->value, &value, vsize);
    printf("sizeof map_node: %ld\n", sizeof(struct map_node));
    printf("%s\n", (char*)(node+1));
    printf("%d\n", node->hash);
    int *disp = node->value;
    printf("%d\n", *disp);
    void *p = malloc(ssize);
    memcpy(p, str, ssize);

    /**
    int bi = 0b100;
    int oc = 0100;
    int he = 0x100;
    printf("%ld\n", sizeof(struct bar));
    printf("%ld\n", sizeof(struct foo));
    printf("%ld\n", sizeof(void*));
    printf("%d\n", ssize);
    printf("%d\n", bi);
    printf("%d\n", oc);
    printf("%d\n", he);
    **/
    printf("%s\n", (char*) p);
    free(p);
    return 0;
}
