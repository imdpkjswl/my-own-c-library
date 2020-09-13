#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#ifndef BigInteger
// Function to convert character to integer value
int chrToint(char a){
    int i;
    for (i = 48; i<=57; i++)
        if (toascii(i)==a)
            return i-48;
    return 0;
}

// Function to perform addition on large integer value
char* largesum(char n1[], char n2[])
{
    int r[101];
    int l1, l2;
    int i, j, k, carry =0, sum;

    l1 = strlen(n1);
    l2 = strlen(n2);

    strrev(n1);
    strrev(n2);

    k = l1>l2?l1:l2;

    for(i=0; i< k; i++)
    {
        if(l1==l2 || (i < l1 && i < l2))
            sum = chrToint(n1[i])+chrToint(n2[i]) + carry;
        else if(i >=l1)
            sum = chrToint(n2[i]) + carry;
        else if(i >=l2)
            sum = chrToint(n1[i]) + carry;

        r[i] = sum%10;
        carry = sum/10;
    }

    if(carry > 0){
        r[i] = carry;
        i++;
    }


    char* result = malloc(102);  // char array to store result
    printf("\nSum of %s and %s =  ",strrev(n1),strrev(n2));
    for(j=0; j < i; j++){
        *(result+j) = r[i-j-1] + 48; // convert int array to char array
    }
    *(result+j) = '\0';

    return result;
}


#define BigInteger
#endif // BigInteger
