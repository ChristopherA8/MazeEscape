all:
	@clang++ -std=c++17 -Isrc src/*.cpp src/core/*.cpp src/core/utils/*.cpp src/ai/*.cpp src/entities/*.cpp src/scenes/*.cpp src/world/*.cpp -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,./SFML/lib -o dist/main
	@clear
	@./dist/main

clean:
	@rm dist/main
