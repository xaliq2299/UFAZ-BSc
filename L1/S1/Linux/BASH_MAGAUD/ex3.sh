#find processor architecture
#find OS release, OS name, OS version 
#check the logmessages in var/log/system.log... for issues related   to AirPort and Ethernet      
#How many messages in system.log
#specific search

#!/bin/bash

echo "Processor arhcitecture: $(uname -p)"
echo "OS release: $(uname -r), OS name: $(uname -s)"
echo "checking the logs"
if [ -f /var/log/kernel.log ]; then 
grep Air[pP]ort /var/log/syslog | grep [Ee]thernet
fi
for i in $(find /var/log/ -name "system.log.*.gz" 2> /dev/null);
do
	sudo gunzip -c $i | wc -l;
done
