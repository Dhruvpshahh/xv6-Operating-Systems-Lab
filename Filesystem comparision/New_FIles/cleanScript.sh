declare -a arr=("zfs_compress" "zfs_nocompress" "zfs_encrypt" "zfs_noencrypt")

for i in "${arr[@]}"
do
   sudo zfs unmount "$i"
   sudo zpool destroy "$i"
done
rm ~/zfs_*.img
