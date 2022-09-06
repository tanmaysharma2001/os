mkdir root
cd root
touch root.txt

date
sleep 3

cd ..
mkdir home
cd home
touch home.txt

cd ..
cd root
ls -r -lt / > root.txt

cd ..
cd home
ls -r -lt ~ > home.txt

cat home.txt

cd ..
cd root
cat root.txt
