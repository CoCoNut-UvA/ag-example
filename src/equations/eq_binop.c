/**
 * @file
 *
 * Equations node: binop
 *
 *
 */

#include "ccngen/equations/binop.h"

/**
 * @fn EVALbinop_this_sum
 */
int EVALbinop_this_sum(int left_sum, int right_sum) {
    return left_sum + right_sum;
}

/**
 * @fn EVALbinop_left_depth
 */
int EVALbinop_left_depth(int this_depth) {
    return this_depth + 1;
}

/**
 * @fn EVALbinop_right_depth
 */
int EVALbinop_right_depth(int this_depth) {
    return this_depth + 1;
}
