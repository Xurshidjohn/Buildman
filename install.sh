
if [[ "$OSTYPE" == "linux-gnu" ]]; then
	gcc src/index.c -o lake
	sudo mv lake /usr/local/bin
fi

if [[ "$OSTYPE" == "msys" ]]; then
	gcc src/index.c -o lake
	setx PATH "C:/Users/$USERNAME/Downloads/lake"
fi
