touch _ex3.txt	

ls -l _ex3.txt >> ex3.txt

chmod a-x _ex3.txt
echo -e "\n" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

chmod u+rwx,o+rwx _ex3.txt	
echo -e "\n" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

chmod g=u _ex3.txt		
echo -e "\n" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

echo -e "\n\n" >> ex3.txt
cat ex3_Questions.txt >> ex3.txt
