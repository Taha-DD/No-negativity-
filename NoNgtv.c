#include<stdio.h>
#include<stdlib.h>

void swap ( double *a, double *b )
{
    *a = *a + *b - ( *b = *a );
}

/*int getback ( double *p, int u )
{
    int s = 0;
    while (u--)
        for (double *v = p, *n = p + u; v < p + u; v++)
            if (*v < 0){
                swap(v, n--);
                s++;
            }
    return u - s;        
}*/
// you can use this too but I can't assure it'll work for all cases 
int getback ( double *p, int N )
{
    int s = 0;
    for( double *v = p; v < p + N; v++ )
    {
        if(*v >= 0)
        {
            p[s] = *v;
            s++;
        }
    }
    return s;        
}


void scanner ( double *p, int N )
{
    for( double *v = p; v < p + N; v++ )
    {
        printf(" give %d value: ", v - p);
        scanf("%lf", v);
    }
}

int main()
{
    double *p;
    int N, counter;
    
    printf("N = ");
    scanf("%d", &N);
    
    p = (double *)malloc(N * sizeof(double));
    
    if ( p == NULL )
        exit (1);
    
    scanner(p, N);
    
    counter = getback(p, N);
    
    p = (double *)realloc( p, counter * sizeof(double) );
    
    if ( p == NULL )
        exit (1);
        
    for( double *v = p; v < p + counter; v++ )
        printf("%lf ", *v);
    
    free(p);
    p = NULL;
    
    return 0;
}
