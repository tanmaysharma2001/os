mkdir tmp
cd tmp
touch file1
touch file2
link file1 link1
cd ..
gcc ex4.c -o ex4
./ex4 > ex4.txt

# removing all files
rm ex4
cd tmp
rm file1
rm file2
rm link1
cd ..
rmdir tmp
