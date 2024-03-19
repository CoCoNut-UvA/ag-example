/**
 * @file
 *
 * Traversal: print
 * UID      : PRT
 *
 *
 */
#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

#include "ccngen/ag.h"
#include "ccngen/visit.h"

/**
 * @fn PRTprog
 */
node_st *PRTprog(node_st *node)
{
    CCNevaluateAttributes(node);
    printf("Tree sum: %d\n", PROG_SUM(node));
    TRAVtree(node);
    printf("\n");
    return node;
}

/**
 * @fn PRTbinop
 */
node_st *PRTbinop(node_st *node)
{
    printf("(");
    TRAVleft(node);
    printf(" + ");
    TRAVright(node);
    printf(")");
    printf(" <depth: %d>", BINOP_DEPTH(node));
    return node;
}

/**
 * @fn PRTleaf
 */
node_st *PRTleaf(node_st *node)
{
    printf("%d", LEAF_VAL(node));
    printf("<depth: %d>", LEAF_DEPTH(node));
    return node;
}
