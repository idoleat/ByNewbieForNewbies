struct BigNum
{
    unsigned long long upper, lower;
};

static inline void BigNum_Add(struct BigNum *result,struct BigNum *A, struct BigNum *B)
{
    result->upper = A->upper + B->upper;
    // A->lower + ~A->lower = ~0
    // ~A->lower = ~0 - A->lower, ~A->lower is distance between A->lower and 0
    // if B->lower is greater than ~A->lower, it means the adding result of two lowers will overflow
    // if overflow than upper needs to take the carry.
    if (B->lower > ~A->lower)
        result->upper++;
    result->lower = A->lower + B->lower;
}