#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "tr.h"

// Δήλωση της συνάρτησης my_root
double my_root(double nu);

ast_node* create_ast_node(char* operation, ast_node* left, ast_node* right) {
    ast_node* node = malloc(sizeof(ast_node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->operation = operation;
    node->left = left;
    node->right = right;
     // Εκτυπώνετε μόνο τη λειτουργία για απλοποίηση
    //printf("(%s)\n", node->operation);
    return node;
}





void free_ast(ast_node* node) {
    if (node) {
        free_ast(node->left);
        free_ast(node->right);
        free(node);
    }
}




void print_ast(ast_node* node) {
    if (node) {
        if (node->left || node->right) {
           // printf("(");
            print_ast(node->left);
            printf(" %s ", node->operation);
            print_ast(node->right);
            //printf(")");

            // Υπολογίζουμε και εκτυπώνουμε το αποτέλεσμα κάθε πράξης
            printf(" = %.2f", evaluate(node));
            printf("\n");
        } else {
            // Αν ο κόμβος είναι φύλλο, ελέγχουμε αν υπάρχει τιμή
            // Αν είναι NULL, τυπώνουμε 0
            // Διαφορετικά, τυπώνουμε την τιμή του κόμβου
            if (!isnan(node->doubleval)) {
                printf("%.2f ", node->doubleval);
            } else {
                printf("0 ");
            }
        }
    }
}




double evaluate(ast_node *node) {
    if (!node) return 0;

    if (node->operation == NULL) {
        return node->doubleval; // Τα φύλλα είναι αριθμοί
    } else {
        double left_val = evaluate(node->left);
        double right_val = evaluate(node->right);

        if (strcmp(node->operation, "+") == 0) {
            return left_val + right_val;
        } else if (strcmp(node->operation, "-") == 0) {
            return left_val - right_val;
        } else if (strcmp(node->operation, "*") == 0) {
            return left_val * right_val;
        } else if (strcmp(node->operation, "/") == 0) {
            return left_val / right_val;
        } else if (strcmp(node->operation, "^") == 0) {
            return pow(left_val, right_val);
        } else if (strcmp(node->operation, "sqrt") == 0) {
            return sqrt(left_val);
        } else if (strcmp(node->operation, "sin") == 0) {
            return sin(right_val);
        } else if (strcmp(node->operation, "cos") == 0) {
            return cos(right_val);
        } else if (strcmp(node->operation, "tan") == 0) {
            return tan(right_val);
        } else if (strcmp(node->operation, "cot") == 0) {
            return 1 / tan(right_val);
        } else if (strcmp(node->operation, "mod") == 0) {
            return fmod(left_val, right_val);
        } else if (strcmp(node->operation, "!") == 0) {
            double result = 1;
            for (int i = 1; i <= left_val; ++i) {
                result *= i;
            }
            return result;
        }else if (strcmp(node->operation, "root") == 0) {
            return my_root(right_val);
        }else if (strcmp(node->operation, "log") == 0) {
            return log10(right_val);
        }else if (strcmp(node->operation, "NOT") == 0) {
            return !right_val;
        }else if (strcmp(node->operation, "!=") == 0) {
            return !right_val;
        } else if (strcmp(node->operation, "AND") == 0) {
            return left_val && right_val;
        }else if (strcmp(node->operation, "&&") == 0) {
            return left_val && right_val;
        } else if (strcmp(node->operation, "XOR") == 0) {
            return left_val != right_val;
        } else if (strcmp(node->operation, "OR") == 0) {
            return left_val || right_val;
        }else if (strcmp(node->operation, "||") == 0) {
            return left_val || right_val;
        } else if (strcmp(node->operation, "NAND") == 0) {
            return !(left_val && right_val);
        }
    }

    return 0; // Πρέπει να επιστρέψει κάτι, αλλά δεν πρόκειται ποτέ να φτάσει εδώ
}


double my_root(double nu) {
    return sqrt(nu);
}


