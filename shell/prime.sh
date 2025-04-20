echo enter the number:
read n
count=0
for ((i=1; i<=n; i++))
do
if [ $((n % i)) -eq 0 ]
then
count=$((count + 1))
fi
done
if [ $count -gt 2 ]
then
echo "$n is composite"
else
echo "$n is prime"
fi
