msdscript: main.cpp cmdline.cpp
	g++ -o msdscript main.cpp cmdline.cpp -I
clean:
	$(RM) msdscript
