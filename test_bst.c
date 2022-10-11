#include <stdio.h>
#include <assert.h>

#include "bst.h"

struct _Node {
    struct _Node* left;
    struct _Node* right;
    int value;
};

int main() {

    printf("Original test case 1: testing removeNode\n");
    Node *a, *b;
    a = addNode(NULL, 42);
    b = removeNode(a, 42);
    assert(b == NULL);
    printf("test passed\n");

    printf("Original test case 2: testing a 1 2 tree\n");
    a = addNode(NULL, 1);
    b = addNode(a, 2);
    displaySubtree(a);
    printf("-\nthe output should be\n1\n2\n-\n");

    printf("Original test case 3: testing numberLeaves\n");
    int c = numberLeaves(a);
    assert(c == 1);
    printf("test passed\n");

    printf("Original test case 3: testing nodeDepth\n");
    c = nodeDepth(a, b);
    assert(c == 1);
    printf("test passed\n");

    printf("Removing the entire tree to prevent memory leak\n");
    a = removeSubtree(a, 1);

    printf("--\nNow on to custom test cases (CTC)\n");

    printf("CTC1: Test if left side greater than right side\n");
    Node *n1, *n2, *n3;
    n1 = addNode(NULL, 5);
    n2 = addNode(n1, 6);
    n3 = addNode(n1, 4);
    assert(n1->left->value == 6);
    assert(n1->right->value == 4);
    printf("test passed\n");

    printf("CTC2: Test the structure of RBST of 5 6 4 3\n");
    n2 = addNode(n1, 3);
    assert(n1->right->right->value == 3);
    printf("test passed\n");

    printf("CTC3: Test numberLeaves correct, n1 should have 3 leaves\n");
    assert(numberLeaves(n1) == 3);
    printf("test passed\n");

    printf("CTC4: Test adding a duplicate node, should not add anything and return NULL\n");
    n3 = addNode(n1, 3);
    assert(n3 == NULL);
    assert(numberLeaves(n1) == 3);
    printf("test passed\n");

    printf("CTC5: Test nodeDepth normal case\n");
    c = nodeDepth(n1, n2);
    assert(c == 2);
    printf("test passed\n");

    printf("CTC5: Test nodeDepth case when node is not inside root\n");
    c = nodeDepth(n1->left, n2);
    assert(c == -1);
    printf("test passed\n");

    printf("CTC6: Test displaySubtree\n");
    displaySubtree(n1);
    printf("-\nthe output should be\n3\n4\n5\n6\n-\n");

    printf("CTC7: Test removeNode, remove 6\n");
    n2 = removeNode(n1, 6);
    assert(n2 == n1);
    assert(n1->left == NULL);
    printf("test passed\n");

    printf("Removing the entire tree to prevent memory leak\n");
    a = removeSubtree(n1, 5);

    return 0;
}
