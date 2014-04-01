CFLAGS="-Wall"

for d in chapter_*
do
  pushd $d
  pwd
  for f in *.cpp
    do
      b=`basename $f .cpp`
      echo ./$b
      ./$b
    done
  popd
done
