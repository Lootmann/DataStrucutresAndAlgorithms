run:
	cd build && cmake -GNinja .. && ninja

out:
	./build/a.out

.PHONY: test
test:
	cd build && cmake -GNinja .. && ninja && cd .. && ./build/test/test_out --gtest_color=yes

.PHONY: clean
clean:
	rm -r build/*

.PHONY: check-leak
check-leak:
	valgrind --tool=memcheck --leak-check=yes --leak-resolution=high ./build/test/test_out
