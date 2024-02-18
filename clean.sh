echo "Deletes binary files without .git directory."
find . -type f -name "*" ! -name "*.*" ! -name ".*" ! -path "./.git/*" -exec rm -f {} \;
