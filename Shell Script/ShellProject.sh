#!/bin/bash
OLDIFS=$IFS
touch FinalReport.csv
mydirectory="$(pwd)"
echo "UserName,EId,Repository link,Git-clone status,Build-status,Valgrind,cppcheck" >>"$mydirectory"/FinalReport.csv
while IFS="," read  Name EmailID Repolink; do 

	echo "$Name $EmailID $Repolink" 
	
	git clone $Repolink >>"$mydirectory"/gitclone.txt
	if [ $? -eq 0 ];then
  		echo -n "$Name,$EmailID,$Repolink,Pass," >>"$mydirectory"/FinalReport.csv
  		
 	else 
 		echo -n "$Name,$EmailID,$Repolink,Fail," >>"$mydirectory"/FinalReport.csv
	fi

	repo="$(cut -d"/" -f5 <<<"$Repolink")"
	repofull="$(cut -d"." -f1 <<<"$repo")"
	echo "my pwd is: $mydirectory" 
	echo "my repository is :$repofull"
	cd "$mydirectory"/"$repofull"
	
	make >> "$mydirectory"/make.txt
	
	if [ $? -eq 0 ]; then
  		echo  -n "Build Success," >>"$mydirectory"/FinalReport.csv
  		
 	else 
 		echo -n "Build Failed," >>"$mydirectory"/FinalReport.csv
	fi
	
	
	
       valgrind ./*.out >"$mydirectory"/valgrind.txt 2>&1
       lastline="$( tail -n 1 "$mydirectory"/valgrind.txt)"
       errors="$(cut -d" " -f4 <<<"$lastline")"
       echo -n "$errors," >>"$mydirectory"/FinalResults.csv

       cppcheck *.c* >"$mydirectory"/cppreport.txt 2>&1
       echo "$(grep -o 'error' "$mydirectory"/cppreport.txt| wc -l)" >>"$mydirectory"/FinalReport.csv
	
       cd "$mydirectory" 
       IFS=$OLDFIS
 	
done<$1

 
 
 

