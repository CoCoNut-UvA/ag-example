#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/visit.h"

// What to do when a breakpoint is reached.
void BreakpointHandler(node_st *root) {
    TRAVstart(root, TRAV_PRT);
}

int main(int argc, char **argv) {
    node_st *leaf1 = ASTleaf(1);
    node_st *leaf2 = ASTleaf(2);
    node_st *leaf3 = ASTleaf(3);
    node_st *leaf4 = ASTleaf(4);
    node_st *leaf5 = ASTleaf(5);

    node_st *binop1 = ASTbinop(leaf1, leaf2);
    node_st *binop2 = ASTbinop(leaf3, leaf4);
    node_st *binop3 = ASTbinop(binop1, binop2);
    node_st *binop4 = ASTbinop(binop3, leaf5);

    node_st *prog = ASTprog(binop4);

    CCNrun(prog);
    return 0;
}
