#!/bin/bash
./globalbank | cut -d ' ' -f 2- > user.log
cat 19920104_091532.log | cut -d ' ' -f 2- > test.log
diff -u user.log test.log > cp.log
if [ $? -eq 0 ]
then
    printf "Test pass.\n"
else
    printf "Test fail.\n"
fi
