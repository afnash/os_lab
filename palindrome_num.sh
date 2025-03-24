echo enter a number:
read n
rev=0
og=$n
while [ $n -ne 0 ]
do
rem=$(( n % 10 ))
rev=$(( rev * 10 + rem ))
n=$(( n / 10 ))
done
if [ $og -eq $rev ]
then
echo "$og is palindrome"
else
echo "$og is not palindrome"
fi

