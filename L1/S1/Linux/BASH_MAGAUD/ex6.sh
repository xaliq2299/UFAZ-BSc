#!/bin/bash

cut -d ":" -f 1,3,7 /etc/passwd
echo "Number of shells in /etc/passwd: $(cut -d ":" -f 7 /etc/passwd | grep -v "#" | sort | uniq | wc -l)"

