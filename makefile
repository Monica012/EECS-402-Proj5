proj5.exe: project5.o EventClass.o RestaurantClass.o readVal.o random.o 
	g++ -g project5.o EventClass.o RestaurantClass.o readVal.o random.o -o proj5.exe 
project5.o: project5.cpp constants.h RestaurantClass.cpp RestaurantClass.h SortedListClass.h SortedListClass.inl FIFOQueueClass.h FIFOQueueClass.inl EventClass.h EventClass.cpp readVal.h readVal.cpp
	g++ -g -c project5.cpp -o project5.o
EventClass.o: EventClass.cpp EventClass.h
	g++ -g -c EventClass.cpp -o EventClass.o
RestaurantClass.o: RestaurantClass.cpp RestaurantClass.h SortedListClass.h SortedListClass.inl constants.h FIFOQueueClass.h FIFOQueueClass.inl readVal.h readVal.cpp
	g++ -g -c RestaurantClass.cpp -o RestaurantClass.o
readVal.o: readVal.cpp readVal.h constants.h
	g++ -g -c readVal.cpp -o readVal.o
random.o: random.cpp random.h
	g++ -g -c random.cpp -o random.o
clean:
	rm -f project5.o EventClass.o RestaurantClass.o readVal.o random.o  proj5.exe
