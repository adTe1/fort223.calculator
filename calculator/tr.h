#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ast_node {
    char* operation;
    double doubleval;
    struct ast_node *left;
    struct ast_node *right;
} ast_node;


ast_node* create_ast_node(char* operation, ast_node* left, ast_node* right);
void free_ast(ast_node* node);
void print_ast(ast_node* node);
double evaluate(ast_node *node);


#endif /* TREE_H */