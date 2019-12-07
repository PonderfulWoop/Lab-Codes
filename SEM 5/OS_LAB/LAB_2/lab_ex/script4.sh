count_files=$(ls -l| grep "^-" | wc -l)

echo The file count: $count_files