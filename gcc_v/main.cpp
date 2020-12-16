#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("%d\n",__GNUC__);
    printf("%d\n",__GNUC_MINOR__);
    printf("%d\n",__GNUC_PATCHLEVEL__);
    return 0;
}