
echo "enter file name"
read f
echo 'enter starting position'
read st
echo 'enter ending position'
read end
echo 'The lines between' $st 'and' $end 'from' $f
if [ $st -lt $end ]
then
n1=`expr $st + 1`
n2=`expr $end - 1`
sed -n "$n1,$n2 p" $f
elif [ $st -gt $end ]
then
n3=`expr $st - 1`
n4=`expr $end + 1`
sed -n "$n4,$n3 p" $f
fi
