#include <stdio.h>
#include <stdlib.h>
#include "../src/List.h"
#include "../src/minunit.h"

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_push() {
    List_push(list, test1 );
    List_push(list, test2 );
    List_push(list, test3 );
    LIST_FOREACH(list, first, next, curr) {
        printf("%s \n", curr->value);
    }
    return NULL;
}

char *test_reverse() {
    List_reverse(list);
    LIST_FOREACH(list, first, next, curr) {
        printf("%s \n", curr->value);
    }
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    list = List_create();
    mu_run_test(test_push);
    mu_run_test(test_reverse);

    return NULL;
}

RUN_TESTS(all_tests);
