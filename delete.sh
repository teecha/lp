echo 'enter a word to be deleted'
read word
echo 'enter file name'
read fname
echo 'lines in' $fname 'after deleting the word' $word ':'
sed "/$word/d" $fname
