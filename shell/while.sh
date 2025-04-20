echo enter the limit
read n
i=1
echo "first $n natural numbers are: "
while [ $i -le $n ]
do
echo "$i"
i=$(($i+1))
done
