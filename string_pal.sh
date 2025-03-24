echo enter a string
read s
rev=''
len=${#s}
for ((i=len-1; i>=0; i--))
do
rev="$rev${s:$i:1}"
done
echo "reversed string:$rev"
if [ "$rev" == "$s" ]
then
echo $s is palindrome
else
echo $s not palindrome
fi
