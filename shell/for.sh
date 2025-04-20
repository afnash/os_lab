sum=0
echo enter the limit:
read n
for ((i=1 ; i<= $n ;i++))
do 
sum=$(($sum + $i))
done
echo "$sum"
