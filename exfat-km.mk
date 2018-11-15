EXFAT_FOLDER ?= external/exfat-nofuse

EXFAT_MODULE:
	make clean -C $(EXFAT_FOLDER) KDIR=$(KERNEL_OUT)
	make -j8 -C $(EXFAT_FOLDER) ARCH=arm KDIR=$(KERNEL_OUT) \
		$(if $(ARM_CROSS_COMPILE),$(ARM_CROSS_COMPILE),$(KERNEL_CROSS_COMPILE))

	mv $(EXFAT_FOLDER)/exfat_core.ko $(KERNEL_MODULES_OUT)
	$(if $(ARM_EABI_TOOLCHAIN),$(ARM_EABI_TOOLCHAIN)/arm-eabi-strip, \
		$(KERNEL_TOOLCHAIN_PATH)strip) --strip-unneeded $(KERNEL_MODULES_OUT)/exfat_core.ko

	mv $(EXFAT_FOLDER)/exfat_fs.ko $(KERNEL_MODULES_OUT)
	$(if $(ARM_EABI_TOOLCHAIN),$(ARM_EABI_TOOLCHAIN)/arm-eabi-strip, \
		$(KERNEL_TOOLCHAIN_PATH)strip) --strip-unneeded $(KERNEL_MODULES_OUT)/exfat_fs.ko

TARGET_KERNEL_MODULES += EXFAT_MODULE
