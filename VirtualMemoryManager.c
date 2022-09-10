#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
 
//Constraints:
#define PAGE_SIZE 256
#define TOTALPAGES 256
#define PAGE_MASK 255
#define OFFSETBITS 8
#define TOTAL_MEMORY_SIZE 65536
 
//Global variables:
long long addrNum[TOTALPAGES];
char memory[TOTAL_MEMORY_SIZE];
char* backingHandling;

int main(int argc, const char *argv[]){
    
    //Takes in Arguments for file names. 
    //Error Handling:
    if (argc != 2 || argc < 1) {
       perror( "Too many or too few arguments. Program terminating.\n");
        exit(0);
    }

    //Open the input file:
    FILE* fp = fopen(argv[1], "r");
    //Open BACKINGSTORE file:
    int backingFD = open("BACKING_STORE.bin", O_RDONLY);

    //Eror Handling:
    if (fp == NULL) {
        perror("Error opening addresses file. Program terminating.\n");
        exit(0);
    }
    if (backingFD == -1) {
        perror("Error opening BACKING_STORE.bin. Program terminating.\n");
        exit(0);
    }

    //Check if next page available:
    unsigned char pageCheck = 0;

    //Mapping Memory for BACKINGSTORE:
    backingHandling = mmap(0, TOTAL_MEMORY_SIZE, PROT_READ, MAP_PRIVATE, backingFD, 0);

    //If Mapping fails:
    if (backingHandling == MAP_FAILED) {
        perror("Mapping failed. Program terminating.\n");
        exit(1);
    }

    //Populating all page frames with -1:
    for (int i = 0; i < TOTALPAGES; i++) { 
        addrNum[i] = -1; 
    } 
    
    //Buffer for lineRead:
    char lineRead[20];
    
    //Reading addresses file:
    while (fgets(lineRead, 20, fp) != NULL) { 
        //Storing the logical address after converting to int using atoi:
        int logicalAddress = atoi(lineRead);

        //BitMasking:
        int logicMask = logicalAddress & PAGE_MASK;
        int logicOffBit = (logicalAddress >> OFFSETBITS) & PAGE_MASK;
        int physicalAddress = addrNum[logicOffBit];  

        //Incase of Page Fault:
        if (physicalAddress == -1) {
            physicalAddress = pageCheck;
            pageCheck++;

            //Reading from the BACKINGSTORE file, a 256-bute chunk of data, and storing it in memory:
            memcpy(memory + physicalAddress * PAGE_SIZE, backingHandling + logicOffBit * PAGE_SIZE, PAGE_SIZE);
            addrNum[logicOffBit] = physicalAddress;
        }
         
        //Storing the translated address:      
        int resultAddress = (physicalAddress << OFFSETBITS) | logicMask;
        //Calculating the value:
        signed char value = memory[physicalAddress * PAGE_SIZE + logicMask];
         
        printf("Virtual Address: %d  Physical Address:  %d  Value:  %d\n", logicalAddress, resultAddress, value);
    }
    return 0;
}