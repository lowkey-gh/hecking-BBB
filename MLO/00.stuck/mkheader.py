#!/usr/bin/env python3
"""
mkheader.py - Prepend the AM335x ROM bootloader TOC header to a raw binary,
              producing a valid MLO file.

AM335x ROM bootloader (CH header) format:
  Offset  Size  Description
  0x00     4    Image size (bytes, NOT including this 8-byte header)
  0x04     4    Destination load address (where ROM copies the image in SRAM)

Total header = 8 bytes, placed at the very start of the MLO.

Usage:
    python3 mkheader.py mlo_minimal.bin MLO
"""

import struct
import sys
import os

LOAD_ADDRESS = 0x402F0400   # Where ROM will copy & jump to our code : ** Public RAM 

def make_mlo(src_bin: str, dst_mlo: str) -> None:
    with open(src_bin, "rb") as f:
        payload = f.read()

    image_size = len(payload)
    header = struct.pack("<II", image_size, LOAD_ADDRESS)

    with open(dst_mlo, "wb") as f:
        f.write(header)
        f.write(payload)

    print(f"[+] Source binary : {src_bin}  ({image_size} bytes)")
    print(f"[+] Load address  : 0x{LOAD_ADDRESS:08X}")
    print(f"[+] MLO written   : {dst_mlo}  ({os.path.getsize(dst_mlo)} bytes)")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.bin> <output.MLO>")
        sys.exit(1)
    make_mlo(sys.argv[1], sys.argv[2])
