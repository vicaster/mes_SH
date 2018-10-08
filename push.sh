find . -name 'a.out' -print -delete | find . -name '.DS_Store' -print -delete | echo "\nKill The Cash\n\n"
git add .
git commit -m "vic"
git push
echo "\n\n------------------------------\n\n"
git ls-files
