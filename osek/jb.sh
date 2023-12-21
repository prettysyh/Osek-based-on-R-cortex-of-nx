cp spe.bin ~/nvidia/Linux_for_Tegra/bootloader/spe_t194.bin
cd ~/nvidia/Linux_for_Tegra
sudo ./flash.sh -k spe-fw jetson-xavier-nx-devkit-emmc mmcblk0p1
cd ../../osek_m