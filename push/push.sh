find . -name 'a.out' -print -delete | find . -name '.DS_Store' -print -delete | echo "\nKill The Cash\n\n"
git add . && git commit -m "`date | cut -d ' ' -f1,2,3,4,5`" && git push
echo "\n\n------------------------------\n\n"
git ls-files
