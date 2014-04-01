CFLAGS="-Wall"

for d in chapter_*
do
  pushd $d
  pwd
  for f in *.cpp
    do
      b=`basename $f .cpp`
      echo g++ $CFLAGS $f -o $b
      g++ $CFLAGS $f -o $b
    done
  popd
done
