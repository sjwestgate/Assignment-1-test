a.out:
	g++ assignment-1 assignment-1.cpp 

clean:
	rm assignment-1

test: assignment-1.out
	bash test.sh
