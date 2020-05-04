echo "Enter the file name"
read file
if [ -f $file ] 
then echo "it is a file"
elif [ -d $file ]
then echo "It is a directory"
else echo "It is something else"
fi
