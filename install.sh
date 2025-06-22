if [[ "$OSTYPE" == "linux-gnu"]]; then
	gcc src/index.c -o lake
	mv lake /usr/local/bin