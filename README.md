<br/>
<div align="center">
  <a href="https://github.com/Afrokk/Airport-Simulator">
    <img src="images/clip.png" alt="Logo" width="315" height="315">
  </a>

  <h3 align="center">Virtual Memory Manager</h3>

  <p align="center">
    Built with Vanilla C on the Linux mMap & POSIX API.
    <br />
    <a href="https://github.com/Afrokk/Virtual-Memory-Manager" target="_blank"><strong>Check it out.»</strong></a>
    <br />
  </p>
</div>

## About The Project

A Virtual Memory Manager implemented using Linux Memory Mapping Library and the POSIX API. It reads in a list of Virtual (logical) addresses and converts them into Physical addresses.

## Built With

Designed and built with C and Linux POSIX API. 

[![C][C.com]][C-url]
[![POSIX][POSIX.com]][POSIX-url]

## How it works
It utilizes bit manipulation and Linux memory mapping library. We start by opening the necessary file descriptors and declaring necessary constraints. 

The implementation starts by setting up the BackingFile, which aids in handling Page Faults. Then, we read the addresses from the address file, which could contain thousands of logical addresses. These addresses are then converted into the correct physical addresses using bit manipulation and masking. Page faults are handled by reading in pages from the BackingFile. All the necessary error handling is also taken care of. Comments are included to further explain the code. 

The program looks at 1000 address in total in sample output (not whole output shown, for obvious reasons). 

<p align="center">
  <img src="https://raw.githubusercontent.com/Afrokk/Virtual-Memory-Manager/main/images/image.png">
</p>

## Contact

Afrasiyab (Afrokk) Khan -  [afrokk.design](https://afrokk.design/home) - [LinkedIn](https://www.linkedin.com/in/afrasiyab-k/) - [@afrokk_](https://www.instagram.com/afrokk_/) - afrasiyabkhan379@gmail.com

ANOTHER PROJECT: Check out <strong>Vintage Autohaus</strong>: [https://github.com/Afrokk/Vintage-Autohaus](https://github.com/Afrokk/Vintage-Autohaus)

[product-screenshot]: images/clip.png
[C.com]: https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[POSIX.com]: https://img.shields.io/badge/mMap-POSIX-blue
[POSIX-url]: https://en.wikipedia.org/wiki/POSIX
