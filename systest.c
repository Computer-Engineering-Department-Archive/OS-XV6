#include "types.h"
#include "stat.h"
#include "user.h"

// function declare
void tickstest(void);

int main(void)
{
    tickstest();
    printf(1, "successful\n");
    exit();
}

void tickstest(void)
{
    // allocate 10 bits because max int has 10 digits
    printf(1, "%d\n", recticks());
}