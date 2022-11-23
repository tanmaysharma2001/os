sudo mkdir -p lofsdisk/{bin,usr/{lib/x86_64-linux-gnu,lib64}}
sudo cp /bin/{bash,echo,ls,cat} lofsdisk/bin/
sudo cp /lib/x86_64-linux-gnu/{libtinfo.so.6,libc.so.6,libselinux.so.1,libpcre2-8.so.0} lofsdisk/usr/lib/x86_64-linux-gnu/
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/usr/lib64/
cd lofsdisk
sudo ln -s usr/lib lib
sudo ln -s usr/lib64 lib64
cd ..
gcc ex2.c -o ex2.out

sudo bash -c "echo 'Tanmay' > lofsdisk/file1"
sudo bash -c "echo 'Sharma' > lofsdisk/file2"

./ex2.out > ex2.txt
echo >> ex2.txt
sudo cp ex2.out lofsdisk/ex2.out
sudo chroot lofsdisk ./ex2.out >> ex2.txt
