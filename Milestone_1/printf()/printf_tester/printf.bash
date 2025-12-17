#!/bin/bash

GREEN="\033[1;32m"
RED="\033[31m"
BRED="\033[1;31m"
BLUE="\033[34m"
BBLUE="\033[1;34m"
RESET="\033[00m"
rm -rf Text
mkdir Text

printheader(){
   local titel="$@"
   local titellen=${#titel}
   printf $BBLUE"========= "$RESET
   printf $BBLUE"$titel"$RESET
   local totallen=$((60-titellen))
   printf $BBLUE"%.*s\n"$RESET $totallen " ==========================================================="
}

printf ""$BLUE"TESTER MADE BY @JBUCHINS\nEmail: jbuchins@student.42Wolfsburg.de\n\n$RESET"

printf ""$BBLUE"COMPILE AND CRASH TEST\n\n$RESET"

printheader CHAR Test
errorcount=0
testlen=0

for i in {a..z} {A..Z} {0..9}
 do
 ./a.out "CHAR" "$i"              > ./Text/CHECK
  status=$?
if ((status > 0))
    then
    printf "$RED[KO]$RESET\n"
    echo -e "[CRASH]FATAL ERROR in CHAR\nCase: '"$i"'\n------------\n"
    echo -e "[CRASH]FATAL ERROR in CHAR\nCase: '"$i"'\n------------\n" >> ./Text/CRASHLOG.txt
    echo -e $RED"Skipping the rest of the Category\n"$RESET
    ((errorcount++))
    break
else
   len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
   printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
   cat ./Text/CHECK         >> ./Text/CHAR.txt
fi
done

printf "\n\n"
printheader STRING Test
testlen=0

strings=("if you can read this you have failed"
"This is the best test String"
"I can't believe you've done this"
"Backup Terry"
"How could this happen to me"
"Core Dumped -> deleting system 32"
"Last String of the day"
"You are done"
"RATIOED"
"Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Sed lectus. Donec mollis hendrerit risus. Phasellus nec sem in justo pellentesque facilisis. Etiam imperdiet imperdiet orci. Nunc nec neque. Phasellus leo dolor, tempus non, auctor et, hendrerit quis, nisi. Curabitur ligula sapien, tincidunt non, euismod vitae, posuere imperdiet, leo. Maecenas malesuada. Praesent congue erat at massa. Sed cursus turpis vitae tortor. Donec posuere vulputate arcu. Phasellus accumsan cursus velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed aliquam, nisi quis porttitor congue, elit erat euismod orci, ac placerat dolor lectus quis orci. Phasellus consectetuer vestibulum elit. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc. Vestibulum fringilla pede sit amet augue. In turpis. Pellentesque posuere. Praesent turpis. Aenean posuere, tortor sed cursus feugiat, nunc augue blandit nunc, eu sollicitudin urna dolor sagittis lacus. Donec elit libero, sodales nec, volutpat a, suscipit non, turpis. Nullam sagittis. Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce id purus. Ut varius tincidunt libero. Phasellus dolor. Maecenas vestibulum mollis diam. Pellentesque ut neque. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In dui magna, posuere eget, vestibulum et, tempor auctor, justo. In ac felis quis tortor malesuada pretium. Pellentesque auctor neque nec urna. Proin sapien ipsum, porta a, auctor quis, euismod ut, mi. Aenean viverra rhoncus pede. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut non enim eleifend felis pretium feugiat. Vivamus quis mi. Phasellus a est. Phasellus magna. In hac habitasse platea dictumst. Curabitur at lacus ac velit ornare lobortis. Curabitur a felis in nunc fringilla tristique. Morbi mattis ullamcorper velit. Phasellus gravida semper nisi. Nullam vel sem. Pellentesque libero tortor, tincidunt et, tincidunt eget, semper nec, quam. Sed hendrerit. Morbi ac felis. Nunc egestas, augue at pellentesque laoreet, felis eros vehicula leo, at malesuada velit leo quis pede. Donec interdum, metus et hendrerit aliquet, dolor diam sagittis ligula, eget egestas libero turpis vel mi. Nunc nulla. Fusce risus nisl, viverra et, tempor et, pretium in, sapien. Donec venenatis vulputate lorem. Morbi nec metus. Phasellus blandit leo ut odio. Maecenas ullamcorper, dui et placerat feugiat, eros pede varius nisi, condimentum viverra felis nunc et lorem. Sed magna purus, fermentum eu, tincidunt eu, varius ut, felis. In auctor lobortis lacus. Quisque libero metus, condimentum nec, tempor a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligula. Fusce fermentum. Nullam cursus lacinia erat. Praesent blandit laoreet nibh. Fusce convallis metus id felis luctus adipiscing. Pellentesque egestas, neque sit amet convallis pulvinar, justo nulla eleifend augue, ac auctor orci leo non est. Quisque id mi. Ut tincidunt tincidunt erat. Etiam feugiat lorem non metus. Vestibulum dapibus nunc ac augue. Curabitur vestibulum aliquam leo. Praesent egestas neque eu enim. In hac habitasse platea dictumst. Fusce a quam. Etiam ut purus mattis mauris sodales aliquam. Curabitur nisi. Quisque malesuada placerat nisl. Nam ipsum risus, rutrum vitae, vestibulum eu, molestie vel, lacus. Sed augue ipsum, egestas nec, vestibulum et, malesuada adipiscing, dui. Vestibulum facilisis, purus nec pulvinar iaculis, ligula mi congue nunc, vitae euismod ligula urna in dolor. Mauris sollicitudin fermentum libero. Praesent nonummy mi in odio. Nunc interdum lacus sit amet orci. Vestibulum rutrum, mi nec elementum vehicula, eros quam gravida nisl, id fringilla neque ante vel mi. Morbi mollis tellus ac sapien. Phasellus volutpat, metus eget egestas mollis, lacus lacus blandit dui, id egestas quam mauris ut lacus. Fusce vel dui. Sed in libero ut nibh placerat accumsan. Proin faucibus arcu quis ante. In consectetuer turpis ut velit. Nulla sit amet est. Praesent metus tellus, elementum eu, semper a, adipiscing nec, purus. Cras risus ipsum, faucibus ut, ullamcorper id, varius ac, leo. Suspendisse feugiat. Suspendisse enim turpis, dictum sed, iaculis a, condimentum nec, nisi. Praesent nec nisl a purus blandit viverra. Praesent ac massa at ligula laoreet iaculis. Nulla neque dolor, sagittis eget, iaculis quis, molestie non, velit. Mauris turpis nunc, blandit et, volutpat molestie, porta ut, ligula. Fusce pharetra convallis urna. Quisque ut nisi. Donec mi odio, faucibus at, scelerisque quis,"
"\n"
"\t"
"")

for i in "${strings[@]}"
do
  ./a.out "STRING" "$i"              > ./Text/CHECK
  status=$?
 if ((status > 0))
     then
     printf "$RED[KO]$RESET\n"
     echo -e "[CRASH]FATAL ERROR in STRING\nCase: '"$i"'\n------------\n"
     echo -e "[CRASH]FATAL ERROR in STRING\nCase: '"$i"'\n------------\n" >> ./Text/CRASHLOG.txt
     echo -e $RED"Skipping the rest of the Category\n"$RESET
     ((errorcount++))
     break
 else
   len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
   printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
  cat ./Text/CHECK         >> ./Text/STRING.txt
 fi
done

printf "\n\n"
printheader POINTER Test
testlen=0

Pointer=("STATICPOINTER"
"NULLPOINTER"
"CHARPOINTER"
"INTPOINTER"
"HEAPPOINTER")

for i in "${!Pointer[@]}"
do 
 ./a.out "POINTER" "$i"                 > ./Text/CHECK
status=$?
 if ((status > 0))
    then
    printf "$RED[KO]$RESET\n"
    echo -e "[CRASH]FATAL ERROR in Pointer\n Case: ${Pointer[$i]} \n------------\n"
    echo -e "[CRASH]FATAL ERROR in Pointer\n Case: ${Pointer[$i]} \n------------\n" >> ./Text/CRASHLOG.txt
    echo -e $RED"Skipping the rest of the Category\n"$RESET
    ((errorcount++))
    break
 else
    len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
   printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
 cat ./Text/CHECK       >> ./Text/POINTER.txt
fi
done

Num=("INT"
"UNSIGNEDINT"
"DECIMAL"
"HEX"
"HEXLOW")

for i in "${Num[@]}"
do

printf "\n\n"
printheader "$i" Test
testlen=0

for rand in {1..50}
do 
 x=$RANDOM
 y=$((x*rand))
 ./a.out "$i" "$y" > ./Text/CHECK
 status=$?
 if ((status > 0))
    then
    printf "$RED[KO]$RESET\n"
    echo -e "[CRASH]FATAL ERROR in "$i"\nCase: '"$y"'\n--------------\n"
    echo -e "[CRASH]FATAL ERROR in "$i"\nCase: '"$y"'\n--------------\n" >> ./Text/CRASHLOG.txt
    echo -e $RED"Skipping the rest of the Category\n"$RESET
    ((errorcount++))
    break
 else
   len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
      printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
    cat ./Text/CHECK     >> ./Text/"$i".txt
 fi
 done

for lim in -1 0 1 42 420 2147483647 -2147483648 4294967295
 do
 ./a.out "$i" $lim              >  ./Text/CHECK
  status=$?
if ((status > 0))
    then
    printf "$RED[KO]$RESET\n"
    echo -e "[CRASH]FATAL ERROR in "$i"\nCase: '"$lim"'\n--------------\n"
    echo -e "[CRASH]FATAL ERROR in "$i"\nCase: '"$lim"'\n--------------\n" >> ./Text/CRASHLOG.txt
    echo -e $RED"Skipping the rest of the Category\n"$RESET
    ((errorcount++))
    break
 else
   len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
      printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
    cat ./Text/CHECK     >> ./Text/"$i".txt
fi
 done
done

printf "\n\n"
printheader PERCENT Test
testlen=0

Percent=("%%"
"%%%%"
"%%%%%%"
"%%d%%"
"%%c%%"
"%%i%%"
"%%p%%"
"%%u%%"
"%%x%%"
"%%X%%"
"%%%%%%%%%%%%%%%%")

 for i in "${Percent[@]}"
 do
 ./percent "$i"               >  ./Text/CHECK
  status=$?
 if ((status > 0))
    then
    printf "$RED[KO]$RESET\n"
    echo -e "[CRASH]FATAL ERROR in Percent\nCase: '"$i"'\n------------\n"
    echo -e "[CRASH]FATAL ERROR in Percent\nCase: '"$i"'\n------------\n" >> ./Text/CRASHLOG.txt
    echo -e $RED"Skipping the rest of the Category\n"$RESET
    ((errorcount++))
    break
 else
   len=$((testlen % 25))
   if [[ "$len" = "0" ]]
   then
      printf "\n"
      printf "$GREEN[OK] $RESET"
   else
      printf "$GREEN[OK] $RESET"
   fi
   ((testlen++))
  cat ./Text/CHECK     >> ./Text/PERCENT.txt
 fi
done

printf "\n\n"

printheader END

if [[ "$errorcount" == "0" ]]
then
   echo -e ""$GREEN"\nALL TESTS COMPILED AND EXECUTED WITH NO ISSUE$RESET\n"
else
   echo -e ""$BRED"\nTotal amount of Crashes: "$errorcount"$RESET\n"
   echo -e ""$BRED"\nTotal amount of Crashes: "$errorcount"$RESET\n" >> ./Text/CRASHLOG.txt
fi
rm ./Text/CHECK
