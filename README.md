# Virtual-Memory-Manager
A Virtual Memory Manager implemented using Linux Memory Mapping Library. It reads in a list of Virtual (logical) addresses and converts them into Physical addresses.

<p align="center">
  <img src="https://raw.githubusercontent.com/Afrokk/Virtual-Memory-Manager/main/images/image.png">
</p>

It utilizes bit manipulation and Linux memory mapping library. We start by opening the necessary file descriptors and declaring necessary constraints. Comments are included to further explain the code. 

The implementation starts by setting up the BackingFile. Then, we read the addresses from the file. These addresses are then converted into the correct physical addresses using bit manipulation and masking. Page faults are handled by reading in pages from the BackingFile. All the necessary error handling is also taken care of.
The program looks at 1000 address in total in sample output. 
