echo enter the string
read s
echo enter the character to search
read ch
length=${#s}
for (( i=0; i<length; i++))
do
if [ ${s:$i:1} == $ch ]
then
count=$((count + 1))
fi
done
echo $ch is $count times in $s
