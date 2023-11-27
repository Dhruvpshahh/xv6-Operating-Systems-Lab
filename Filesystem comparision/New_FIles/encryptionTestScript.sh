
truncate -s 256M ~/zfs_encrypt.img
truncate -s 256M ~/zfs_noencrypt.img


sudo zpool create zfs_noencrypt ~/zfs_noencrypt.img
sudo zpool create zfs_encrypt ~/zfs_encrypt.img
echo "12345678" | sudo zfs create -o encryption=on -o keyformat=passphrase zfs_encrypt/encrypted

sudo ./vdbench -f encryption_test.conf -o encryptionTestOutput+ 
