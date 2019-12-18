#include<stdio.h>
#include<stdlib.h>

int is_prime(int num)  // calculate prime number
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }  
     return 1;
}
//----------------------------------------------------------
int function1(int arrA[15][20], int arrB[])  // return size of B
{



int array_length = 0;
int i,j;
for(i = 0; i < 15; i++){
    for(j = 0 ;j < 20; j++){
         if(is_prime(arrA[i][j])){
              arrB[array_length++] = arrA[i][j];
          }
     }
  }

return array_length;
}
//----------------------------------------------------------
void function2(int arrB[], int sizeB){  
int temp;
printf("Array B :\n");
 for(int j=0;j<sizeB;j++) {
         printf("%d ", arrB[j]);   // print original B
}
printf("\n");
 for(int i = 0; i < sizeB; i++)
    {
        for(int j = i+1; j < sizeB; )
        {
            if(arrB[j] == arrB[i])
            {
                for(int k = j; k < sizeB; k++)
                {
                    arrB[k] = arrB[k+1];
                }
                sizeB--;
            }
            else
            {
                j++;
            }
        }
    }


printf("Array B without duplicates:\n");

for(int i=0; i<sizeB; i++)
    {
        for(int j=i+1; j<sizeB; j++)
        {
            if(arrB[i] > arrB[j])
            {
                temp     = arrB[i];
                arrB[i] = arrB[j];
                arrB[j] = temp;
            }
        }
    }
for(int i = 0; i < sizeB; i++)
    {
        printf("%d ", arrB[i]);  // print in ascending order
    }
}
//----------------------------------------------------------
int main()
{
int A[15][20];
int B[300];
int size_B;
for (int i = 0; i <15; i++){		//initialize A with random numbers
        for(int k = 0; k < 20; k++){
            A[i][k] = rand() % 100;
        }     
    }
printf("Array A:\n");
for(int i=0; i<15; i++) {			//print elements of A
      for(int j=0;j<20;j++) {
         printf("%d ", A[i][j]);
        
      }
   }
printf("\n");
size_B=function1(A,B);

function2(B,size_B);
return 0;

}
