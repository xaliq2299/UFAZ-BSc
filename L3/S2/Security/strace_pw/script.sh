#!/bin/bash
echo "a" > foo.txt
echo "bc" >> foo.txt
echo ‘id -urn‘ >> foo.txt
chmod 750 foo.txt
cat foo.txt | wc
chmod 644 foo.txt