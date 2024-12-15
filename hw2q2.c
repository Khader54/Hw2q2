#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 50

// "Enter a positive integer: \n"
//"Binary representation of %d: "
//"The largest sum is: %d\n"


void FlipBin(int binNum[],int numLing)
{
   int temp;
    for (int i = 0; i < (numLing+1)/2; i++)
    {
        temp = binNum[i];
        binNum[i] = binNum[numLing-i];
        binNum[numLing-i] = temp;
    }
}


int NumToBin(int num, int binNum[])
{
    int numLing = MAX_LEN;
    for (int i = 0; i < MAX_LEN; i++)
    {
        binNum[i] = num % 2;
        num = num / 2;
        if(num == 0)
        {
            numLing = i;
            break;
        }
    }
    FlipBin(binNum,numLing);
    return numLing;
}


void Binrep(int binNum[], int numLing, int num)
{
    printf("Binary representation of %d: ", num);
    for (int i = 0; i < numLing+1; i++)
    {
        printf("%d",binNum[i]);
    }
    printf("\n");
}

int SumOfOnes(int binNum[], int numLing)
{
    int oneCnt = 0, maxCnt = 1;
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (binNum[i] == 1)
        {
            int j = i;
            while (binNum[j] == 1)
            {
                oneCnt++;
                j++;
            }
            i = j;
        }
        if (oneCnt > maxCnt)
        {
            maxCnt = oneCnt;
        }
        oneCnt = 0;
    }
    return maxCnt;
}





int main()
{
    int number,numLing,maxSum;
    int binNum[MAX_LEN] = {0};

    printf("Enter a positive integer: \n");
    scanf("%d",&number);

    numLing = NumToBin(number, binNum);
    Binrep(binNum, numLing, number);

    maxSum = SumOfOnes(binNum,numLing);
    printf("The largest sum is: %d\n", maxSum);


    return 0;
}























