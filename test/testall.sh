#!/bin/bash
for dirs in */ ; do
  ../obj/assembler ${dirs}/src.asm ;
done
