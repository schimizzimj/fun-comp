
CMP = g++ -std=c++14 -Wno-narrowing 
GFX = -lX11 gfxnew.o
CLASS = board
MAIN = final
EXEC = froggy

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(GFX) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm $(CLASS).o $(MAIN).o
	rm $(EXEC)

