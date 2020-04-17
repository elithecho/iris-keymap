KEEB_DIR=~/qmk_firmware/keyboards/keebio/iris/keymaps/choonggg

build:
	qmk compile -kb keebio/iris/rev2 -km choonggg
	mv ~/qmk_firmware/keebio_iris_rev2_choonggg.hex ./

flash:
	qmk flash --keyboard keebio/iris/rev2 -km choonggg
