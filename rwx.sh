
for i in *
do
if [ -r $i -a -w $i -a -x $i ]
then
echo $i
fi
done
