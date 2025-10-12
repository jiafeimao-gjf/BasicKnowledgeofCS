DIR = $1
AC_MD = $2

echo "Init one AC path=$DIR/$AC_MD"
mkdir -p $DIR

cp demo_one/demo_one.md "$DIR/$AC_MD.md"
cp demo_one/demo_one.py $DIR/$AC_MD.py

